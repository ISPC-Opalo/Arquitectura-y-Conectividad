## 4) Simular un sensor de temperatura, una luz con dimmer, un botón de encendido y apagado mediante Wokwi, Proteus, LabView; etc con ESP32.

***El código desarrollado en el simulador Wokwi, y la simulación se puede ejecutar desde la extensión de platformio en VScode. A a continuación se describe el funcionamiento parte por parte del código. El prototipo funcional se encuentra alojado en el repositorio correspondiente.***

### Aquí se explica el desarrollo del mismo:

#### 1. Inclusión de librerías y definición de pines

>     #include <Arduino.h>
>     
>       
>     
>     // Pines del ESP32
>     
>     const int tempSensorPin = 26; // Slide pot como “sensor” de temperatura
>     
>     const int dimmerPin = 33; // Potenciómetro estándar para regular brillo
>     
>     const int ledPin = 15; // LED conectado al pin 15
>     
>     const int buttonPin = 4; // Botón conectado al pin 4

-   #include <Arduino.h> te da acceso a analogRead(), digitalRead(), millis(), etc.  
-   Se definen las constantes para cada pin, de modo que si cambias pines en el hardware solo modifiques aquí arriba.
    

  

#### 2. Variables de estado    

>     int tempRawValue = 0; // Lectura bruta ADC del “sensor”
>     
>     float simulatedTemperatureC = 0.0; // Temperatura en °C tras map()
>     
>     int dimmerValue = 0; // Lectura bruta ADC del dimmer
>     
>     bool lightOn = false; // Estado actual del LED (encendido/apagado)
>     
>       
>     
>     // Variables para debounce del botón
>     
>     int lastButtonReading = HIGH; // Última lectura cruda del pin
>     
>     bool lastDebouncedState = HIGH; // Último estado “estable” verificado
>     
>     unsigned long lastDebounceTime = 0; // Timestamp del último cambio
>     
>     const unsigned long debounceDelay = 50; // Ms mínimo para considerar el cambio válido
>     
>       
>     
>     // Para controlar cada cuánto imprimimos en el monitor serie
>     
>     unsigned long lastPrintTime = 0;
>     
>     const unsigned long printInterval = 1000; // imprimir una vez por segundo

    
   - Debounce: evita lecturas falsas (rebotes) del botón.  
   - millis() lo usamos como reloj sin bloquear el programa con delay() excesivos.
     
  

#### 3. Configuración inicial (setup())

    void setup() {
    
    Serial.begin(115200); // Inicia el puerto serie a 115200 bps
    
    pinMode(buttonPin, INPUT_PULLUP); // Botón con pull‑up interno
    
    pinMode(ledPin, OUTPUT); // LED como salida digital
    
    Serial.println("Sistema listo: Botón, LED con dimmer, sensor simulado.");
    
    }

-   INPUT_PULLUP activa la resistencia interna que deja el pin en HIGH hasta que el botón lo lleve a GND.    
-   Inicializamos el monitor serie y damos un mensaje de “arranque”.
    

#### 4. Bucle principal (loop())

    tempRawValue = analogRead(tempSensorPin);
    
    // Mapeamos [0–4095] → [10–40] °C
    
    simulatedTemperatureC = map(tempRawValue, 0, 4095, 10, 40);

-   **analogRead()** en el ESP32 devuelve 0…4095 por su ADC de 12 bits.
    
-   **map()** escala ese valor a un rango realista de temperatura.
    

  

#### 4.2. Leer y “debounciar” el botón

    int currentReading = digitalRead(buttonPin);
    
    if (currentReading != lastButtonReading) {
    
    // Si cambió la lectura, reiniciamos el contador de estabilidad
    
    lastDebounceTime = millis();
    
    }
    
    if ((millis() - lastDebounceTime) > debounceDelay) {
    
    // Si el estado se mantuvo estable más de 50 ms:
    
    if (currentReading == LOW && lastDebouncedState == HIGH) {
    
    // Detectamos un flanco de bajada (pulsación)
    
    lightOn = !lightOn; // Toggle del estado de la luz
    
    }
    
    lastDebouncedState = currentReading;
    
    }
    
    lastButtonReading = currentReading;

-   Flanco de bajada: solo cuando pasamos de HIGH a LOW invertimos lightOn.    
-   Evitamos múltiples toggles por un único clic gracias al retardo de debounceDelay.
   
   
#### 4.3. Control del LED con PWM (dimmer)

    if (lightOn) {
    
    dimmerValue = analogRead(dimmerPin); // 0–4095
    
    int pwmValue = map(dimmerValue, 0, 4095, 0, 255); // 8 bits
    
    analogWrite(ledPin, pwmValue); // Ajusta el brillo
    
    } else {
    
    analogWrite(ledPin, 0); // Apaga el LED
    
    }

-   Cuando lightOn == true, leemos el potenciómetro y lo mapeamos a 0…255 para analogWrite().    
-   Si está apagado, forzamos 0 en PWM para secar toda corriente al LED.
    

  

#### 4.4. Impresión periódica en serie

    if (millis() - lastPrintTime >= printInterval) {
    
    lastPrintTime = millis();
    
    Serial.print("Temp: ");
    
    Serial.print(simulatedTemperatureC);
    
    Serial.print("°C | LED: ");
    
    Serial.print(lightOn ? "ON" : "OFF");
    
    Serial.print(" | Dimmer: ");
    
    Serial.println(dimmerValue);
    
    }

-   Solo mostramos un nuevo mensaje cada segundo (o el intervalo que definas), manteniendo la consola limpia.
-   Mientras tanto, el bucle sigue respondiendo rápido al botón y al dimmer.
    

  

#### 4.5. Pausa

    delay(50);