![Carátula](../../E%20assets/caratula.png)

## 5- ¿Qué es un protocolo PROFINET?, ¿Para qué se usa? Ejemplifique 

**PROFINE** (Process Field Network) es un estándar abierto de comunicación industrial basado en Ethernet industrial, Este mismo se desarrollado por la organización PROFIBUS & PROFINET International (PI). este cambio representa una evolución significativa de los protocolos de campo tradicionales hacia la conectividad Ethernet moderna..


## Características fundamentales de PROFINET:


**Comunicación basada en Ethernet:** Utiliza la infraestructura Ethernet estándar pero con adaptaciones para entornos industriales.

**Comunicación en tiempo real:** esta ofrece tres niveles de rendimiento:

- TCP/IP estándar (NRT - Non-Real-Time): Para tareas sin requisitos temporales estrictos
- Tiempo real (RT - Real-Time): Para aplicaciones con tiempos de ciclo de 1-10 ms
- Tiempo real isócrono (IRT - Isochronous Real-Time): Para aplicaciones de alta precision con tiempos de ciclo inferiores a 1 ms

**Arquitectura flexible:** esta permite topologías en estrella, árbol, anillo o línea.
**Diagnóstico integrado:** tiene capacidades avanzadas para detección y resolución de problemas.

## Usos principales de PROFINET

**PROFINET**  se utiliza principalmente para:

**Automatización industrial:** Para conectar controladores (PLCs), dispositivos de campo, HMIs y otros componentes.
**Control de procesos:** En industrias como manufactura, automotriz, farmacéutica, alimentaria y química.
**control de movieiento:** Para aplicaciones que requieren sincronización precisa de movimientos.
**integración vertical:** Permite la comunicación desde el nivel de campo hasta el nivel empresarial.
**Industria 4.0:** Facilita la implementación de fábricas inteligentes y digitalización industrial.

## Ejemplos prácticos de implementación

### Línea de producción automotriz

En una línea de ensamblaje automotriz, **PROFINET** conecta:

- PLCs que controlan diferentes estaciones de trabajo
- Robots de soldadura y ensamblaje
- Sistemas de visión para control de calidad
- Sensores y actuadores distribuidos
- HMIs para supervisión del proceso

## Componentes de PROFINET
PROFINET clasifica los dispositivos en tres tipos: controladores, dispositivos y supervisores.

- Los **controladores** son dispositivos que ejecutan un programa de automatización e intercambian datos con los dispositivos.
- Los **dispositivos** son sensores/actuadores conectados al controlador a través de Ethernet.
- Los **supervisores** son un HMI, un PC u otros dispositivos de puesta en marcha, monitoreo o análisis de diagnóstico.

## Diagrama Básico de PROFINET

![Imagen](/../../blob/main/E%20assets/Cuestionario%20N5/P5img1.png)

