#include <SPI.h>
#include <WiFi101.h>
#include "WiFiSSLClient.h"

#include <PubSubClient.h>

// WiFi settings
char ssid[]     = "ssid";
char password[] = "password";

// MQTT settings
char server[]   = "server";
int  port       = 8883;
char name[]     = "arduinoWiFiSSLClient";
char username[] = "username";
char token[]    = "token";
char topic[]    = "/username/topic";

WiFiSSLClient wifiSSLClient;
PubSubClient client(server, port, callback, wifiSSLClient);

void setup()
{
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println(F("WiFi shield not present"));
    // don't continue:
    while(true);
  }

  Serial.print("Firmware version is ");
  Serial.println(WiFi.firmwareVersion());

  // attempt to connect to Wifi network:
  while(true) {
    Serial.print(F("Attempting to connect to SSID: "));
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    if (WiFi.begin(ssid, password) == WL_CONNECTED) {
      break;
    } else {
      // wait 1 seconds for connection:
      delay(1000);
    }
  }
  Serial.println(F("Connected to wifi"));

  Serial.print(F("SSID: "));
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print(F("IP Address: "));
  Serial.println(ip);

  Serial.print(F("signal strength (RSSI):"));
  Serial.print(WiFi.RSSI());
  Serial.println(F(" dBm"));

  Serial.println(F("Connecting to MQTT broker ..."));
  if (client.connect(name, username, token)) {
    Serial.println(F("Connected :D"));
    client.subscribe(topic);
    client.publish(topic, "hello world");
  } else {
    Serial.println(F("Connection failed :("));
  }
}

void loop()
{
  client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print(F("Topic: "));
  Serial.println(topic);
  
  Serial.print(F("Payload: "));
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

