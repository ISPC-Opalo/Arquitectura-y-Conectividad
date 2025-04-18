#include "wifi.h"
#include <WiFi.h>

static const char* _ssid     = nullptr;
static const char* _password = nullptr;

void wifiSetup(const char* ssid, const char* password) {
  _ssid     = ssid;
  _password = password;
  WiFi.begin(_ssid, _password);
}

void wifiLoop() {
  if (WiFi.status() != WL_CONNECTED) {
    static unsigned long lastAttempt = 0;
    if (millis() - lastAttempt > 5000) {
      lastAttempt = millis();
      WiFi.begin(_ssid, _password);
    }
  }
}

bool wifiIsConnected() {
  return WiFi.status() == WL_CONNECTED;
}
