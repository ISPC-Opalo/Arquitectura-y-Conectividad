//importo librerias
#include <Arduino.h>
#include <BluetoothSerial.h> //Libreria para enviar y recibir datos por Bluetooth
#include <ctype.h> // Para toupper()

//declaro variables
int pinRojo = 5;
int pinAzul = 4;

int pinPotenciometro = 36; // // GPIO36 = VP en el ESP32
int valorPot = 0;
String entrada;
BluetoothSerial bluetooth; //creo el objeto bluetooth

unsigned long tiempoAnterior = 0;
const unsigned long intervalo = 1000; // Enviar cada 1000 ms = 1 segundo

// Verificar si Bluetooth está habilitado
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth no está habilitado!
#endif
void setup(){
    Serial.begin(9600);

    bluetooth.begin("ESP32");//Nombre del bluetooth del esp32
    pinMode(pinRojo,OUTPUT);//declaro el pinRele como salida
    digitalWrite(pinRojo,LOW);//para que la lampara inicie apagado
    pinMode(pinAzul,OUTPUT);//declaro el pinRele como salida
    digitalWrite(pinAzul,LOW);//para que la lampara inicie apagado
   
}
void loop(){
    
    if(bluetooth.available()>0){//verifico si hay algo para leer en el bluetooth
        entrada=" ";
         // Leer todo lo disponible
        while (bluetooth.available()) {
            char c = bluetooth.read();
            entrada += (char)toupper(c); // Convertir cada carácter a mayúscula
            delay(2); // pausa para evitar lectura incompleta
        }
  
        entrada.trim(); // Elimina espacios en blanco
        
    
        if (entrada == "ENCENDER ROJO") {
            digitalWrite(pinRojo, HIGH);
            
        } 
        else {
            if (entrada == "APAGAR ROJO") {
                digitalWrite(pinRojo, LOW);
                
            }else{
                if (entrada == "ENCENDER AZUL") {
                    digitalWrite(pinAzul, HIGH);
                    
                } 
                else 
                    if (entrada == "APAGAR AZUL") {
                        digitalWrite(pinAzul, LOW);
                        
                    }else{
                        if(entrada == "APAGAR TODO"){
                            digitalWrite(pinRojo,LOW);
                            digitalWrite(pinAzul,LOW);
                           
                        }else{
                            if(entrada == "ENCENDER TODO"){
                                digitalWrite(pinRojo,HIGH);
                                digitalWrite(pinAzul,HIGH);
                               
                            }
                        }
                        
                    }
                    
            } 
        }
            
       
    }
    // Enviar lectura del potenciómetro cada intervalo
    unsigned long tiempoActual = millis();
    if (tiempoActual - tiempoAnterior >= intervalo) {
        tiempoAnterior = tiempoActual;
        int valorADC = analogRead(pinPotenciometro);
        float voltaje = (valorADC * 3.3) / 4095.0;
        bluetooth.print("Voltaje: ");
        bluetooth.print(voltaje, 2);
        bluetooth.println("V");

        }
}