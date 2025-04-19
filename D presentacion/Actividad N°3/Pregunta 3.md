![Carátula](../../E%20assets/caratula.png)

# Seguridad en MQTT

La seguridad en MQTT es crucial debido a su uso en sistemas IoT donde se transmiten datos sensibles. Aunque MQTT es un protocolo ligero y eficiente, que no tiene seguridad integrada, por lo que debe complementarse con medidas externas y practicas:

##  Manejo de la seguridad en MQTT

### 1.Autenticación

- **Autenticación:** Esto garantiza que solo dispositivos autorizados puedan conectarse al broker.
- **Implemantacion:** Encriptación, Autenticación basada en tokens para mayor seguridad.

```
Un broker MQTT puede requerir que cada dispositivo IoT se autentique con un nombre de usuario y contraseña antes de publicar o suscribirse.  
```
## 2.Encriptación

- **Datos:** Controla qué dispositivos o usuarios tienen permiso para acceder a temas específicos.
- **Implemantacion:** Listas de control de acceso (ACLs) que definen permisos por usuario o dispositivo
```
Configurar el broker para usar mqtts:// en lugar de mqtt://, asegurando la conexión mediante TLS.

```
## 3.Autorización

- **Datos:** Protege los datos durante la transmisión para evitar que sean interceptados.
- **Implemantacion:** Uso de TLS (Transport Layer Security) para cifrar la conexión entre cliente y broker, Certificados digitales para verificar la identidad del broker y del cliente

```

Un LDR IoT puede publicar datos en el tema casa/LDR, pero solo dispositivos específicos pueden suscribirse.

```

## 4.Prevención de ataques

- **Datos:** Protege contra amenazas como ataques de denegación de servicio (DoS).
- **Implemantacion:** Límites en la tasa de conexiones, Uso de firewalls para restringir acceso no autorizado al broker.

```

Configurar el broker para limitar la cantidad de mensajes por segundo que un dispositivo puede enviar.

```

##  Manejo de la seguridad en MQTT.

### Prácticas de seguridad en MQTT:
*** Utilizar TLS (Transport Layer Security): *** 
- Cifra las comunicaciones entre dispositivos y el broker.
- Asegúrate de usar certificados confiables para evitar ataques de intermediarios.

*** Autenticación robusta: *** 
- Requiere credenciales únicas para cada dispositivo o usuario.
- Implementa autenticación basada en certificados para mayor seguridad.

*** Configurar ACLs (Listas de Control de Acceso): *** 
- Define qué dispositivos pueden publicar o suscribirse a temas específicos.
- Evita que dispositivos no autorizados accedan a datos sensibles.

***  Evitar credenciales en texto plano: *** 
- No almacenes nombres de usuario y contraseñas en texto plano en el dispositivo.
- Utiliza técnicas de hash para proteger credenciales almacenadas.

***  Limitar permisos y accesos: *** 
- Aplica el principio de privilegio mínimo, permitiendo que cada dispositivo acceda solo a los temas necesarios.
- Por ejemplo, un dispositivo IoT agrícola solo necesita datos del tema campo/sensores.

***  Monitoreo y auditoría: *** 
- Habilita el registro de eventos en el broker MQTT.
- Monitorea intentos fallidos de conexión para detectar posibles amenazas.

***  Uso de QoS adecuado: *** 
- Ajusta el nivel de calidad de servicio (QoS) según la importancia de los datos.
- Para datos críticos, utiliza QoS 2, que garantiza entrega exacta.






