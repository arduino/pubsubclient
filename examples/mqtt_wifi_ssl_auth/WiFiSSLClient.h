/*
  WiFiSSLClient.h

  Overrides connect methods to use connectSSL,
  for compatiblity with existing Client based libraries. 
*/

#ifndef WIFISSLCLIENT_H
#define WIFISSLCLIENT_H

#include <WiFiClient.h>

class WiFiSSLClient : public WiFiClient {

public:
  WiFiSSLClient();
  WiFiSSLClient(uint8_t sock, uint8_t parentsock = 0);
  WiFiSSLClient(const WiFiSSLClient& other);

  virtual int connect(IPAddress ip, uint16_t port);
  virtual int connect(const char* host, uint16_t port);
};

#endif /* WIFISSLCLIENT_H */
