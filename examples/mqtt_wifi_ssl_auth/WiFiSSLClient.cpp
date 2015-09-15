#include "WiFiSSLClient.h"

WiFiSSLClient::WiFiSSLClient() : 
  WiFiClient()
{
}

WiFiSSLClient::WiFiSSLClient(uint8_t sock, uint8_t parentsock) :
  WiFiClient(sock, parentsock)
{  
}
WiFiSSLClient::WiFiSSLClient(const WiFiSSLClient& other) :
  WiFiClient(other)
{
}

int WiFiSSLClient::connect(IPAddress ip, uint16_t port)
{
  WiFiClient::connectSSL(ip, port);
}

int WiFiSSLClient::connect(const char* host, uint16_t port)
{
  WiFiClient::connectSSL(host, port);
}
