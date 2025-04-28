### 6- ¿Qué es un protocolo CANopen?, ¿Para qué se usa? Ejemplifique

CANopen es una especificación desarrollada por la agrupación CiA (CAN in Automation) sobre la base física y de enlace de datos del bus CAN clásico, ampliable a CAN FD. Diseñado para sistemas embebidos y de automatización con exigencias de determinismo, robustez y trazabilidad, define perfiles de comunicación y de dispositivo que permiten interoperabilidad entre nodos heterogéneos.

<img src="../../E assets/Cuestionario N5/P6Img1.png" alt="CANopen"
     width="400"
     style="margin-left: 20px; margin-top: 15px;" />

**Capas del modelo OSI que abarca**

- Capa física:  Utiliza CAN clásico (hasta 1 Mbit/s) o CAN FD (payload aumentada y tasas superiores).
- Capa de enlace de datos: Arbitraje por CSMA/CR (bitwise), bit‐stuffing, CRC de 15 bits, señal de AC
- Capa de aplicación (CiA 301):
    - Perfil de comunicación: Define los servicios (SDO, PDO, NMT, SYNC, Heartbeat, Emergency).
    - Perfiles de dispositivo (CiA 4xx): Estandariza la funcionalidad de diferentes tipos de nodos (E/S, drives, sensores).

Asi como otros protocolos de red industriales, se diseñan para hacer uso unicamente de las capas o elementos necesarios para la tarea concreta para la que estan desarrollados.

**Componentes Clave**

| Elemento                   | Descripción técnica                                                                                                     |
|----------------------------|-------------------------------------------------------------------------------------------------------------------------|
| Object Dictionary (OD)     | Estructura en memoria (índice–subíndice) que lista todos los parámetros (tipos y valores por defecto).                   |
| Service Data Object (SDO)  | Servicio acíclico para acceso a cualquier entrada del OD (lectura/escritura puntuales).                                 |
| Process Data Object (PDO)  | Intercambio de datos de proceso (hasta 8 bytes) en modo cíclico o acíclico, con baja latencia.                          |
| Network Management (NMT)   | Control de estados de nodo: Pre‐operational, Operational, Stopped; permite arranque/parada global.                      |
| Heartbeat & Life‐Guarding  | Publicación periódica (1–1000 ms) del “estoy vivo”; detección de fallos de nodo mediante timeout.                      |
| Emergency Messages         | Mensajes espontáneos ante errores críticos (2 bytes de código de fallo + datos contextuales).                           |

### Para que se utiliza?
- Automatización industrial
    - Control distribuido de ejes y servomotores.
    - Redes de E/S distribuidas en plantas y máquinas.
- Robótica
    - Sincronización de múltiples articulaciones usando SYNC y CSP (Cyclic Synchronous PDO).
- Vehículos especializados
    - Agricultura y construcción (CANopen FD para mayor throughput y trazabilidad).
- Edificios inteligentes y medicina
    - Control HVAC, iluminación, equipos clínicos con exigencias de disponibilidad y registro de fallos.

### Ejemplo Práctico: Red de Servomotores
Se considera un sistema con un PLC maestro y cinco servos (nodos 1–5):
1) Inicialización (SDO)
    - Escritura en OD de cada servo: límite de par (0x6072), offset de encoder (0x6000:0x01).
2) Intercambio de datos en tiempo real (PDO + SYNC)
    - RPDO1 (maestro→servo): consigna de posición (4 bytes) + modo operativo (1 byte).
    - TPDO1 (servo→maestro): posición real (4 bytes) + estado (1 byte).
    - El maestro envía SYNC cada 1 ms; tras recibirlo, cada nodo actualiza/envía su PDO.
3) Gestión de emergencias
    - Si un servo detecta sobretemperatura envía Emergency (0x3210); el maestro ejecuta NMT “Stopped” y activa alarmas.