![Carátula](../../E%20assets/caratula.png)

# Formato de datos JSON (JavaScript Object Notation)


JSON es un formato de datos ligero, basado en texto, que se utiliza para estructurar y enviar información entre sistemas es fácil de leer y escribir tanto para las personas como para máquinas.

Se organiza en pares clave-valor:  

{
  "clave": "valor"
}


## se usa en:
- En APIs RESTful para intercambiar datos entre cliente y servidor.
- En aplicaciones IoT, donde dispositivos envían o reciben datos en JSON.
- En almacenamiento de datos estructurados sensillos.

## Ejemplo:
Un sensor IoT envía sus lecturas al servidor en formato JSON:
{
  "sensor_id": "DTH11",
  "temperatura": 25.6,
  "unidad": "Celsius",
  "ubicacion": "Cosina"
}


El servidor puede procesar este mensaje para mostrar la información en un panel de control.

## Hay una relacion entre REST y JSON
JSON es un formato comúnmente utilizado en comunicaciones RESTful:
- El cliente envía una solicitud a un servidor RESTful usando un método como POST con un mensaje en JSON.
- El servidor responde con datos estructurados en JSON que el cliente interpreta y utiliza.
