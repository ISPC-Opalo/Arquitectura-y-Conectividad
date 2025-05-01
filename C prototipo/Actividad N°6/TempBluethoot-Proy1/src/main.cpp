#include <Arduino.h>
#include <BluetoothSerial.h>
#include <DHT.h>

// Verifica si Bluetooth está habilitado en este ESP32
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth no está habilitado!
#endif

// Define el tipo de sensor DHT
#define DHTPIN 4     // Pin digital conectado al sensor DHT 
#define DHTTYPE DHT22   // DHT 22 (AM2302) - Cambia a DHT11 si se usa ese modelo

// Inicializa el puerto serie Bluetooth
BluetoothSerial SerialBT;

// Inicializa el DHT
DHT dht(DHTPIN, DHTTYPE);

// Variables para almacenar los valores de temp y humedad
float temperatura;
float humedad;

// Variable para controlar el tiempo entre lecturas
unsigned long tiempoAnterior = 0;
const long intervalo = 5000;  // Intervalo de tiempo entre lecturas (5 segundos)

void setup() {
  Serial.begin(9600);
  
  // Inicializar el sensor DHT
  dht.begin();
  
  // Inicializar Bluetooth y su nombre
  SerialBT.begin("ESP32_Sensor_TyH"); 
  Serial.println("Dispositivo Bluetooth iniciado. Ahora podes emparejarlo.");
}

void loop() {
  // Código para realizar lecturas a intervalos regulares
  unsigned long tiempoActual = millis();
  
  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;
    
    // Lee temperatura y humedad
    humedad = dht.readHumidity();
    temperatura = dht.readTemperature();
    
    // Verifica si las lecturas son válidas
    if (isnan(humedad) || isnan(temperatura)) {
      Serial.println("Error al leer los valores del sensor DHT");
      SerialBT.println("Error al leer los valores del sensor DHT");
      return;
    }
    
    // Formato de datos para Bluetooth Electronics: "$0VTEMPERATURA;$1VHUMEDAD;"
    String datos = "*T" + String(temperatura) + "*H" + String(humedad) + "*";
    
    // Enviar datos por Bluetooth
    SerialBT.print(datos);
    
    // Muestra datos en monitor serie
    Serial.println("Enviando: " + datos);
  }
  
  // Verificar si hay comandos entrantes por Bluetooth
  if (SerialBT.available()) {
    String comando = SerialBT.readStringUntil('\n');
    Serial.println("Comando recibido: " + comando);
    
    // Aca se pueden implementar comandos personalizados
    if (comando == "getLectura") {
      String datos = "Temperatura:" + String(temperatura) + ";Humedad:" + String(humedad);
      SerialBT.println(datos);
    }
  }
}