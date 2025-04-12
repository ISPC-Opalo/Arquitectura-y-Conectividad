![Carátula](../../E%20assets/caratula.png)

# TECNICATURA SUPERIOR EN TELECOMUNICACIONES

## ¿Qué es el Protocolo HTTPS?  


**HTTPS** (HyperText Transfer Protocol Secure) es la **versión segura de HTTP**, el protocolo que utilizan los navegadores y servidores web para comunicarse. La “S” al final significa **“Secure”**, e indica que la comunicación entre el cliente (normalmente un navegador) y el servidor está **cifrada** usando **TLS (Transport Layer Security)** o su predecesor SSL.

## ¿Qué relación hay entre SSL y HTTPS?

Las URLs van precedidas del **HTTP (protocolo de transferencia de hipertexto)** o **HTTPS (protocolo de transferencia de hipertexto seguro)**. Estos protocolos determinan de manera efectiva cómo se transmiten los datos que envías y recibes.

Los sitios web sin certificado SSL funcionarán con HTTP y transferirán datos en texto plano, lo que significa que cualquiera en Internet puede interceptar y recuperar el mensaje.

Esto puede causar problemas si los datos transmitidos contienen información confidencial que los atacantes pueden utilizar para cometer ciberdelitos como la violación de datos, la ciberextorsión y el robo de identidad.

Cuando se instala un certificado SSL, este se configura para transmitir datos cifrados mediante HTTPS. Las dos tecnologías van de la mano: no se puede utilizar una sin la otra.

En resumen: **HTTPS protege la información que viaja entre el usuario y el sitio web.**

![HTTP vs HTTPS](https://www.hostinger.com/ar/tutoriales/wp-content/uploads/sites/38/2023/08/ES-what-are-the-differences-between-http-and-https-1.webp)
  
 Para mas información Click [AQUI](https://www.hostinger.com/ar/tutoriales/ssl-tls-https)
## ¿Cómo funciona HTTPS?

1.  **El cliente (navegador) inicia una conexión HTTPS** solicitando la conexión segura al servidor.
    
2.  El servidor responde con su **certificado digital**, emitido por una **Autoridad Certificadora (CA)** confiable.
    
3.  El cliente **verifica el certificado**, y si es válido, se inicia un **intercambio de claves** para establecer una conexión segura.
    
4.  A partir de ese momento, los datos se **transmiten cifrados** utilizando algoritmos como AES y RSA.
    
5.  Esto garantiza que **nadie más pueda leer ni modificar los datos** en tránsito.

Información adicional, pulsa [AQUI](https://es.semrush.com/blog/que-es-https/)  

![HTTPS vs HTTPS](https://static.semrush.com/blog/uploads/media/1a/17/1a17037b8efbf07292e1d8ea93bdfaaa/ES-HTTP-HTTPS.jpg)


## Características del protocolo HTTPS

### Características del protocolo HTTPS

| Característica                    | Descripción                                                                 |
|----------------------------------|-----------------------------------------------------------------------------|
| 🔐 Cifrado de extremo a extremo  | Protege los datos transmitidos entre cliente y servidor mediante TLS.      |
| ✅ Autenticación                 | Verifica la identidad del servidor usando certificados digitales.           |
| 🛡️ Integridad de datos          | Asegura que los datos no han sido modificados durante la transmisión.       |
| 🌍 Usa puerto 443                | El protocolo HTTPS utiliza el puerto 443 por defecto.                      |
| 🔄 Basado en TLS/SSL            | HTTPS encapsula HTTP dentro de una capa segura usando TLS o SSL.           |
| 🔎 Verificable en navegador      | Los certificados pueden ser verificados por el usuario en el navegador.     |
| 🧠 Mejora confianza y SEO       | Mejora la reputación del sitio, confianza del usuario y posicionamiento web.|


### Ventajas de HTTPS frente a HTTP

| Característica         | HTTP           | HTTPS                                |
|------------------------|----------------|--------------------------------------|
| 🔒 Cifrado             | ❌ No          | ✅ Sí, mediante TLS/SSL              |
| 🧾 Autenticación       | ❌ No          | ✅ Certificados digitales verificados |
| 🛡️ Integridad de datos | ❌ No          | ✅ Sí                                 |
| 🌐 Puerto utilizado     | 80             | 443                                   |
| 👁️ Visibilidad en navegador | ❌ No         | ✅ Candado visible, más confianza     |
| 🔍 SEO y reputación     | ❌ Negativa    | ✅ Favorecida por buscadores         |
| 💳 Apto para pagos      | ❌ No seguro   | ✅ Recomendado y obligatorio          |



## Ejemplo práctico

### Ejemplo 1: Navegación web segura

-   Cuando accedes a `https://www.banco.com`:
    
    -   El navegador **establece una conexión HTTPS** con el servidor del banco.
        
    -   Se intercambian claves y se verifica el **certificado SSL/TLS**.
        
    -   Luego, tus datos de login o transacciones se **envían cifrados**, evitando que puedan ser interceptados.
        

### Ejemplo 2: Comunicación con una API

-   Un sistema IoT envía datos a `https://api.misensores.com/data`
    
    -   Se garantiza que los datos de sensores (temperatura, CO₂, etc.) lleguen **seguros y sin ser manipulados**.
        
    -   Además, el dispositivo puede validar que está hablando con la API correcta y no con un servidor malicioso (ataques tipo _man-in-the-middle_).

## 🔍 1. ¿Cómo ver el certificado HTTPS en un navegador?

Esto lo podés hacer desde **Chrome**, **Firefox**, **Edge**, etc. Aquí va el paso a paso:

###  En Google Chrome (aunque el procedimiento es similar en otros navegadores):

1.  Accedé a cualquier sitio seguro, por ejemplo: `https://www.google.com`.
    
2.  Hacé clic en el **ícono del candado 🔒** que aparece en la barra de direcciones.

![Click candado](https://www.hostinger.com/ar/tutoriales/wp-content/uploads/sites/38/2024/06/la-conexion-es-segura.webp)
    
3.  Aparece un menú con opciones como:
    
    -   "La conexión es segura"
        
    -   "El certificado es válido"
        
4.  Hacé clic en “**El certificado es válido**” o "Información del certificado".
    
5.  Se abre una ventana donde podés ver:
    
    -   Emisor del certificado (CA)
        
    -   Periodo de validez (desde y hasta)
        
    -   Detalles del cifrado
        
    -   A qué dominio fue emitido
