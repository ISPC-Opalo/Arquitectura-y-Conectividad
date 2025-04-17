**Implementar un Prototipo del dispositivo  antes mencionado con ESP32  y conectarlo  a  un  Broker  mediante  Protocolo  MQTT,  visualizando  en Smartphone o Tablet. En su defecto controlar y comunicar 3 dispositivos, sensores y/o actuadores, mediante el protocolo mencionado. Pueden usar Arduino, pero necesitan el módulo de comunicación a internet. El lenguaje de programación es a su elección, Phyton, C++, etc.**

Se desarrolla un un sistema de 3 componenetes, que interactuan entre si, emulando un sistema de sensorizacion, alarma y reaccion.
Creamos un dispositivo que funcionara como el sensor del trio, simulado en Wokwu. Un dispo, en fisico que recibira y alamara cuando se cumplan ciertas condiciones, y un movil. Que mediante una app podra interaccuar con el sistema, y funcionara a modo de elemnto de reaccion

**Broker elegido:** test.mosquitto.org

**Topics**: - tempESP
            - AlarmaAltaTemperatura
________________________            

- **Dispositivo Sensor**. ESP32 simulado en wokwi, y corresponde simplemente a un ponteciometro que simulara cambios de temperatura. Emviara la informacion (temperatura) cada 5 segundos a todos los elementos subscriptos al topic que llamamos tempESP. Como el mensaje es informativo, y se envia cada cortos periodos, no es necesario asegurar la llegada del mensaje en cada envio, por lo que sale con QoS 0

<img src="../../E assets/Cuestionario N3/P5Img1.png" alt="Wokwi"
     width="300"
     style="margin-left: 20px; margin-top: 15px;" />

El codigo y estructura en directorio: **C prototipo\Actividad N°3\Medidor Temperatura - Simulacion Wokwi**

- **Dispositivo Alarma**. ESP32 fisico con 3 leds. Este emularia un sistema de alarmas regular ante una variacion. El led numero 1, encendera durante 1 segundo, cada vez que el dispositivo reciba una lectura correspondiente al topic tempESP. Cuando dicho valor rompa el umbral establecido de 45°C - encendera el led numero 2 por 3 segundos. En un sistema real, podemos equipararlo a una alarma de bajo nivel o advertencia. Y cuado el valor recibido corresponda a +65°C encendera led 3, en lugar de led 2. Ahora ademas enviando un mensaje de alerta al dispositivo movil. Como quisieramos que este mensaje llegue obligatoriamente, lo enviamos con una calidad QoS 2 al topic AlertaAltaTemperatura.

El codigo y estrcutura en e directorio: **C prototipo\Actividad N°3\Alarma Temperatura**

<img src="../../E assets/Cuestionario N3/P5Img2.png" alt="ESP32-fisico"
     width="300"
     style="margin-left: 20px; margin-top: 15px;" />

- **DIsposivito de Reaccion**. Este corresponde a una app del movil (IoT MQTT movil) que permite actuar y configurar gadgets con conexiones a canales, seguridad. calidad, etc. Este dispositivo estara con un gadget conectado al canal tempESP, recibiendo en tiempo real la informacion y estado de temperatura. Ante el mensaje de alarma recibido desde el Dispositivo Alarma (visible via un gadget log), se podra presionar un boton de emergencia. Que envia en QoS 2 un mensaje de "reset" al Disposivito Sensor, mediante el topic AlertaAltaTemperatura, reseteando el valor de temperatura a 0. Emulando lo que podria ser un la reaccon de un operario o sistema automatizado.

<img src="../../E assets/Cuestionario N3/P5Img3.png" alt="App-Movil"
     width="300"
     style="margin-left: 20px; margin-top: 15px;" />

<img src="../../E assets/Cuestionario N3/P5Img4.png" alt="App-Movil"
     width="300"
     style="margin-left: 20px; margin-top: 15px;" />     