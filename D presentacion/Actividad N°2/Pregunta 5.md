## **¿Cómo se aplica las modulaciones digitales ASK, FSK y PSK en sistema IoT?** 

Las modulaciones digitales constan en el procesamiento de algunos parámetros de una onda portadora en función a otra señal conocida generalmente como onda moduladora la cual es una señal digital binaria (de “1” y “0”) que porta la información, para que la misma sea transmitida por un canal. Dentro de este tipo de modulaciones se pueden considerar entre las más resaltantes ASK, FSK y PSK para los sistemas de comunicación digitales.

### Ejemplo:


## Modulacion de Desplazamiento de Amplitud (ASK)

La modulación ASK, se basa en representar variaciones de amplitud inmersos en una secuencia de datos digitales como variaciones de amplitud en una onda portadora. En otras palabras, la alternancia de amplitud de la señal portadora dependerá directamente de los niveles de amplitud de la señal a modular manteniendo la frecuencia y la fase constante. Las variaciones de amplitud es usada para representar valores binario de “0” y “1”, de esta manera se puede representar la señal portadora como un interruptor ON/OFF.

### Ejemplo de modulación de ASK:


### Esquema de modulador ASK:

El circuito consta de un interruptor el cual dependiendo de la información de la señal a modular (“1” y “0”) elige la portadora correspondiente para ese valor.

## Modulacion de Desplazamiento de Frecuencia (FSK)

El bloque del modulador consiste básicamente en una señal binaria entrante y un sub-sistema selector que escoge entre dos señales portadoras de la misma amplitud pero con diferente frecuencia, si la señal digital entrante es un “1” lógico, este mostrara una mayor frecuencia, si es un “0” la frecuencia será menor. Correspondiendo el bloque modulador a la siguiente imagen.

### Ejemplo de modulación FSK:


Las portadoras poseen diferentes frecuencias como se aprecian en la siguiente figura, obteniendo como resultado la señal modulada dependiendo del tren de datos a modular.

### Esquema de modulador FSK:

## Modulacion de Desplazamiento de Fase (PSK)

Este tipo de modulación se caracteriza por variar la fase de la señal portadora dependiendo de la amplitud de la señal a modular, resultando una modulación en fase. A diferencia a la modulación ASK, la señal portadora mantiene una amplitud constante y variaciones en la fase entre 0º para un “0” lógico y 180º para cuando se presente un “1” lógico.

### Ejemplo de modulación PSK:

### Esquema de modulador PSK: