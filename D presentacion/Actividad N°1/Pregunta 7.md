![Carátula](../../E%20assets/caratula.png)

# TECNICATURA SUPERIOR EN TELECOMUNICACIONES  

## ¿Qué es la comunicación de datos en paralelo?  
##  Describa su funcionamiento.

### ¿Qué es la comunicación de datos en paralelo?

La **comunicación de datos en paralelo** es un método de transmisión de información en el que **varios bits de datos se envían simultáneamente** a través de múltiples líneas o canales físicos, uno por cada bit. A diferencia de la comunicación serial (que transmite un bit por vez), en paralelo se envían varios bits al mismo tiempo, lo que puede aumentar significativamente la velocidad de transmisión, aunque a costa de complejidad en el hardware.  

### Componentes clave:

1.  **Líneas de datos *(Data lines)*:**  
    Cada línea transporta un bit. Por ejemplo, para transmitir 8 bits (1 byte), se necesitan 8 líneas de datos: D0 a D7.
    
2.  **Línea de reloj *(Clock line)* [opcional]:**  
    Sincroniza el envío y la lectura de datos entre el emisor y el receptor. Si no se usa, puede haber otra señal de control como _strobe_.
    
3.  **Señales de control:**
    
    -   **STROBE:** Indica al receptor que los datos están listos para ser leídos.
        
    -   **ACK (Acknowledgement):** El receptor responde cuando los datos se han recibido correctamente.
        
    -   **BUSY:** Indica que el receptor aún no está listo para recibir nuevos datos.
  
  ### ¿Cómo es su funcionamiento?

Supongamos que queremos enviar un byte (8 bits) desde un dispositivo A a un dispositivo B:

-   En comunicación **paralela**, se usan **8 líneas de datos**, una para cada bit.
    
-   Todos los bits del byte se transmiten al mismo tiempo, sincronizados por una señal de **reloj** o una señal de control adicional (como _strobe_ o _handshake_).
    
-   Además de las líneas de datos, puede haber otras líneas auxiliares para **control de flujo**, **confirmación de recepción** o sincronización.

[Click para ampliar información.](https://ceptelematica.blogspot.com/2010/10/transmision-serie-y-paralela.html)

![Comunicación en parelelo](https://pc-solucion.es/wp-content/uploads/2018/04/paralelo.png)

## Tabla comparativa SERIE/PARALELO

![Tabla comparativa Serie/Paralelo](https://pc-solucion.es/wp-content/uploads/2018/04/comparativa-entre-transmision-de-datos-serie-y-paralelo.jpg)


## Ventajas y desventajas de la comunicación en paralelo:
### 🧠 Ventajas

-   ✅ Mayor **velocidad de transmisión** para distancias cortas.
    
-   ✅ Simple de implementar en entornos donde el espacio físico y el ruido no son un problema (como dentro de un microcontrolador o entre componentes en una placa).
    

----------

### ⚠️ Desventajas

-   ❌ Requiere **más cables o pistas** físicas (más costoso y complejo en hardware).
    
-   ❌ Problemas de **desincronización** o **interferencias** cuando las líneas son largas (efecto skew).
    
-   ❌ No es ideal para **distancias largas**, como entre nodos IoT distribuidos.
    

----------

## 📡 Aplicación en Internet de las cosas (IoT):

En el contexto de **IoT** *(Internet of things)* por sus siglas en inglés, la comunicación paralela **no es común entre nodos IoT** distribuidos, ya que estos suelen usar **comunicación serial** (UART, SPI, I2C) o protocolos inalámbricos (Wi-Fi, BLE, Zigbee, LoRa, etc.) para minimizar el cableado y ahorrar energía.

Sin embargo, **sí se puede usar internamente** en una PCB IoT, por ejemplo:

-   Entre un microcontrolador y una pantalla LCD.
    
-   Entre un microcontrolador y una memoria paralela.
    
-   En buses de expansión internos.  
___

###  ¿Dónde se usa esta lógica?

Este modelo se ve, por ejemplo, en la **interfaz de puerto paralelo** tradicional (como las impresoras antiguas con conector DB-25), y también en dispositivos embebidos que usan **LCDs de 8 bits**, **memorias RAM antiguas**, **buses de expansión**, etc.

![Conexión en paralelo impresora](https://pc-solucion.es/wp-content/uploads/2018/04/paralelo.jpg)

