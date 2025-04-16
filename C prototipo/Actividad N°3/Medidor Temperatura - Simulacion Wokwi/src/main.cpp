#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Broker MQTT
const char* mqtt_server = "test.mosquitto.org";

// Wifi
WiFiClient espClient;
PubSubClient client(espClient);

// Pines
const int PIN_SENSOR = 34; 

// WiFi
void setup_wifi() {
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" WiFi conectado!");
}

// Función de callback para recibir mensajes
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en el canal ");
  Serial.print(topic);
  Serial.print(": ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

// Reconexión al broker
void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando al broker MQTT...");
    String clientId = "ESP32SensorTemp-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println(" conectado!");
      client.subscribe("tempESP");  // Suscripción al canal
    } else {
      Serial.print(" falló, rc=");
      Serial.print(client.state());
      Serial.println(" reintentando en 5 segundos.");
      delay(5000);
    }
  }
}

unsigned long lastSend = 0;

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Enviar cada 5 segundos
  if (millis() - lastSend > 5000) {
    int raw = analogRead(PIN_SENSOR); // Valor analógico 0-4095
    float tempC = (raw / 4095.0) * 100.0; // Escalamos a 0-100°C

    char msg[10];
    dtostrf(tempC, 4, 2, msg);  // Convertir a string

    Serial.print("Temperatura en dispositivo en C°: ");
    Serial.println(msg);

    client.publish("tempESP", msg); // QoS 0 por defecto

    lastSend = millis();
  }
}
