![Carátula](../../E%20assets/caratula.png)


# ¿Qué es el protocolo MODBUS?

### **¿Qué es el protocolo Modbus RTU?**

Modbus es un protocolo de comunicaciones, basado en la arquitectura maestro/esclavo o cliente/servidor, diseñado en 1979 por Modicon (ahora Schneider Electric) para su gama de controladores lógicos programables (PLCs).
Debido a que este protocolo fue público, de fácil uso y que requiere poco desarrollo (maneja bloques de datos sin suponer restricciones) se convirtió en un protocolo de comunicaciones estándar en la industria. Es el protocolo de mayor disponibilidad para la conexión de dispositivos electrónicos industriales.  
El protocolo Modbus permite el control de una red de dispositivos, por ejemplo un equipo de medición temperatura y humedad puede comunicar los resultados a una PC. Modbus también se usa para la conexión de un PC de supervisión con una unidad remota (RTU) en sistemas de supervisión de adquisición de datos (SCADA). 
Existen versiones del protocolo Modbus para puerto serial y Ethernet (Modbus/TCP).

----------

### ¿Para qué se usa?  

Se utiliza para conectar dispositivos electrónicos industriales y permitir la supervisión y el control remoto de procesos. MODBUS es simple, robusto y confiable, lo que lo hace ideal para aplicaciones industriales donde se requiere comunicación maestro/esclavo.

El protocolo MODBUS funciona bajo un esquema **maestro-esclavo** (o cliente-servidor) donde un dispositivo central (el maestro o cliente) se comunica con uno o varios dispositivos periféricos (los esclavos o servidores) para intercambiar información. 

Aquí se explican los aspectos clave de su funcionamiento:

**1. Arquitectura Maestro-Esclavo:**

-   **Maestro:** Es el dispositivo que inicia la comunicación enviando una **consulta** a uno o varios esclavos. Típicamente es un PLC, una PC con software SCADA, o una HMI (Human Machine Interface).
-   **Esclavo:** Son los dispositivos que **responden** a las consultas del maestro con la información solicitada o realizando la acción indicada. Pueden ser sensores, actuadores, otros PLCs, medidores, etc.
-   **Dirección de Esclavo:** Cada esclavo en una red MODBUS tiene una **dirección única** (entre 1 y 247 para MODBUS Serial). El maestro utiliza esta dirección para especificar a qué esclavo va dirigida la consulta.

**2. Modelo de Datos:**

MODBUS define cuatro tablas de datos principales que los esclavos utilizan para almacenar información. El maestro puede acceder a estas tablas:

-   **Bobinas (Coils):** Registros de 1 bit para salidas discretas (on/off). Se acceden con los códigos de función 01 (Leer Bobinas) y 05/15 (Escribir Bobinas).
-   **Entradas Discretas (Discrete Inputs):** Registros de 1 bit para entradas discretas (solo lectura). Se acceden con el código de función 02 (Leer Entradas Discretas).
-   **Registros de Entrada (Input Registers):** Registros de 16 bits para valores analógicos de entrada (solo lectura). Se acceden con el código de función 04 (Leer Registros de Entrada).
-   **Registros de Retención (Holding Registers):** Registros de 16 bits para valores analógicos de salida o parámetros de configuración (lectura/escritura). Se acceden con los códigos de función 03 (Leer Registros de Retención) y 06/16 (Escribir Registros de Retención).

**Es importante notar:** La documentación de cada dispositivo esclavo indicará cómo se mapean sus datos físicos (temperatura, estado de un motor, etc.) a estas tablas y direcciones MODBUS.

**3. Unidad de Datos del Protocolo (PDU):**

La PDU es la parte del mensaje MODBUS que contiene la información esencial para la comunicación. Tiene un formato común tanto para la consulta del maestro como para la respuesta del esclavo:

-   **Código de Función (Function Code):** Un byte que indica la acción que el maestro quiere que el esclavo realice (lectura o escritura de datos) o el tipo de respuesta del esclavo.
-   **Datos (Data):** Contiene información adicional necesaria para la función, como la dirección inicial del registro a leer o escribir, la cantidad de registros, y los datos a escribir.

**4. Unidad de Datos de Aplicación (ADU):**

La ADU es la PDU envuelta en información adicional dependiendo del medio de comunicación utilizado:

-   **MODBUS Serial (RTU):**
    -   **Dirección del Esclavo (Slave Address):** Un byte que especifica el esclavo destino.
    -   **PDU (Código de Función + Datos):**
    -   **Verificación de Redundancia Cíclica (CRC - Cyclic Redundancy Check):** Dos bytes para la detección de errores en la transmisión.


____

-   **MODBUS TCP/IP:**
    -   **Identificador de Transacción (Transaction Identifier):** Dos bytes para identificar pares de solicitud-respuesta.
    -   **Identificador de Protocolo (Protocol Identifier):** Dos bytes (siempre 0 para MODBUS).
    -   **Longitud (Length):** Dos bytes que indican la longitud de los bytes siguientes.
    -   **Identificador de Unidad (Unit Identifier):** Un byte (similar a la dirección de esclavo en serial, útil para enrutar a través de gateways).
    -   **PDU (Código de Función + Datos):**
___

**5. Proceso de Comunicación:**

1.  **El maestro envía una consulta MODBUS:** El maestro construye un mensaje ADU con la dirección del esclavo, el código de función deseado y cualquier dato necesario (dirección de inicio, cantidad de datos, etc.).
2.  **El mensaje viaja por el medio de comunicación:** Esto puede ser un cable serial (RS-232, RS-485) para MODBUS RTU o una red Ethernet para MODBUS TCP/IP.
3.  **El esclavo recibe la consulta:** Cada esclavo en la red escucha las consultas. Solo el esclavo cuya dirección coincide con la dirección en la consulta procesa el mensaje.
4.  **El esclavo procesa la solicitud:** El esclavo realiza la acción solicitada (lee los datos de sus tablas, escribe nuevos valores, etc.).
5.  **El esclavo envía una respuesta MODBUS (si es necesario):** El esclavo construye un mensaje ADU de respuesta que incluye el código de función (que puede indicar un error), los datos solicitados (si fue una lectura) y cualquier información de verificación de errores.
6.  **El maestro recibe la respuesta:** El maestro verifica si la respuesta es válida (dirección correcta, sin errores de transmisión) y extrae los datos necesarios.

**Ejemplo Simplificado (Lectura de un Registro de Retención):**

Imagina un maestro (PLC) queriendo leer el valor de temperatura (almacenado en el registro de retención número 40001, que corresponde a la dirección 0 en la PDU) de un sensor esclavo con dirección 05 (en MODBUS RTU).

**Consulta del Maestro (MODBUS RTU):**

    [Dirección Esclavo (05)] 
    [Código Función (03 - Leer Holding Registers)] 
    [Dirección Inicio (00 00)]
    [Cantidad Registros (00 01)] 
    [CRC (XX XX)]

**Respuesta del Esclavo (si la temperatura es 25 °C, que podría representarse como el valor hexadecimal 0019):**

    [Dirección Esclavo (05)] 
    [Código Función (03)] 
    [Cantidad Bytes (02)] 
    [Dato Alto (00)] 
    [Dato Bajo (19)] 
    [CRC (YY YY)]

### **¿Cuáles son los beneficios de utilizar el protocolo Modbus RTU/TCP?**

-   De código abierto, no se requiere pagar por licencia.
-   Ampliamente soportado por HMIs o softwares SCADA
-   Fácil de usar
-   Se pueden integrar varios equipos fácilmente
-   Bajo costo de desarrollo
-   Conocido ampliamente en la industria

**En resumen, MODBUS facilita la comunicación entre dispositivos industriales a través de un modelo simple de consultas y respuestas, un conjunto bien definido de funciones y tablas de datos, y formatos de mensajes específicos para diferentes medios de comunicación. La clave para entender un sistema MODBUS en particular reside en conocer la dirección de cada esclavo y cómo se mapean los datos de cada dispositivo a las tablas y direcciones MODBUS que expone.**

### ¿En qué lenguaje se programa?

El protocolo MODBUS no define un lenguaje de programación específico, ya que se centra en el formato de mensajes y el protocolo de comunicación. En entornos industriales  se puede encontrar como **Ladder (Escalera)** dentro de PLCs.

El lenguaje más utilizado actualmente para sistemas embebidos con MODBUS es **C/C++**, mientras que **Python** es muy popular para pruebas, herramientas de monitoreo o desarrollo rápido en PC.

----
### Ejemplo de aplicación

Un **PLC maestro** se comunica mediante MODBUS RTU sobre RS-485 con los siguientes dispositivos esclavos:

-   Un **sensor de temperatura**
    
-   Un **variador de frecuencia (drive)**
    
-   Una **pantalla HMI**
    

#### El PLC solicita datos de temperatura, ajusta la velocidad del motor según estos datos y muestra la información en la HMI.

![Imagen](/../../blob/main/E%20assets/Cuestionario%20N5/protocolo_MODBUS_RTO.png)  

#### Tambien se puede realizar la comunicación vía ethernet:

![Imagen](/../../blob/main/E%20assets/Cuestionario%20N5/protocolo_MODBUS_Ether.png)

----------

SE AGREGA CUADRO COMPARATIVO DE LOS PROTOCOLOS DE COMUNICION UTILIZADOS EN LOS 
ENTORNOS INDUSTRIALES E IOT:

## Cuadro Comparativo de Protocolos Industriales y IoT

| Protocolo               | Tipo de Protocolo                      | Arquitectura                          | Medio de Transmisión                  | Velocidad                             | Número de Dispositivos                  | Aplicaciones Típicas                     | Complejidad                         | Tiempo Real                       | Seguridad                            | Ventajas                                      | Desventajas                                  |
| :---------------------- | :------------------------------------- | :------------------------------------ | :------------------------------------ | :------------------------------------ | :-------------------------------------- | :-------------------------------------- | :---------------------------------- | :-------------------------------- | :----------------------------------- | :-------------------------------------------- | :------------------------------------------- |
| **CoAP** | IoT (RESTful)                        | Cliente-Servidor                      | UDP, TCP, SMS, Bluetooth              | Baja a Media                          | Depende de la red IP                    | IoT restringido, Smart Devices         | Simple                              | No determinístico                   | DTLS (opcional)                      | Ligero, eficiente para IoT                   | Seguridad sin DTLS, adopción                 |
| **AMQP** | Middleware (Mensajería)              | Broker-Centrado                       | TCP                                   | Media a Alta                          | Prácticamente ilimitado                 | Mensajería empresarial, sistemas distribuidos | Media a Alta                          | Configurable (QoS)                | TLS/SSL, SASL                        | Robusto, flexible, confiable                | Mayor complejidad, overhead                |
| **MODBUS** | Industrial                             | Maestro-Esclavo                       | Serial, Ethernet                      | Baja a Alta                           | Hasta 247 (serial) / Ilimitado (Ethernet) | Automatización general, SCADA           | Simple a Media                      | No determinístico (típicamente)      | Limitada (serial) / Variable (Ethernet) | Ampliamente soportado, simple, bajo costo | Baja velocidad (serial), seguridad           |
| **HART** | Industrial (Híbrido)                   | Maestro-Esclavo (Punto a Punto)       | Bucle de corriente (4-20 mA)          | Baja                                  | Punto a punto                             | Instrumentación de procesos, diagnóstico | Simple                              | No determinístico                   | Limitada                             | Superposición analógica+digital, diagnóstico | Baja velocidad, infraestructura analógica |
| **PROFINET** | Industrial                             | Maestro-Esclavo, Peer-to-Peer         | Ethernet                              | Alta                                  | Prácticamente ilimitado                 | Automatización de fábricas, control de movimiento | Compleja                            | Determinístico (con IRT)            | Amplias opciones                       | Alto rendimiento, integración IT, robusto    | Mayor complejidad, costo                   |
| **CANopen** | Industrial                             | Maestro-Esclavo, Peer-to-Peer         | CAN Bus                               | Baja a Media                          | Hasta 127                               | Control de maquinaria, robótica         | Media                               | Determinístico (configurable)       | Depende de la implementación         | Robusto para entornos distribuidos         | Complejidad de configuración              |
| **PROFIBUS-DP/PA** | Industrial                             | Maestro-Esclavo                       | Serial (RS-485), Bucle de corriente    | Baja a Media                          | Hasta 126 (DP)                            | Automatización de fábricas y procesos   | Media                               | Determinístico (con extensiones)      | Depende de la implementación         | Amplia base instalada, versátil          | Requiere terminación, sensibilidad al ruido (DP) |
