#include <VirtualWire.h> // Biblioteca para comunicación RF
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>

// Definición de pines
#define DATA_PIN 12 // Pin de datos para RF
#define RELAY_PIN 7 // Pin conectado al Relay de la lámpara (ajusta según tu conexión)

// Crear objeto para la pantalla LCD
LiquidCrystal_I2C lcd(0x38, 20, 4); // Asegúrate de que la dirección sea correcta

void setup() {
  Serial.begin(9600); // Iniciar la comunicación serial
  lcd.init(); // Inicializar el LCD
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Esperando mensaje");

  pinMode(RELAY_PIN, OUTPUT); // Configurar el pin del Relay como salida
  digitalWrite(RELAY_PIN, LOW); // Inicialmente la lámpara apagada

  vw_set_ptt_inverted(true); // Requerido por DR3100
  vw_set_rx_pin(DATA_PIN); // Configurar el pin de datos
  vw_setup(4000); // Configurar la velocidad en baudios (4000 bps)

  vw_rx_start(); // Comenzar a recibir mensajes
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // Buffer para almacenar el mensaje recibido
  uint8_t buflen = VW_MAX_MESSAGE_LEN; // Tamaño del buffer

  if (vw_get_message(buf, &buflen)) {
    // Convertir el buffer recibido a una cadena
    String receivedMessage = (char*)buf;
    Serial.print("Mensaje Recibido: ");
    Serial.println(receivedMessage);

    // Extraer temperatura y humedad del mensaje (formato: "Txx.xHyy.y")
    float temperature = -100.0;
    float humidity = -1.0;
    int tIndex = receivedMessage.indexOf('T');
    int hIndex = receivedMessage.indexOf('H');

    if (tIndex != -1 && hIndex != -1) {
      String tempStr = receivedMessage.substring(tIndex + 1, hIndex);
      temperature = tempStr.toFloat();
      String humStr = receivedMessage.substring(hIndex + 1);
      humidity = humStr.toFloat();

      Serial.print("Temperatura Recibida: ");
      Serial.println(temperature);
      Serial.print("Humedad Recibida: ");
      Serial.println(humidity);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temperature);
      lcd.print(" C");
      lcd.setCursor(0, 1);
      lcd.print("Hum: ");
      lcd.print(humidity);
      lcd.print(" %");

      // Lógica para controlar la lámpara
      if (temperature > 20.0 && humidity > 50.0) {
        digitalWrite(RELAY_PIN, HIGH); // Enciende la lámpara
        Serial.println("Lampara ENCENDIDA");
        lcd.setCursor(0, 2);
        lcd.print("Lampara: ENCENDIDA");
      } else {
        digitalWrite(RELAY_PIN, LOW); // Apaga la lámpara
        Serial.println("Lampara APAGADA");
        lcd.setCursor(0, 2);
        lcd.print("Lampara: APAGADA ");
      }
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Formato Invalido");
      delay(2000);
    }

    delay(100); // Pequeño delay
  }
}
