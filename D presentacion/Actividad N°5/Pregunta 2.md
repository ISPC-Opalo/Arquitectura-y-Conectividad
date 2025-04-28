![Carátula](../../E%20assets/caratula.png)

# Protocolo AMQP (Advanced Message Queuing Protocol)

## ¿Qué es AMQP?

El *Advanced Message Queuing Protocol (AMQP)* es un protocolo de comunicación abierto, estándar y orientado a mensajes. Fue diseñado para sistemas de mensajería empresarial, garantizando la interoperabilidad entre diferentes tecnologías y permitiendo el intercambio confiable de mensajes entre aplicaciones distribuidas.

AMQP es utilizado en arquitecturas basadas en microservicios, sistemas de procesamiento distribuido, y aplicaciones que requieren una alta confiabilidad y flexibilidad en la comunicación.

---

## ¿Cómo funciona AMQP?

AMQP opera bajo un modelo cliente-servidor, en el que:

### 1. *Componentes principales:*
   - *Productor (Producer):* Es la entidad que envía los mensajes al sistema de mensajería.
   - *Broker:* Es el intermediario que administra el enrutamiento y entrega de los mensajes. Ejemplos de brokers que implementan AMQP incluyen RabbitMQ y Apache ActiveMQ.
   - *Cola (Queue):* Es el destino donde se almacenan los mensajes antes de ser consumidos.
   - *Consumidor (Consumer):* Es la entidad que recibe y procesa los mensajes desde las colas.

### 2. *Flujo de trabajo:*
   1. *Publicación:* El productor envía mensajes al broker.
   2. *Enrutamiento:* El broker analiza las reglas configuradas (como exchanges y bindings) para determinar a qué cola se debe enviar el mensaje.
   3. *Almacenamiento:* El mensaje se coloca en la cola designada.
   4. *Consumo:* El consumidor extrae mensajes de la cola para procesarlos.

---

## Características clave de AMQP:

1. *Fiabilidad:* AMQP asegura que los mensajes lleguen a su destino y permite confirmaciones de entrega.
2. *Transacciones:* Soporte para transacciones de mensajes, asegurando integridad en operaciones críticas.
3. *Interoperabilidad:* Funciona en múltiples lenguajes de programación y plataformas.
4. *Modelo basado en cola:* Facilita el procesamiento asincrónico de mensajes.

---

## Uso práctico:
Supón que tienes un sistema de pedidos:
- *Productores:* Las aplicaciones que generan nuevos pedidos (como una app de compras).
- *Broker:* RabbitMQ distribuye los pedidos en colas específicas según el tipo de procesamiento necesario (facturación, envíos, etc.).
- *Consumidores:* Servicios que procesan los pedidos desde las colas, como un módulo de impresión de etiquetas de envío.

---
  **Diagrama AMQP**
  
![Texto alternativo](https://github.com/ISPC-Opalo/Arquitectura-y-Conectividad/blob/83ed8168dc76233546056241e0e044ddb710662c/E%20assets/Cuestionario%20N5/P2img1.png)


---

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
