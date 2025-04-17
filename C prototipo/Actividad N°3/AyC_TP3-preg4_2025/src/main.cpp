#include <Arduino.h>

// Pines
const int tempSensorPin = 26;
const int dimmerPin     = 33;
const int ledPin        = 15;
const int buttonPin     = 4;

// Variables
int  tempRawValue         = 0;
float simulatedTemperatureC = 0.0;
int  dimmerValue          = 0;
bool lightOn              = false;

int  lastButtonReading    = HIGH;
bool lastDebouncedState   = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

// Para el intervalo de impresión
unsigned long lastPrintTime = 0;
const unsigned long printInterval = 1000; // 1 segundo

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.println("Sistema listo: Botón, LED con dimmer, sensor simulado.");
}

void loop() {
  // 1) Leer temperatura simulada
  tempRawValue = analogRead(tempSensorPin);
  simulatedTemperatureC = map(tempRawValue, 0, 4095, 10, 40);

  // 2) Leer botón con debounce
  int currentReading = digitalRead(buttonPin);
  if (currentReading != lastButtonReading) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (currentReading == LOW && lastDebouncedState == HIGH) {
      lightOn = !lightOn;
    }
    lastDebouncedState = currentReading;
  }
  lastButtonReading = currentReading;

  // 3) Control del LED con dimmer
  if (lightOn) {
    dimmerValue = analogRead(dimmerPin);
    int pwmValue = map(dimmerValue, 0, 4095, 0, 255);
    analogWrite(ledPin, pwmValue);
  } else {
    analogWrite(ledPin, 0);
  }

  // 4) Imprimir solo cada printInterval ms
  if (millis() - lastPrintTime >= printInterval) {
    lastPrintTime = millis();
    Serial.print("Temp: ");
    Serial.print(simulatedTemperatureC);
    Serial.print("°C | LED: ");
    Serial.print(lightOn ? "ON" : "OFF");
    Serial.print(" | Dimmer: ");
    Serial.println(dimmerValue);
  }

  // Pequeño retardo para alivianar el loop
  delay(50);
}
