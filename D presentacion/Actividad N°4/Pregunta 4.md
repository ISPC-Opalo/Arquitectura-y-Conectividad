![Carátula](../../E%20assets/caratula.png)


# 4) Implementar un código JSON, para comunicar un sensor de temperatura y humedad con un ESP32, simulando los mismos en WOKWI.
# ¿Cuáles serían los campos mínimos para hacer la implementación?  

***Se comparte el codigo generado  en C++ para la simulación en WOKWI, se imprimen en el monitor serial el mensaje JSON y los valores medidos por los potenciometros, simulando los sensores de temperatura y humedad.***  

## AyC TP4-p4
![Imagen](/../../E%20assets/Cuestionario%20N4/ayctp4-p4.png)

![Imagen1](/../../E%20assets/Cuestionario%20N4/ayctp4-p4-1.png)

    #include  <Arduino.h>
    
    #include  <ArduinoJson.h>
    
    
    const  int tempPin =  34;  // Potenciómetro para temperatura
    
    const  int humPin =  35;  // Potenciómetro para humedad
    
      
    
    void  setup()  {
    
    Serial.begin(115200);
    
    }
    
      
    
    void  loop()  {
    
    int tempRaw =  analogRead(tempPin);
    
    int humRaw =  analogRead(humPin);
    
      
    
    // Convertimos a valores reales
    
    float temperatura =  map(tempRaw,  0,  4095,  0,  500)  /  10.0;  // 0-50 °C
    
    float humedad =  map(humRaw,  0,  4095,  0,  1000)  /  10.0;  // 0-100 %
    
      
    
    // Crear objeto JSON
    
    StaticJsonDocument<128> doc;
    
    doc["Temperatura"]  = temperatura;
    
    doc["Humedad"]  = humedad;
    
      
    
    // Serializar como string JSON
    
    String jsonOutput;
    
    serializeJson(doc, jsonOutput);
    
    Serial.println("----- JSON -----");
    
    Serial.println(jsonOutput);
    
      
    
    Serial.println();  // Línea en blanco para separación
    
      
    
    // Imprimir valores por separado
    
    Serial.println("----- Lectura -----");
    
    Serial.print("Temperatura: ");
    
    Serial.print(temperatura);
    
    Serial.println("° C");
    
      
    
    Serial.print("Humedad: ");
    
    Serial.print(humedad);
    
    Serial.println("%");
    
      
    
    Serial.println();  // Línea en blanco para separación
    
      
    
    delay(3000);
    
    }
