#ifndef MQTT_H
#define MQTT_H

#include <Arduino.h>

/// Tipo de callback para mensajes entrantes
typedef void (*MqttCallback)(char* topic, byte* payload, unsigned int length);

/// Inicializa el cliente MQTT apuntando a `server:port`. En nuestro caso mosquitto, al puerto 1883
void mqttSetup(const char* server, uint16_t port);

/// Llamar en loop. Aca mantiene la conexion y si se corta, busca reconeccion
void mqttLoop();

/// Registra la función que maneja los mensajes entrantes
void mqttSetCallback(MqttCallback callback);

/// Publica `payload` en `topic`, con ql QoS que definamos, y sin retain
void mqttPublish(const char* topic, const char* payload, uint8_n qos=0,bool reteined = false );

/// Se suscribe a `topic` para recibir mensajes
void mqttSubscribe(const char* topic);

#endif