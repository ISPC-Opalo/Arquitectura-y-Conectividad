#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#define PIN_SCK   18
#define PIN_MISO  19
#define PIN_MOSI  23
#define PIN_SS    5
#define PIN_DIO0  4

void setup() {
  Serial.begin(115200);
  while (!Serial);

  SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_SS);
  LoRa.setPins(PIN_SS, -1, PIN_DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Error iniciando LoRa");
    while (1);
  }
  Serial.println("LoRa Receptor listo");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String msg;
    while (LoRa.available()) msg += (char)LoRa.read();
    Serial.print("Recibido: ");
    Serial.println(msg);
    // responder un “ACK” —
    LoRa.beginPacket();
    LoRa.print("ACK");
    LoRa.endPacket();
  }
}
