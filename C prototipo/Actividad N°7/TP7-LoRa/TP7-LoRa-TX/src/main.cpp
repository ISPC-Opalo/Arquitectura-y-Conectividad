#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#define PIN_SCK   18  // SPI SCK
#define PIN_MISO  19  // SPI MISO
#define PIN_MOSI  23  // SPI MOSI
#define PIN_SS    5   // SPI CS (NSEL)
#define PIN_DIO0  4  // IRQ (NIRQ)

uint8_t readVersion() {
  const uint8_t REG_VERSION = 0x42;
  digitalWrite(PIN_SS, LOW);
  SPI.transfer(REG_VERSION & 0x7F); // MSB=0 para lectura
  uint8_t v = SPI.transfer(0x00);
  digitalWrite(PIN_SS, HIGH);
  return v;
}

void setup() {
  Serial.begin(9600);
  SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_SS);
  pinMode(PIN_SS, OUTPUT);
  LoRa.setPins(PIN_SS, -1, PIN_DIO0);
  Serial.print("Versión radio: 0x");
  Serial.println(readVersion(), HEX);
  if (!LoRa.begin(433E6)) {
    Serial.println("Error iniciando LoRa");
    while (1);
  }
  Serial.println("LoRa Transmisor listo");
}

void loop() {
  Serial.println("Enviando 'Hola'");
  LoRa.beginPacket();
  LoRa.print("Hola");
  LoRa.endPacket();
  delay(1000);
}
