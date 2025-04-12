# LOS TRES PROTOCOLOS EN SERIE MAS UTILIZADOS SON  
--- 
###  **UART (Universal Asynchronous Receiver/Transmitter)**

- #### Tipo: Asíncrono (no requiere señal de reloj)

- #### Uso común: Comunicación entre microcontroladores, módulos Bluetooth, GPS, etc.
- #### Características:

 Solo requiere dos líneas: TX (transmisión) y RX (recepción)

 La velocidad (baud rate) debe estar configurada igual en ambos dispositivos

 No es adecuado para largas distancias

 No tiene un estándar físico (se implementa dentro del microcontrolador)

 ---
 ### **I2C (Inter-Integrated Circuit)** 
- #### ipo: Síncrono (requiere señal de reloj)

- #### Uso común: Sensores, memorias EEPROM, pantallas, RTC, etc.

- #### Características:

Usa solo dos líneas: SDA (datos) y SCL (reloj)

Soporta múltiples dispositivos en el mismo bus (comunicación multidispositivo)

Cada dispositivo tiene una dirección única

Velocidades típicas: 100 kHz, 400 kHz, hasta 3.4 MHz (High Speed Mode)

---
### **SPI (Serial Peripheral Interface)**

- #### Tipo: Síncrono

- #### Uso común: Comunicación rápida entre microcontroladores y periféricos como memorias flash, sensores, pantallas, etc.

- #### Características:

Usa al menos 4 líneas: MISO, MOSI, SCK, y SS/CS (chip select)

Comunicación full-dúplex (puede enviar y recibir al mismo tiempo)

Más rápido que I2C pero requiere más pines

No tiene un protocolo de direccionamiento como I2C, por lo que necesita una línea de selección por dispositivo esclavo


