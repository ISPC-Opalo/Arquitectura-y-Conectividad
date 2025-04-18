#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>

/// Inicializa la conexión WiFi con SSID y password
void wifiSetup(const char* ssid, const char* password);

/// Llamar en loop, reintenta la conexión cada 5 s si no está conectado
void wifiLoop();

/// Booleano que nos confirma si esta o no cnoectado
bool wifiIsConnected();

#endif
