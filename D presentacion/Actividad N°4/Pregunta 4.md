![Carátula](../../E%20assets/caratula.png)


# 4) Implementar un código JSON, para comunicar un sensor de temperatura y humedad con un ESP32, simulando los mismos en WOKWI.
# ¿Cuáles serían los campos mínimos para hacer la implementación?  

**`#include <ArduinoJson.h>`**  
Esta línea incluye la biblioteca ArduinoJson.
ArduinoJson es una librería para trabajar con el formato JSON (JavaScript Object Notation) en placas como Arduino, ESP32, ESP8266, etc. 

**`StaticJsonDocument<128> doc;`**  
Se crea un objeto llamado doc de tipo StaticJsonDocument, el cual reserva 128 bytes de memoria estática para almacenar los datos en formato JSON. 
Este objeto servirá como contenedor para construir y organizar la estructura del mensaje JSON.

**`doc["Temperatura"] = temperatura;`**  
 Asigna un valor a la clave "Temperatura" dentro del objeto JSON doc. Esto significa que se esta agregando un nuevo par clave-valor al documento JSON.

**`String jsonOutput;`**  
**`serializeJson(doc, jsonOutput);`**  
**String jsonOutput;** Crea una variable de tipo String llamada jsonOutput que servirá para guardar el texto del JSON que se va a generar. 

**serializeJson(doc, jsonOutput);** Convierte el contenido del objeto doc (que es un JSON en memoria) en una cadena de texto. El resultado de esa conversión se guarda dentro de la variable jsonOutput.


***Se comparte el codigo generado  en C++ para la simulación en WOKWI, se imprimen en el monitor serial el mensaje JSON y los valores medidos por los potenciometros, simulando los sensores de temperatura y humedad.
Se utiliza la aplicacion andriod "IOT MQTT" para recibir los datos de las mediciones.***  

## AyC TP4-p4

### Link a simulación: https://wokwi.com/projects/428719509160397825

![Imagen](/../../blob/main/E%20assets/Cuestionario%20N4/ayctp4-p4.png)

![Imagen1](/../../blob/main/E%20assets/Cuestionario%20N4/ayctp4-p4-1.png)


    #include <Arduino.h>
    #include <WiFi.h>
    #include <PubSubClient.h>
    #include <ArduinoJson.h>
    
    // Pines de sensores simulados
    const int tempPin = 34; // Potenciómetro para temperatura
    const int humPin  = 35; // Potenciómetro para humedad
    
    // WiFi - Wokwi
    const char* ssid = "Wokwi-GUEST";
    const char* password = "";

    // MQTT
    WiFiClient espClient;
    PubSubClient client(espClient);
    const char* mqtt_server = "test.mosquitto.org";
    const int mqtt_port = 1883;
    const char* mqtt_client_id = "esp32_control_full";
    const char* mqtt_topic = "/casa/sala/mediciones";
    
    void connectToWiFi() {
      Serial.print("Conectando a WiFi...");
      WiFi.begin(ssid, password);
    
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println(" conectado!");
    }
    
    void connectToMQTT() {
      Serial.print("Conectando a MQTT...");
      client.setServer(mqtt_server, mqtt_port);
    
      while (!client.connected()) {
        if (client.connect(mqtt_client_id)) {
          Serial.println(" conectado!");
        } else {
          Serial.print(" fallo, rc=");
          Serial.print(client.state());
          Serial.println(" intentando de nuevo en 5 segundos");
          delay(5000);
        }
      }
    }
    
    void setup() {
      Serial.begin(115200);
      WiFi.mode(WIFI_STA);
      connectToWiFi();
      connectToMQTT();
    }

    void loop() {
      if (!client.connected()) {
        connectToMQTT();
      }
      client.loop();
    
      int tempRaw = analogRead(tempPin);
      int humRaw  = analogRead(humPin);
    
      float temperatura = map(tempRaw, 0, 4095, 0, 500) / 10.0; // 0-50°C
      float humedad     = map(humRaw,  0, 4095, 0, 1000) / 10.0; // 0-100%
    
      // Crear objeto JSON
      StaticJsonDocument<128> doc;
      doc["Temperatura"] = temperatura;
      doc["Humedad"] = humedad;
    
      // Serializar JSON
      String jsonOutput;
      serializeJson(doc, jsonOutput);
    
      // Mostrar en Serial
      Serial.println("----- JSON enviado a MQTT -----");
      Serial.println(jsonOutput);
      Serial.println();
    
      // Publicar en el único topic
      client.publish(mqtt_topic, jsonOutput.c_str());
    
        // Imprimir valores por separado
      Serial.println("----- Lectura -----");
      Serial.print("Temperatura: ");
      Serial.print(temperatura);
      Serial.println("° C");
    
      Serial.print("Humedad: ");
      Serial.print(humedad);
      Serial.println("%");
    
      Serial.println();  // Línea en blanco para separación
    
      delay(3000); // Publicar cada 3 segundos
    }
