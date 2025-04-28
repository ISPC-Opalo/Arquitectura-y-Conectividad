## ¿Qué es el protocolo HART?
**HART *(Highway Addressable Remote Transducer)*** es un **protocolo de comunicación industrial** utilizado principalmente en la **automatización de procesos.** 
Fue desarrollado para permitir que los **instrumentos de medición** como sensores y transmisores puedan comunicarse con un sistema de control (como un PLC o DCS)
y además puedan intercambiar información adicional, todo a través de una **única línea de comunicación**.  
Lo interesante de HART es que combinan **comunicación digital y analógica** en el **mismo cable**. Esto significa que, por ejemplo, un
**sensor de presión** puede seguir enviando una **señal analógica** tradicional de 4-20 mA (que es lo que muchos sistemas usan para leer
valores como la presión), pero al mismo tiempo puede estar enviando **datos digitales** adicionales sobre su estado, configuraciones o diagnósticos,
todo sin interrumpir la **señal analógica**.

### Topologías soportadas
- **Punto a punto** (1 maestro ↔ 1 esclavo)
- **Multidrop** (1 maestro ↔ hasta 15 esclavos)
	- En este modo, cada dispositivo fija su salida a **4 mA**

### ¿Cómo funciona?
Imaginemos que tenemos un **sensor de temperatura** que está conectado a un sistema de control.
- **Señal analógica**: El sensor envía una señal de 4-20 mA, que representa la temperatura medida.
- **Señal digital (HART)**: Al mismo tiempo, el sensor también envía datos digitales sobre su estado, como su modelo, número de serie, posibles fallos, o incluso cambios de configuración.
- **Comunicación bidireccional**: Con HART, además de **leer los valores** de la medición (como la temperatura), podés **enviar comandos** para configurar el sensor, **realizar diagnósticos** o **hacer ajustes**, todo de forma remota.
La señal analógica y la digital viajan a través del mismo cable de manera **superpuesta**. Es decir, las dos señales **no se interfieren entre sí**.

### Lenguaje de programación utilizado
El protocolo HART no depende de un lenguaje de programación específico, ya que es un estándar de comunicación industrial que define cómo se intercambian
datos entre dispositivos (por ejemplo, sensores y controladores). Sin embargo, cuando querés programar un sistema que se comunique mediante HART
(como un maestro HART o un sistema SCADA), los lenguajes más usados para implementar esa comunicación son:

- **C / C++:** Muy común para programar dispositivos embebidos que actúan como maestros HART o gateways. Permite control bajo nivel del hardware y del protocolo.
- **Python:** Usado en entornos de prueba, simulación y desarrollo rápido. Existen bibliotecas y scripts que permiten comunicarse con dispositivos HART a través de puertos serie o adaptadores USB.
- **LabVIEW:** Utilizado en automatización y control industrial. Algunas librerías permiten acceder a dispositivos HART si están conectados a través de interfaces compatibles.
- **.NET / Java:** Usados en sistemas de gestión o aplicaciones de escritorio que comunican con dispositivos HART a través de servidores OPC o gateways.

### Ejemplo
Imaginemos que tenemos una planta de procesamiento químico con sensores de temperatura en varios puntos. Estos sensores están conectados
a un sistema central de control que mide la temperatura para asegurar que los procesos se mantengan dentro de los parámetros correctos.
Con la implementación de HART, los sensores siguen enviando señales análogas que indican la temperatura, pero también están enviando
información digital adicional, como el modelo del sensor, posibles fallos o su estado a través de HART

### ¿Por qué es importante?
- **Flexibilidad**: Permite la comunicación digital sin cambiar los sistemas de control analógicos existentes, lo que lo hace muy fácil de integrar
en instalaciones ya existentes.
- **Diagnósticos avanzados**: Puedes obtener información detallada sobre el estado de los dispositivos, como fallos o condiciones de mantenimiento, algo
que no era posible con los sistemas analógicos tradicionales.
- **Configuración remota**: Puedes ajustar parámetros de los instrumentos sin necesidad de ir físicamente al dispositivo.

### Desventajas del protocolo
**1. Velocidad de comunicación muy baja**  
La velocidad típica es de solo 1200 bps (bits por segundo), lo que lo hace lento para enviar grandes cantidades de datos o múltiples variables.

**2. Limitado a redes punto a punto o multidrop reducidas**  
Aunque admite conexiones multidrop (varios dispositivos en una línea), el número de dispositivos es limitado (generalmente hasta 15) y solo se puede
obtener una variable a la vez.

**3.  Requiere convertidores o pasarelas para integrarse con protocolos digitales modernos**  
Para comunicar HART con sistemas Ethernet industriales (como PROFINET o Modbus TCP), es necesario usar dispositivos intermedios (gateways).

**4. Comunicaciones no deterministas**  
No garantiza tiempos de respuesta exactos, lo que lo hace menos adecuado para aplicaciones que requieren control en tiempo real.

**5. Obsolescencia tecnológica gradual**  
Aunque sigue siendo muy utilizado, está siendo reemplazado por protocolos 100% digitales más rápidos y con mayores capacidades como
**Foundation Fieldbus** o **WirelessHART**.

**6.  Requiere herramientas específicas para configuración avanzada**
Si bien se puede hacer lectura básica fácilmente, para configuraciones avanzadas se necesita un comunicador HART o software especializado.

## Variantes HART

### WirelessHART
Es una extensión inalámbrica del protocolo HART, diseñada para operar en redes industriales sin cables. Fue estandarizado en 2007 bajo la norma IEC 62591.

📡 **Características:**
- Usa radiofrecuencia de 2,4 GHz (similar al Wi-Fi)
- Tecnología de red de malla (mesh): cada dispositivo actúa como nodo repetidor
- Comunicación segura con cifrado AES-128
- Totalmente compatible con dispositivos HART existentes (puede integrarse a través de Gateways)

🎯 **Aplicaciones típicas:**
- Lugares donde es difícil o costoso tender cables (plantas químicas, refinerías, áreas clasificadas)
- Monitoreo de variables ambientales: temperatura, presión, humedad
- Instalaciones temporales o móviles
- Sensores en movimiento o que requieren flexibilidad
- Expansiones de planta sin necesidad de cableado adicional

✅ **Ventajas:**
- Reducción de costos de instalación
- Mayor flexibilidad para reconfigurar redes
- Mejor cobertura en áreas remotas o de difícil acceso

### HART-IP  
Es una variante que permite encapsular mensajes HART para que puedan transmitirse a través de redes Ethernet estándar (TCP/IP).

🌐 **Características:**
- Permite comunicación sobre redes Ethernet o incluso Internet
- Mantiene compatibilidad con comandos HART tradicionales
- Se usa para comunicarse con servidores, sistemas SCADA o software de mantenimiento

🎯 **Aplicaciones típicas:**
- Sistemas de supervisión centralizados en la nube o en redes LAN industriales
- Integración de dispositivos HART en arquitecturas digitales modernas
- Comunicación entre gateways y sistemas de control (como DCS o PLCs)
- Gestión remota de activos (Asset Management)

✅ **Ventajas:**
- Compatible con infraestructuras Ethernet
- Ideal para monitoreo remoto y diagnóstico avanzado
- Se integra fácilmente con sistemas modernos basados en IP

## Diagrama de sistema
#### <p style="text-align:center;">----------- Configuración MULTIDROP -----------</p>
![multidrop](https://cncontrolvalve.com/wp-content/uploads/2023/01/hart-networks-4-600x443.jpg)
![multidrop2](https://cncontrolvalve.com/wp-content/uploads/2023/01/hart-network-3-600x466.jpg)
#### <p style="text-align:center;">----------- Configuración Punto a Punto -----------</p>
![ptp](https://cncontrolvalve.com/wp-content/uploads/2023/01/HART-network-600x498.jpg)

## Cuadro Comparativo de Protocolos Industriales y IoT

| Protocolo               | Tipo de Protocolo                      | Arquitectura                          | Medio de Transmisión                  | Velocidad                             | Número de Dispositivos                  | Aplicaciones Típicas                     | Complejidad                         | Tiempo Real                       | Seguridad                            | Ventajas                                      | Desventajas                                  |
| :---------------------- | :------------------------------------- | :------------------------------------ | :------------------------------------ | :------------------------------------ | :-------------------------------------- | :-------------------------------------- | :---------------------------------- | :-------------------------------- | :----------------------------------- | :-------------------------------------------- | :------------------------------------------- |
| **HART** | Industrial (Híbrido)                   | Maestro-Esclavo (Punto a Punto)       | Bucle de corriente (4-20 mA)          | Baja                                  | Punto a punto                             | Instrumentación de procesos, diagnóstico | Simple                              | No determinístico                   | Limitada                             | Superposición analógica+digital, diagnóstico | Baja velocidad, infraestructura analógica |
| **CoAP** | IoT (RESTful)                        | Cliente-Servidor                      | UDP, TCP, SMS, Bluetooth              | Baja a Media                          | Depende de la red IP                    | IoT restringido, Smart Devices         | Simple                              | No determinístico                   | DTLS (opcional)                      | Ligero, eficiente para IoT                   | Seguridad sin DTLS, adopción                 |
| **AMQP** | Middleware (Mensajería)              | Broker-Centrado                       | TCP                                   | Media a Alta                          | Prácticamente ilimitado                 | Mensajería empresarial, sistemas distribuidos | Media a Alta                          | Configurable (QoS)                | TLS/SSL, SASL                        | Robusto, flexible, confiable                | Mayor complejidad, overhead                |
| **MODBUS** | Industrial                             | Maestro-Esclavo                       | Serial, Ethernet                      | Baja a Alta                           | Hasta 247 (serial) / Ilimitado (Ethernet) | Automatización general, SCADA           | Simple a Media                      | No determinístico (típicamente)      | Limitada (serial) / Variable (Ethernet) | Ampliamente soportado, simple, bajo costo | Baja velocidad (serial), seguridad           |
| **PROFINET** | Industrial                             | Maestro-Esclavo, Peer-to-Peer         | Ethernet                              | Alta                                  | Prácticamente ilimitado                 | Automatización de fábricas, control de movimiento | Compleja                            | Determinístico (con IRT)            | Amplias opciones                       | Alto rendimiento, integración IT, robusto    | Mayor complejidad, costo                   |
| **CANopen** | Industrial                             | Maestro-Esclavo, Peer-to-Peer         | CAN Bus                               | Baja a Media                          | Hasta 127                               | Control de maquinaria, robótica         | Media                               | Determinístico (configurable)       | Depende de la implementación         | Robusto para entornos distribuidos         | Complejidad de configuración              |
| **PROFIBUS-DP/PA** | Industrial                             | Maestro-Esclavo                       | Serial (RS-485), Bucle de corriente    | Baja a Media                          | Hasta 126 (DP)                            | Automatización de fábricas y procesos   | Media                               | Determinístico (con extensiones)      | Depende de la implementación         | Amplia base instalada, versátil          | Requiere terminación, sensibilidad al ruido (DP) |