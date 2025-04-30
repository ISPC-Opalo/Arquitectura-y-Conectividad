#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT; // Crear un objeto BluetoothSerial

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_NodeMCU"); // Iniciar Bluetooth con el nombre "ESP32_Bluetooth"
  Serial.println("El dispositivo está listo para emparejarse.");
}

void loop() {
  // Si hay datos disponibles desde el Monitor Serie, enviarlos vía Bluetooth
  if (Serial.available()) {
    String message = Serial.readString();  // Leer el mensaje del Monitor Serie
    SerialBT.print(message);               // Enviar el mensaje vía Bluetooth
    Serial.print("Enviando vía Bluetooth: ");
    Serial.println(message);
  }

  // Si hay datos recibidos vía Bluetooth, mostrarlos en el Monitor Serie
  if (SerialBT.available()) {
    String btMessage = SerialBT.readString();  // Leer el mensaje recibido vía Bluetooth
    Serial.print("Mensaje recibido vía Bluetooth: ");
    Serial.println(btMessage);                 // Mostrar el mensaje en el Monitor Serie
  }
}
