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

CoAP es más adecuado para dispositivos que requieren el mecanismo de suspensión /
activación en escenarios de IoT. El dispositivo puede permanecer en modo de hibernación
durante largos períodos de tiempo, lo que ahorra energía de la batería, y una sola batería puede durar 10 años o más. Actualmente, soluciones como medidores de agua inteligentes,
medidores de electricidad inteligente, agricultura inteligente y estacionamiento inteligente
utilizan el protocolo CoAP.

**Un ejemplo básico de cómo usar COAP en un escenario de IoT:**
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
