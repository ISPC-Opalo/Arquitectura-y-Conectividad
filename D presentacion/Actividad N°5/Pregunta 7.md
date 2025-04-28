## 7- ¿Qué es un protocolo PROFIBUS-DP/PA?, ¿Para qué se usa? Ejemplifique 

**PROFIBUS** corresponde a un acronimo de Process Field Bus. Un estandar de comunicacion utilizado en automatizacion, comun en entornos industriales. Entas estrcuturas de conexion cuentan con sensores/actuadores conectado a una sala de controldonde se reciben los datos, y son gestionados via un Controlador Logico Programable (PLC) Este se encuentra definido en la norma  (IEC 61158).
Si imaginamos que dentro de un entorno industrial donde se requieren no solo una enorme cantidad de sensores/actuadores, sino que estos se despliegan a lo largo de grandes distancias, se desarrolo un protocolo para optimizar la comunacion de los mismos via nodos de I/O (entrada y salida de informacion) que se encuentren mas proximos a los diferentes puntos de sensorizacion. Y que luego mediant un unico cable bus (**RS-485**) conectan con el PLC. Estos nodos funcionan como **Perifericos Desentralizados (DP)** De esta forma se reduce drasticamente la cantidad de cable en el espacio fisico.

<img src="../../E assets/Cuestionario N5/P7Img1.png" alt="DP"
     width="400"
     style="margin-left: 20px; margin-top: 15px;" />


Como evolucion del protoloco PROFIBUS-DP. A fin de mejor el rendimientdo y economia del sistema, se utiliza un cable bus al que se conectaran todos los sensores/actuadores. Luego ese table bus dirigira hacia un acoplador direccional. Que luego conecta con el PCL medianta el protocolo **PROFIBUS-DP**. Los datos desde los sensores hasta el acoplador se realiza mediante el protocolo **PROFIBUS-PA**.

Ejemplo de un acoplador direccional

<img src="../../E assets/Cuestionario N5/P7Img2.png" alt="DP"
     height="250"
     style="margin-left: 20px; margin-top: 15px;" />

Ejemplo de estrcutura red del protocolo **PROFIBUS-PA**.

<img src="../../E assets/Cuestionario N5/P7Img3.png" alt="DP"
     width="400"
     style="margin-left: 20px; margin-top: 15px;" />

### Arquitectura y relacioncon la capa OSI:
capas 3–6 no se utilizan

**Capa 1: Física**
- DP: RS-485 diferencial, hasta 12 Mbps.
- PA: MBP (Manchester Bus Powered), 31.25 kbps, alimentación sobre el par de datos, apto para zonas peligrosas

**Capa 2: Enlace de datos**
-  Gestión de acceso al medio (token/bus)
-  Control de errores (FCS de 16 bits)
-  Formatos de trama (maestro a esclavo, esclavo a maestro, broadcast)

**Capa 7	Aplicación**
- PROFIBUS-DP V0/V1/V2: intercambio de datos cíclicos, diagnóstico, alarmas y acoplamiento de bloques de datos grandes

**PROFIBUS-DP**
- Velocidad: 9.6 kbps a 12 Mbps (configurable por segmento).4
- Topología: Línea principal (bus line) con terminadores en ambos extremos; repetidores para segmentar.
- Máster–Esclavo: Uno o varios maestros (PLC), hasta 126 nodos esclavos.
- Ciclicidad:
    - DP-V0: Sólo datos de proceso cíclicos.
    - DP-V1: Añade servicios acíclicos (diagnóstico remoto, parametrización).
    - DP-V2: Transferencia de bloques de datos largos, acoplamiento maestros.
- Formato tipoco de un "Telegrama" **[BREAK][SYNC][START][ADDR][CT][DATA…][FCS]**
    - BREAK: ≥ 33 µs de nivel “marcado” (1) para reiniciar el receptor.
    - SYNC: 1 byte “0xA5” para sincronizar reloj.
    - START: 1 byte que indica formato (por ejemplo 0x10 = acceso maestro a esclavo).
    - ADDR: Nodo destino (0 = broadcast, 1–125 esclavos, 126 maestro).
    - CT: Código de control (p.ej. número de bytes de datos).
    - DATA: Payload (p.ej. salidas digitales o entradas analógicas).
    - FCS: CRC-16 (polinomio x¹⁶ + x¹² + x⁵ + 1).

**Ejemplo de uso**
En una línea de montaje automotriz, un PLC maestro envía cada 2 ms valores de salida al módulo de E/S distribuida (esclavo) para:
- Activar solenoides de colocación de tornillos.
- Leer estados de detectores de presencia.
- Si falla un módulo, el PLC detecta el error gracias al diagnóstico cíclico (DP-V1) y genera una alarma en el HMI.

**PROFIBUS-PA**
- Velocidad: 31.25 kbps (Manchester bit-coding).
- Alimentación sobre bus: El mismo par de cables transporta datos y hasta 320 mA de alimentación.
- Intrínsecamente seguro: Permite instalación en zonas explosivas (ATEX).
- Topología: Topología en línea o en árbol con segmentos max. de 1900 m; repetidores galvánicos para separación.
- Integración con DP: Se usa un acoplador DP/PA para conectar segmentos PA (campo) a un bus DP (PLC).

**Ejemplo de uso**
En una planta química, se instalan transmisores de presión y temperatura en reactores:
- Cada transmisor PA envía mediciones cada 200 ms a la estación de control.
- El bus, intrínsecamente seguro, circula por zonas con atmósfera explosiva.

