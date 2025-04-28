#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Broker MQTT
const char* mqtt_server = "test.mosquitto.org"; //mosquitto parece estar andando mal. Si no funciona usar este: broker.hivemq.com

// WiFi
WiFiClient espClient;
PubSubClient client(espClient);

// Pin analógico simulado (potenciómetro en Wokwi)
const int PIN_SENSOR = 34;

// Variables globales
float overrideTemp = -1;             // Valor override si se recibe comando "reset"
unsigned long lastSend = 0;          // Control de tiempo para envíos periódicos

// Conexión a red WiFi simulada de Wokwi
void setup_wifi() {
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" WiFi conectado!");
}

// Función de callback cuando se recibe un mensaje MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en el canal ");
  Serial.print(topic);
  Serial.print(": ");

  String msg = "";
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  Serial.println(msg);

  if (msg == "reset") {
    Serial.println("⚠️ Instrucción de reset de temperatura recibida.");
    overrideTemp = 0;
  }
}

// Reconexion automática al broker si se pierde conexión
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

// Inicialización: consola, WiFi, MQTT y suscripción
void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

// Loop principal: verifica conexión y publica cada 5 segundos
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (millis() - lastSend > 5000) {
    float tempC;

    // Si hay override, usarlo solo una vez
    if (overrideTemp >= 0) {
      tempC = overrideTemp;
      overrideTemp = -1;  // Limpiar después de usar
    } else {
      int raw = analogRead(PIN_SENSOR);         // Valor 0–4095
      tempC = (raw / 4095.0) * 100.0;            // Escalamos a 0–100 °C
    }

    char msg[15];  // Espacio suficiente para valores como "100.00"
    dtostrf(tempC, 5, 2, msg);  // 5 dígitos, 2 decimales

    Serial.print("Temperatura en dispositivo en C°: ");
    Serial.println(msg);

    client.publish("tempESP", msg);  // QoS 0 por defecto
    lastSend = millis();
  }
}
