#include <WiFi.h>
#include <PubSubClient.h>

const char* mqtt_server = "test.mosquitto.org"; //mosquitto parece estar andando mal. Si no funciona usar este: broker.hivemq.com

const int LED1 = 27;
const int LED2 = 26;
const int LED3 = 25;

WiFiClient espClient;
PubSubClient client(espClient);

const char* ssid = "Vitto";
const char* password = "vittorio10";

// Funcion para suscribirse a un topic, interpretar el mensaje, y reaccionar segun la temperatura indicada.
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("]: ");

  String msg = "";
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  Serial.println(msg);
  float temp = msg.toFloat();

  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);

  if (temp > 65.0) {
    digitalWrite(LED3, HIGH);
    delay(3000);
    digitalWrite(LED3, LOW);

    // Envio de mensaje de alerta con calidad QoS 2
    String alerta = "ALERTA: Temperatura crítica - " + String(temp, 2) + " °C";
    client.publish("AlarmaAltaTemperatura", (const uint8_t*) alerta.c_str(), alerta.length(), false);

  } else if (temp > 40.0) {
    digitalWrite(LED2, HIGH);
    delay(3000);
    digitalWrite(LED2, LOW);
  }
}

// Reconecciones al broker
void reconnect() {
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT...");
    String clientId = "ESP32Receptor-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println(" conectado.");
      client.subscribe("tempESP");
    } else {
      Serial.print(" fallo, rc=");
      Serial.print(client.state());
      Serial.println(" reintentando en 5 segundos.");
      delay(5000);
    }
  }
}

// Coneccion a wifi
void setup_wifi() {
  delay(10);
  Serial.println("Conectando a WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" WiFi conectado");
}

// comienza monitor serial, salida de los leds, wifi, server mqtt y funcion callback para reaccionar a los mensajes recibidos
void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

// Realiza la reconeccion de no estar establecida. Continua con el callback
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
