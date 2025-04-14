![Carátula](../../E%20assets/caratula.png)

# TECNICATURA SUPERIOR EN TELECOMUNICACIONES

## PROTOCOLOS DE SERIE MÁS USADOS

Los protocolos de serie más usados son UART, I²C, y SPI. Estos protocolos se usan para transmitir datos entre dispositivos de manera secuencial. 

Una categoría especial de protocolos serie son aquellos que se utilizan en la industria automotriz, como CAN, LIy FlexRay. Estos protocolos se diseñaron para lidiar con los exigentes requisitos de los vehículos como proporcionarles un funcionamiento eficiente a una combinación de velocidades bajas y altas y en un entorno con mucho ruido.

## Protocolo UART

El receptor-transmisor asíncrono universal (UART) es un protocolo que permite a los dispositivos intercambiar datos en serie, o bit a bit. Es una forma sencilla y flexible de comunicarse entre dispositivos con diferentes frecuencias de reloj.

### Funcionamiento:

- El **UART** utiliza dos cables entre el transmisor y el receptor.
- Los datos se envían en tramas, que suelen incluir un bit de inicio, bits de datos, un bit de paridad opcional y bits de parada.
- El receptor lee el paquete de datos bit a bit y lo reensambla en bytes.
- El **UART** es asíncrono, lo que significa que no hay una señal de reloj compartida entre el transmisor y el receptor.
- El transmisor y el receptor acuerdan una velocidad en baudios (bits por segundo) para sincronizar su comunicación.

### Ejemplo de UART:

<img src= "![alt text](https://i.ytimg.com/vi/sTHckUyxwp8/maxresdefault.jpg)" />

## Protcolo I²C

**I2C** (Inter-Integrated Circuit) es un protocolo de comunicación en serie que permite la comunicación entre múltiples dispositivos a través de dos cables. Se utiliza frecuentemente para la comunicación de corta distancia entre microcontroladores y sensores.

### Funcionamiento:

- **I2C** utiliza un modelo maestro-esclavo, donde el maestro proporciona el reloj.
- La comunicación se envía en paquetes de bytes, cada uno con una dirección única para el dispositivo de destino.
- Cada trama de datos va seguida de un bit ACK/NACK para confirmar su recepción.
- El bus **I2C** utiliza una salida de drenaje abierto, lo que significa que el bus puede ser descargado a tierra o liberado para ser descargado mediante una resistencia.

### Ejemplo de I²C:

<img src= "![**alt text**](https://www.analog.com/en/_/media/analog/en/landing-pages/technical-articles/i2c-primer-what-is-i2c-part-1-/36689.png?la=en&rev=800e587601a84cb28576fb870b2cdc8b)" />

## Protocolos SPI

La Interfaz Periférica en Serie (SPI) es un protocolo de comunicación que permite el intercambio de datos entre dispositivos. Es una opción común para la comunicación a corta distancia entre microcontroladores y dispositivos periféricos. SPI se utiliza en numerosas aplicaciones, como sistemas embebidos, IoT y vehículos autónomos.

### Funcionamiento:

- **SPI** es un protocolo síncrono, lo que significa que transmite y recibe datos simultáneamente.
- **SPI** utiliza una configuración maestro-esclavo, donde el maestro controla a los esclavos.
- **SPI** utiliza múltiples líneas de transmisión o cables de señal para conectar los dispositivos.
- **SPI** utiliza una señal de reloj sincronizada que comparten todos los dispositivos.
- **SPI** cuenta con canales dedicados para transmitir y recibir datos.

### Ejemplo de SPI:

<img src= "![**alt text**](https://cdn.sparkfun.com/assets/learn_tutorials/1/6/SPI_CS_Updated2.png)" />
