// src/mqtt.cpp
#include "mqtt.h"
#include "wifi.h"
#include <WiFi.h>
#include <PubSubClient.h>

static WiFiClient   _wifiClient;
static PubSubClient _mqttClient(_wifiClient);
static MqttCallback _userCb         = nullptr;
static const char*  _mqttServer     = nullptr;
static uint16_t     _mqttPort       = 1883;
static bool         _configured     = false;

static void mqttReconnect() {
  if (!wifiIsConnected()) return; //Prueba si esta ya conectado a wifi. Si no lo esta, no tiene  sentido seguir conexion
  while (!_mqttClient.connected()) { // Bloque que trata de conectar al broker. 
    Serial.print("Intentando MQTT… ");
    String clientId = "ESP32Mod-"; // Crea un ID unico para el dispositivo con el nombre: ESP32Mod-n° aleatorio
    clientId += String(random(0xFFFF), HEX);

    if (_mqttClient.connect(clientId.c_str())) {
      Serial.println("¡conectado!");

    } else {
      Serial.print("falló, rc=");
      Serial.print(_mqttClient.state());
      Serial.println("reintento en 5s");
      delay(5000);
    }
  }
}

void mqttSetup(const char* server, uint16_t port) {
  _mqttServer = server;
  _mqttPort   = port;
  _mqttClient.setServer(_mqttServer, _mqttPort);
  _mqttClient.setCallback([](char* topic, byte* payload, unsigned int len){
    if (_userCb) _userCb(topic, payload, len);
  });
  _configured = true;
}

void mqttLoop() {
  if (!_configured) return;
  if (!_mqttClient.connected()) {
    mqttReconnect();
  }
  _mqttClient.loop();
}

void mqttSetCallback(MqttCallback cb) { // Esto es para que luego en main, se pueda llamar el callback con otras funciones.
  _userCb = cb;
}

void mqttPublish(const char* topic, const char* payload, uint8_n qos, bool retained) {
  if (_mqttClient.connected()) {
    _mqttClient.publish(topic, payload, qos, retained);
  }
}

void mqttSubscribe(const char* topic) {
  if (_mqttClient.connected()) {
    _mqttClient.subscribe(topic);
  }
}