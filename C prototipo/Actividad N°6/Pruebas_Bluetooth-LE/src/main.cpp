#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLEAdvertising.h>

// Nombre del dispositivo BLE
#define DEVICE_NAME "ESP32-NodeMCU_BLE"

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando BLE...");

  // Iniciar el dispositivo BLE
  BLEDevice::init(DEVICE_NAME);

  // Crear el servidor BLE
  BLEServer *pServer = BLEDevice::createServer();

  // Crear el anunciado para hacer visible el dispositivo
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(BLEUUID((uint16_t)0x180F)); // UUID del servicio (cambiar si es necesario)
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x06);  // Tiempo mínimo de conexión
  pAdvertising->setMaxPreferred(0x12);  // Tiempo máximo de conexión

  // Iniciar el anunciado
  BLEDevice::startAdvertising();
  Serial.println("Dispositivo BLE anunciado y esperando conexión.");
}

void loop() {
  delay(2000);
}