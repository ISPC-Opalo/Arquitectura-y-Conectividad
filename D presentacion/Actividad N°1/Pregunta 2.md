![Carátula](../../E%20assets/caratula.png)

# TECNICATURA SUPERIOR EN TELECOMUNICACIONES

## Comunicación de los dispositivos IoT

Los dispositivos de la Internet de las Cosas (IoT) utilizan diversas tecnologías de comunicación. La elección correcta depende siempre de las necesidades específicas de la aplicación, del tipo de dispositivo, su uso y el entorno en el que opera.


### Tipos de conectividad: física o inalámbrica

Los dispositivos IoT se conectan utilizando distintos tipos de redes, tanto inalámbricas como por cable:

#### Redes inalámbricas

- **Wi-Fi**: Muy común en entornos domésticos y comerciales, ofrece alta velocidad pero con consumo energético elevado. Opera en las bandas de frecuencia de 2,4 GHz y 5 GHz, y la más reciente, la banda de 6 GHz.
- **Bluetooth**: Ideal para comunicaciones de corto alcance y bajo consumo, usado en dispositivos personales y wearables.
- **Zigbee**: Protocolo inalámbrico de bajo consumo y baja tasa de transferencia de datos, usado en domótica y sensores.
- **Z-Wave**: Similar a Zigbee, utilizado principalmente en automatización del hogar.
- **LoRa**: Representa la capa física de la red que dicta las frecuencias de trabajo con las que se obtienen largas distancias y muy bajo consumo, ideal para zonas rurales o aplicaciones de monitoreo ambiental.
- **Sigfox**: Es una red de IoT pensada para tener un bajo consumo y ser independiente de los despliegues de telefonía, usada en sensores remotos donde se transmiten pocos datos.

#### Redes celulares

- **3G, 4G y 5G**: Tecnologías celulares tradicionales que permiten conectividad móvil de alta cobertura y velocidad.
- **NB-IoT (Narrowband IoT)**: Diseñada específicamente para dispositivos IoT que requieren poca energía y buena penetración en interiores.
- **LTE-M (Long Term Evolution for Machines)**: Similar al NB-IoT, pero con mayor velocidad y soporte de movilidad, ideal para dispositivos en movimiento.

#### Comunicación por cable

- **Ethernet**: Proporciona conexión estable y de alta velocidad, usada en entornos industriales o cuando no se requiere movilidad.
- **RS-485**: Estándar usado en entornos industriales para comunicación en serie entre dispositivos.


### Protocolos de comunicación

Además de las tecnologías de conectividad, los dispositivos IoT emplean diversos **protocolos de transmisión de datos**, que definen cómo los dispositivos intercambian información de manera eficiente y segura:

- **MQTT (Message Queuing Telemetry Transport)**: Ligero y eficiente, ideal para IoT con conexiones inestables o limitadas.
- **CoAP (Constrained Application Protocol)**: Similar a HTTP, pero optimizado para dispositivos con recursos limitados.
- **AMQP (Advanced Message Queuing Protocol)**: Protocolo confiable y orientado a mensajes, útil en aplicaciones críticas que requieren entrega garantizada.
- **HTTP/HTTPS**: Utilizado en dispositivos que requieren comunicación con servidores web, aunque con mayor carga de datos.
- **LoRaWAN**: Es un protocolo de red que usa la tecnología LoRa, para redes de baja potencia y área amplia, LPWAN (Low Power Wide Area Network) empleado para comunicar y administrar dispositivos LoRa. El protocolo LoRaWAN se compone de gateways y nodos.
- **NB-IoT y LTE-M**: Protocolos celulares diseñados para comunicación eficiente, segura y de gran cobertura.
- **Bluetooth Low Energy (BLE)**: Protocolo optimizado para dispositivos con batería, como relojes inteligentes o sensores de salud.
- **Zigbee y Z-Wave**: Muy usados en domótica, permiten la creación de redes de dispositivos interconectados.


### Arquitectura de comunicación IoT

La comunicación en IoT sigue una arquitectura que involucra varios componentes:

- **Dispositivos IoT**: Sensores, actuadores y dispositivos inteligentes que capturan datos o ejecutan acciones.
- **Pasarelas IoT (Gateways)**: Traducen y retransmiten información entre redes locales y la nube.
- **Servidores en la nube**: Gestionan la transmisión y almacenamiento de datos.
- **Aplicaciones en la nube**: Procesan los datos y los presentan a los usuarios finales.
- **Interfaz de usuario**: Medio por el cual los usuarios visualizan la información y controlan los dispositivos (apps móviles, web, etc.).


### Modelos de comunicación en IoT

Los dispositivos IoT pueden comunicarse siguiendo distintos modelos:

- **Dispositivo a Dispositivo**: Comunicación directa entre dispositivos sin intermediarios, usando protocolos como Bluetooth o Zigbee.
- **Dispositivo a Nube (Device-to-Cloud)**: Los dispositivos envían datos directamente a servicios en la nube para su procesamiento y almacenamiento, común en aplicaciones de monitoreo remoto.
- **Dispositivo a Puerta de Enlace (Gateway)**: Los dispositivos se conectan a través de una puerta de enlace que facilita la comunicación con la nube o con otros dispositivos.
- **Intercambio de Datos a través del Back-End**: Permite que los datos recopilados por los dispositivos sean analizados y combinados con otras fuentes de información en la nube, enriqueciendo la toma de decisiones.


### Esquema de comunicación en IoT

La comunicación entre dispositivos IoT se puede representar en varias etapas:

1. **Dispositivos y Sensores**: Capturan datos del entorno (temperatura, humedad, movimiento, etc.).
2. **Conectividad**: Transmiten esos datos mediante tecnologías como Wi-Fi, Bluetooth, Zigbee, LoRaWAN o redes móviles (4G/5G).
3. **Puerta de Enlace (Gateway)**: Recoge los datos y los envía a la nube o a servidores locales.
4. **Plataforma en la Nube o Servidor**: Almacena y procesa los datos recibidos.
5. **Aplicaciones y Usuarios**: Los usuarios acceden a la información procesada a través de aplicaciones móviles o web, pudiendo controlar dispositivos y tomar decisiones.

<img src="../../E assets/Cuestionario N1/p2img1.png" />


### Ejemplo: Lámparas inteligentes en un hogar IoT

- La lámpara inteligente se conecta a la red Wi-Fi del hogar o a un hub central mediante Zigbee o Bluetooth.
- Este hub (o directamente la lámpara, si tiene Wi-Fi) se conecta a la nube del fabricante.
- El usuario interactúa desde su smartphone o asistente de voz para dar órdenes como “apagar todas las luces del dormitorio”.
- La aplicación móvil envía la orden a través de Internet, que es redirigida por los servidores del fabricante hacia la lámpara.
- La lámpara ejecuta la orden y puede enviar una confirmación del estado (por ejemplo, "apagada").

<img src="../../E assets/Cuestionario N1/p2img2.png" />


