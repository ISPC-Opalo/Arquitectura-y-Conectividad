![Carátula](../../E%20assets/caratula.png)

# ¿Por qué es conveniente usar un broker en MQTT?

En el protocolo **MQTT**, el uso de un **broker** es fundamental para garantizar una comunicación eficiente, confiable y escalable entre dispositivos. El broker actúa como **intermediario** entre los dispositivos que **publican** información (como un sensor de movimiento) y los que **se suscriben** a esa información (como una luz, cámara o aplicación).

---

## 1. Desacoplamiento entre dispositivos

- Los dispositivos **no necesitan conocerse entre sí** ni establecer conexiones directas.
- El sensor simplemente **publica** su mensaje en un tema, y el broker lo **distribuye** a todos los dispositivos **suscritos**.
- Esto permite construir un sistema más **modular, flexible y escalable**.

---

## 2. Gestión centralizada y eficiente del tráfico

- El broker se encarga de **filtrar, enrutar y distribuir** los mensajes según los temas.
- Puede manejar **miles de dispositivos** conectados simultáneamente.
- Esto simplifica la arquitectura de red y mejora el **rendimiento general del sistema**.

---

## 3. Mayor confiabilidad y control

- El broker gestiona los **niveles de calidad de servicio (QoS)** y asegura que los mensajes se entreguen correctamente.
- Puede **almacenar mensajes retenidos** para que los nuevos suscriptores reciban el último estado conocido.
- Garantiza que **no se pierdan eventos importantes**, incluso si un dispositivo estaba desconectado temporalmente.

---

## Conclusión

El broker es un componente **clave** en MQTT porque:

- Centraliza la comunicación entre dispositivos.
- Mejora la **eficiencia y confiabilidad** del sistema.
- Permite una arquitectura de red más **ordenada, flexible y escalable**.

En sistemas de IoT como un sensor de movimiento que controla otros dispositivos, el broker permite que todo funcione de manera **coordinada y autónoma**.
