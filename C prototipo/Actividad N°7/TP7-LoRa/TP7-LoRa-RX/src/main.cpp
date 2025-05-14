#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

//=======================================
// PINES 
//=======================================
#define PIN_SCK   18   // SCLK
#define PIN_MISO  19   // SPI MISO
#define PIN_MOSI  23   // SPI MOSI 
#define PIN_SS    5    // NSEL
#define PIN_DIO0  4    // NIRQ
// Reset [SDN] queda punteado con GND

//=======================================
// PIN RELÉ
//=======================================
#define RELAY_PIN 16   // Conecta la entrada del módulo de relé aquí

//=======================================
// UMBRALES
//=======================================
const float TEMP_THRESHOLD = 30.0;  
const float HUM_THRESHOLD  = 60.0;  

//=======================================
// SETUP
//=======================================
void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Inicializa LoRa
  SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_SS);
  LoRa.setPins(PIN_SS, -1, PIN_DIO0);
  if (!LoRa.begin(915E6)) {
    Serial.println("Error iniciando LoRa");
    while (1);
  }
  Serial.println("LoRa Receptor listo");

  // Inicializa relé
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  // Verifica si llegó un paquete
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // Lee todo el mensaje
    String msg;
    while (LoRa.available()) {
      msg += (char)LoRa.read();
    }
    Serial.print("Recibido: ");
    Serial.println(msg);

    // Extrae valores de Temp y Hum
    float tempVal = NAN, humVal = NAN;

    int iT = msg.indexOf("Temp: ");
    if (iT >= 0) {
      int iDeg = msg.indexOf("°", iT);
      if (iDeg > iT) {
        String s = msg.substring(iT + 6, iDeg);
        tempVal = s.toFloat();
      }
    }

    int iH = msg.indexOf("Hum: ");
    if (iH >= 0) {
      int iPct = msg.indexOf("%", iH);
      if (iPct > iH) {
        String s = msg.substring(iH + 5, iPct);
        humVal = s.toFloat();
      }
    }

    // Comprueba y acciona relé
    if (!isnan(tempVal) && !isnan(humVal)) {
      Serial.printf("Temp=%.1f°C, Hum=%.1f%%\n", tempVal, humVal);
      if (tempVal > TEMP_THRESHOLD || humVal > HUM_THRESHOLD) {
        Serial.println("¡Umbral superado! Activando relé.");
        digitalWrite(RELAY_PIN, HIGH);
      } else {
        Serial.println("Valores normales. Desactivando relé.");
        digitalWrite(RELAY_PIN, LOW);
      }
    } else {
      Serial.println("Error parseando datos recibidos.");
    }
  }
}
