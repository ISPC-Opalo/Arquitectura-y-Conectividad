#include <Arduino.h>
#include <DHT.h>
#include "BluetoothSerial.h"

#define DHTPIN 5        // Pin del sensor
#define DHTTYPE DHT11   // Tipo de sensor

DHT dht(DHTPIN, DHTTYPE);
BluetoothSerial BTSerial;

void setup() {
  Serial.begin(115200);
  BTSerial.begin("ESP32_DHT");  // Nombre del dispositivo Bluetooth
  dht.begin();
  delay(2000);  // Esperar estabilización
  Serial.println("Sistema iniciado. Enviando datos por Bluetooth...");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Error leyendo el sensor DHT");
    return;
  }

  // Mostrar por monitor serial
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Humedad: ");
  Serial.print(hum);
  Serial.println(" %");

  // Enviar formato compatible con Bluetooth Electronics:
// T<valor>
BTSerial.print("*T");
BTSerial.print(temp);
BTSerial.print("");

// H<valor>
BTSerial.print("*H");
BTSerial.print(hum);
BTSerial.print("");

delay(3000);
}
