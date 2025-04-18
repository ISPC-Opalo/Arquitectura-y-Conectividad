![Carátula](../../E%20assets/caratula.png)

# **Encendido de luces por detección de movimiento usando el protocolo MQTT.**

Comunicación entre el sensor de movimiento y las luces.
Cuando el sensor de movimiento, ubicado en el pasillo, detecta la presencia de una persona, actúa como cliente MQTT y se comporta como publicador. Este sensor establece una conexión con el broker MQTT a través de una conexión TCP/IP.

## **Establecimiento de la conexión**
Para conectarse, el cliente envía un mensaje CONNECT, que contiene:

- client-id (identificador del cliente),

- nombre de usuario y contraseña (si el broker lo requiere).

El broker responde con un mensaje CONNACK, indicando si la conexión fue aceptada o rechazada.

Por defecto, MQTT utiliza el puerto 1883 para conexiones sin cifrado.

## **Publicación del mensaje**
Una vez establecida la conexión, el sensor de movimiento envía un mensaje PUBLISH que incluye:

- Un topic o tema, por ejemplo: pasillo/movimiento.

- Un payload o contenido del mensaje, por ejemplo: "ON" para indicar que se detectó movimiento.

El broker recibe ese mensaje y aplica un filtrado por topic para identificar qué clientes están suscritos a ese tema y reenviarles el contenido.

## **Recepción y acción de las luces**
Las luces del pasillo, también configuradas como clientes MQTT, enviaron previamente un mensaje SUBSCRIBE al broker, indicando su interés en recibir mensajes del topic pasillo/movimiento.

Cuando el broker recibe un mensaje con ese topic (por ejemplo, "ON"), lo reenvía automáticamente a todas las luces que están suscritas. Al recibir el mensaje, las luces ejecutan la acción previamente programada: encenderse.

## **Rol del broker**
El broker MQTT cumple un rol central en este sistema. Se encarga de:

- Recibir los mensajes publicados por los clientes.

- Filtrar los mensajes según el topic.

- Reenviar los mensajes solo a los clientes que estén suscritos al topic correspondiente.

Este diseño desacopla completamente los dispositivos emisores de los receptores, brindando flexibilidad y escalabilidad al sistema.
