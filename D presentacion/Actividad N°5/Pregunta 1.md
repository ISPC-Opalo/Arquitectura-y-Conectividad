![Carátula](../../E%20assets/caratula.png)

# ¿Qué es un protocolo COAP?
El protocolo **COAP (Constrained Application Protocol)** es un protocolo de aplicación
diseñado para entornos con recursos limitados, como dispositivos IoT y redes de
sensores. COAP se utiliza para facilitar la comunicación entre estos dispositivos y las
aplicaciones que los controlan.

COAP se basa en la arquitectura cliente-servidor y utiliza el protocolo de transferencia de
hipertexto (HTTP) para habilitar la comunicación entre dispositivos y aplicaciones. Este
protocolo se desarrolló como una alternativa ligera a HTTP, ya que HTTP estándar puede ser
demasiado complejo y pesado para dispositivos con limitaciones de recursos. COAP utiliza el
modelo de intercambio de mensajes basado en UDP (User Datagram Protocol) para
minimizar el tamaño del paquete y la sobrecarga de protocolo. También incluye mecanismos
de seguridad, como autenticación y encriptación, a través de la capa de transporte para
proteger la comunicación entre los dispositivos.

Características de CoAP
- El encabezado está comprimido, el formato del paquete es simple y el mensaje
puede ser muy corto. El mensaje CoAP más pequeño tiene solo cuatro bytes.
La capa de transporte utiliza el protocolo UDP para reducir los gastos
generales de la red y CoAP admite multidifusión.
- Para compensar la falta de fiabilidad de la transmisión UDP, CoAP tiene un
mecanismo de retransmisión de mensajes.
- CoAP no admite la conexión persistente y no tiene mensajes de heartbeat.
Cuando no hay servicio, el dispositivo no necesita enviar mensajes a sistemas
externos.
- Rendimiento deficiente en tiempo real: el dispositivo debe activarse antes de
realizar los servicios.

### ¿Para qué se usa? 
CoAP se usa para que los dispositivos pequeños puedan comunicarse de manera eficiente en redes IoT.
Estos dispositivos suelen tener muy poca memoria, poco poder de procesamiento y, a veces, una conexión de internet débil o de baja velocidad. Entonces, necesitan un protocolo liviano y rápido como CoAP.

Ademas, CoAP es más adecuado para dispositivos que requieren el mecanismo de suspensión /
activación en escenarios de IoT. El dispositivo puede permanecer en modo de hibernación
durante largos períodos de tiempo, lo que ahorra energía de la batería, y una sola batería puede durar 10 años o más. Actualmente, soluciones como medidores de agua inteligentes,
medidores de electricidad inteligente, agricultura inteligente y estacionamiento inteligente
utilizan el protocolo CoAP.

### Ejemplo de cómo usar COAP en un escenario de IoT:
Supongamos que tienes un sistema de iluminación inteligente en tu hogar, donde cada luz es
un dispositivo IoT compatible con COAP y quieres controlar las luces desde tu teléfono
móvil.
- Configuración:
Configura cada luz con una dirección IP y un recurso identificador único, por
ejemplo, "coap://192.168.1.100/light".
Asegúrate de que tu teléfono móvil también esté conectado a la misma red.
- Descubrimiento de recursos:
Desde tu teléfono móvil, envía una solicitud de descubrimiento COAP a la dirección
de broadcast, utilizando el método GET y la opción de mensaje "Well-Known Core".
Recibirás una respuesta con los recursos disponibles en la red, incluyendo las
direcciones y los identificadores de las luces.
- Encendido de una luz:
Desde tu teléfono móvil, envía una solicitud COAP a la dirección de la luz específica,
utilizando el método PUT y el recurso identificador de la luz.
Incluye en el cuerpo del mensaje la información para encender la luz, por ejemplo,
{"state": "on"}.
La luz recibirá la solicitud y cambiará su estado a encendido.
- Apagado de una luz:
De manera similar al paso anterior, envía una solicitud COAP a la dirección de la luz
específica, utilizando el método PUT y el recurso identificador de la luz.
Incluye en el cuerpo del mensaje la información para apagar la luz, por ejemplo,
{"state": "off"}.
La luz recibirá la solicitud y cambiará su estado a apagado.

En este ejemplo, COAP se utiliza para enviar solicitudes y recibir respuestas entre tu
teléfono móvil y las luces del sistema de iluminación inteligente.

**Diagrama de sistema**


![Imagen](/../../blob/main/E%20assets/Cuestionario%20N5/P1img1.png)

![Imagen](/../../blob/main/E%20assets/Cuestionario%20N5/P1img2.png)

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
