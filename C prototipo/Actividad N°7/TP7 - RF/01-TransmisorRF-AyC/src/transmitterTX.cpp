#include <Wire.h>
#include <DHT.h>                // Biblioteca para el sensor DHT
#include <SPI.h>
#include <LiquidCrystal_I2C.h>  // Biblioteca para controlar el LCD I2C
#include <VirtualWire.h>        // Biblioteca para comunicación RF

#define DATA_PIN 12       // Pin de datos para RF
#define DHTPIN 4          // Pin conectado al sensor DHT
#define DHTTYPE DHT11     // Tipo de sensor DHT (DHT11, DHT22, AM2302)

// Objeto para la pantalla LCD con dirección 0x38

LiquidCrystal_I2C lcd(0x38, 20, 4); 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializar la biblioteca VirtualWire

  vw_set_ptt_inverted(true);
  vw_set_tx_pin(DATA_PIN);                     // Configurar el pin de datos
  vw_setup(4000);                             // Configurar la velocidad en baudios (4000 bps)

  Serial.begin(9600);                         // Iniciar la comunicación serial
  Serial.println("Transmisor RF con DHT");

  dht.begin();                                // Inicializar el sensor DHT

  // Inicializar el LCD
 
  lcd.begin(16, 2);                           // Inicializar el LCD con 16 columnas y 2 filas (ajusta si es diferente)
  lcd.backlight();                            // Encender la luz de fondo del LCD
  lcd.setCursor(0, 0);                        // Colocar el cursor en la primera línea
  lcd.print("TX Listo (DHT)");                // Mensaje inicial en el LCD
}

void loop() {
  delay(2000); // Esperar un momento antes de leer el sensor

  // Leer la temperatura y la humedad

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer el sensor DHT!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error DHT!");
    delay(2000);
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %, Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");

  // Formatear el mensaje con temperatura y humedad

  String message = "T" + String(t, 1) + "H" + String(h, 1);   // Txx.xHyy.y
  Serial.print("Enviando: ");
  Serial.println(message);
  
  vw_send((uint8_t *)message.c_str(), message.length());      // Enviar el mensaje   
  vw_wait_tx();                                               // Esperar a que se complete la transmisión

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enviado:");
  lcd.setCursor(0, 1);
  lcd.print(message);

  delay(3000); // Esperar antes de la siguiente lectura y envío
}