## ¿Cuáles son las ventajas de usar MQTT frente a otros protocolos de comunicación IoT?
### ¿Qué es MQTT?
MQTT **(Message Queuing Telemetry Transport)** es uno de los protocolos de comunicación más populares en el ámbito del Internet de las Cosas (IoT), y ha ganado reconocimiento por su eficiencia, simplicidad y bajo consumo de recursos. Se trata de un protocolo de mensajería ligero basado en el modelo publicador/suscriptor, que funciona sobre TCP/IP y fue diseñado para conexiones remotas con dispositivos de recursos limitados y redes de baja calidad o alta latencia.

### Ventajas frente a otros protocolos:
1. **Eficiencia en el uso del ancho de banda**
	- MQTT utiliza paquetes muy livianos, con encabezados mínimos de solo 2 bytes, lo cual lo hace ideal para redes con poco ancho de banda, como las redes móviles o redes de sensores.
	- A diferencia de HTTP, que es más pesado y requiere una conexión continua entre cliente y servidor, MQTT permite ahorrar datos y recursos en cada transmisión.
	
2. **Bajo consumo de energía**
	- Los dispositivos IoT suelen estar alimentados por baterías, y MQTT está optimizado para minimizar el uso de energía.
	- Permite que el dispositivo se conecte, envíe o reciba mensajes y se vuelva a dormir rápidamente, lo cual extiende la vida útil de la batería, en comparación con protocolos como HTTP que requieren mantener la conexión abierta más tiempo.

3. **Modelo publish/subscribe *(publicador/suscriptor)***
	- Este modelo permite una comunicación desacoplada, es decir, el emisor (publicador) y el receptor (suscriptor) no necesitan conocerse ni mantenerse conectados entre sí directamente.
	- Esto reduce la complejidad de los dispositivos y mejora la escalabilidad del sistema. Esto es especialmente útil cuando hay muchos dispositivos conectados.

4. **Mecanismo de calidad de servicio *(QoS)***  
	MQTT permite elegir entre tres niveles de QoS según la importancia del mensaje:
	- **QoS 0:** El mensaje se entrega una vez como máximo (sin garantía de entrega).
	- **QoS 1:** El mensaje se entrega al menos una vez.
	- **QoS 2:** El mensaje se entrega exactamente una vez (máxima garantía).
	
	Esta flexibilidad permite ajustar el comportamiento según las necesidades de cada aplicación IoT.

5. **Persistencia y Retención de mensajes**
	- MQTT permite retener mensajes en el broker para que los nuevos suscriptores reciban la información más reciente inmediatamente al conectarse.
	- También puede almacenar mensajes offline, lo cual es ideal cuando un dispositivo pierde conexión y necesita recibir los datos que se enviaron mientras estuvo desconectado.

6. **Soporte para conexiones inestables**
	- MQTT fue diseñado para entornos con conexiones poco fiables o intermitentes, como redes móviles o rurales.
	- El protocolo puede mantener la sesión del cliente, permitiendo la reconexión automática y la recuperación de mensajes perdidos.

7. **Escalabilidad y simplicidad**
	- Es fácil de implementar y escalar a miles de dispositivos sin aumentar mucho la carga del sistema.
	- A diferencia de otros protocolos como AMQP, que son más robustos pero también más complejos, MQTT ofrece un equilibrio ideal entre simplicidad y funcionalidad para la mayoría de las aplicaciones IoT.

8. **Seguridad (Depende de la implementación)**
	- Aunque MQTT por sí solo no incluye cifrado, se puede integrar fácilmente con TLS/SSL para proteger los datos en tránsito.
	- Además, permite autenticación mediante usuario y contraseña, lo cual puede ser suficiente en sistemas controlados o cerrados.

9. **Compatibilidad con múltiples plataformas y lenguajes**
	- Hay clientes MQTT para prácticamente todos los lenguajes de programación (Python, C/C++, JavaScript, Java, etc.) y sistemas operativos, incluyendo microcontroladores como ESP32 o Arduino.

### Tabla comparativa de diferentes protocolos

| **Protocolo** | **Modelo**            | **Peso** | **QoS**       | **Recomendado para...**                    |
|---------------|-----------------------|----------|---------------|--------------------------------------------|
| MQTT          | Pub/Sub               | Muy bajo | Sí            | Sensores, IoT con bajo consumo.            |
| HTTP          | Cliente/Servidor      | Alto     | No            | Web apps, APIs tradicionales.              |
| CoAP          | Cliente/Servidor(UDP) | Muy bajo | Sí (limitado) | Redes muy restringidas, sensores pequeños. |
| AMQP          | Pub/Sub               | Alto     | Sí (avanzado) | Aplicaciones críticas, banca, industria.   |
| WebSocket     | Bidireccional         | Medio    | No            | Apps en tiempo real, web/chat.             |