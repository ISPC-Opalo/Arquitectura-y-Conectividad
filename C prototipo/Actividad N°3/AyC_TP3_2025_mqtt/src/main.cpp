#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT
WiFiClient espClient;
PubSubClient client(espClient);
const char* mqtt_server = "mqtt.eclipseprojects.io";
const int mqtt_port = 1883;
const char* mqtt_client_id = "esp32_control_full";
const char* mqtt_topic_temp = "/casa/sala/temperatura";
const char* mqtt_topic_control = "/casa/sala/control";

// Pines
const int tempSensorPin = 34;
const int dimmerPin     = 33;
const int ledPin        = 15;
const int buttonPin     = 4;

// Variables
float simulatedTemperatureC = 0.0;
bool lightOn = false;
int dimmerOverride = -1;

int lastButtonReading = HIGH;
bool lastDebouncedState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

unsigned long lastPrintTime = 0;
const unsigned long printInterval = 1000;

// MQTT Callback
void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  message.trim();

  if (String(topic) == mqtt_topic_control) {
    if (message == "ON") {
      lightOn = true;
      dimmerOverride = -1; // usar potenciómetro
    } else if (message == "OFF") {
      lightOn = false;
    } else if (message.startsWith("BRIGHTNESS:")) {
      int value = message.substring(11).toInt();
      if (value >= 0 && value <= 255) {
        dimmerOverride = value;
        lightOn = true;
      }
    }
  }
}

// Conectar a WiFi
void connectWiFi() {
  Serial.print("Conectando a WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" ¡Conectado!");
}

// Conectar a MQTT
void connectMQTT() {
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.print("Conectando a MQTT...");
    if (client.connect(mqtt_client_id)) {
      Serial.println(" ¡Conectado!");
      client.subscribe(mqtt_topic_control);
    } else {
      Serial.print(" fallo, rc=");
      Serial.print(client.state());
      Serial.println(" reintentando en 2 segundos");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(dimmerPin, INPUT);
  ledcSetup(0, 1000, 8); // canal, frecuencia, resolución
  ledcAttachPin(ledPin, 0);

  connectWiFi();
  connectMQTT();
}

void loop() {
  if (!client.connected()) connectMQTT();
  client.loop();

  // Leer temperatura simulada
  int tempRawValue = analogRead(tempSensorPin);
  simulatedTemperatureC = map(tempRawValue, 0, 4095, 10, 40);

  // Publicar temperatura
  client.publish(mqtt_topic_temp, String(simulatedTemperatureC, 2).c_str());

  // Leer botón con debounce
  int currentReading = digitalRead(buttonPin);
  if (currentReading != lastButtonReading) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (currentReading == LOW && lastDebouncedState == HIGH) {
      lightOn = !lightOn;
      dimmerOverride = -1;
    }
    lastDebouncedState = currentReading;
  }
  lastButtonReading = currentReading;

  // Control LED
  if (lightOn) {
    int pwmValue;
    if (dimmerOverride >= 0) {
      pwmValue = dimmerOverride;
    } else {
      int rawDimmer = analogRead(dimmerPin);
      pwmValue = map(rawDimmer, 0, 4095, 0, 255);
    }
    ledcWrite(0, pwmValue);
  } else {
    ledcWrite(0, 0);
  }

  // Mostrar estado
  if (millis() - lastPrintTime > printInterval) {
    lastPrintTime = millis();
    Serial.print("Temp: ");
    Serial.print(simulatedTemperatureC);
    Serial.print("°C | LED: ");
    Serial.print(lightOn ? "ON" : "OFF");
    Serial.print(" | Dimmer: ");
    if (dimmerOverride >= 0)
      Serial.println(dimmerOverride);
    else
      Serial.println(analogRead(dimmerPin));
  }

  delay(50);
}
