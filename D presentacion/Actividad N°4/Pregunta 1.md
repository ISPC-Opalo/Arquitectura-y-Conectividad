![Carátula](../../E%20assets/caratula.png)

# Comunicación REST (Representational State Transfer)

REST es un forma arquitectónico que define cómo interactúan los sistemas en una red, usa principalmente el protocolo HTTP. Este sistemas RESTful intercambian datos en formato sencillo (como JSON o XML) mediante operaciones como GET, POST, PUT, DELETE, como vimos en la Activoda 3 . Se usa en aplicaciones web y sistemas IoT.  

## ¿Para qué se usa?
REST se usa para diseñar servicios web que permiten:
- Acceso y manipulación de recursos en un servidor.
- Comunicación entre sistemas diferentes de manera ligera y eficiente.
- Creación de APIs RESTful, las cuales permiten que aplicaciones o dispositivos se comuniquen con un servidor para consultar o modificar datos.

## Ejemplo:
Vamos a suponer que una aplicación utiliza un API RESTful para mostrar datos de usuarios.

Solicitud REST (usando HTTP GET):
GET https://api.example.com/usuarios/123


Respuesta del servidor (en formato JSON):
{
  "id": 123,
  "nombre": "Luciano",
  "email": "luciano@example.com"
}


En este caso el cliente solicita información sobre un usuario con el ID 123 y el servidor responde con los datos en JSON.
