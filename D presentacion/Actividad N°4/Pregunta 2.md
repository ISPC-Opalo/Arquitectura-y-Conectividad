![Carátula](../../E%20assets/caratula.png)


#  ¿Qué es el formato JSON?

**JSON** (JavaScript Object Notation) es un formato ligero de intercambio de datos, basado en texto, fácil de leer y escribir tanto para humanos como para máquinas. Se originó en el lenguaje JavaScript, pero hoy es compatible con prácticamente todos los lenguajes de programación.

---

#  ¿Para qué se utiliza?

JSON se utiliza principalmente para estructurar y transportar datos entre diferentes sistemas. Es muy común en entornos de desarrollo web, móviles, IoT, bases de datos y APIs modernas.

---

#  Estructura de un archivo JSON

Los datos en JSON se organizan como pares clave-valor, encerrados entre llaves `{}`.  
Cada clave (**key**) debe ser un *string* entre comillas dobles y debe tener un valor asociado:

```json
{
  "clave": "valor"
}
```

Los valores pueden ser:

- Cadenas de texto (`"texto"`)
- Números (`25`, `3.14`)
- Booleanos (`true`, `false`)
- Arreglos (listas) (`[1, 2, 3]`)
- Objetos (diccionarios anidados)
- `null` (para valores vacíos)

---

#  Ejemplos de uso

###  En una API RESTful:

El cliente realiza una solicitud al servidor para obtener información sobre un usuario.

**Solicitud GET:**
```bash
GET /api/usuarios/1
```

**Respuesta JSON:**
```json
{
  "id": 1,
  "nombre": "Ana",
  "email": "ana@example.com"
}
```

---

###  En un dispositivo IoT:

Un sensor de temperatura envía sus datos a un servidor central.

```json
{
  "sensor_id": "DHT11",
  "temperatura": 25.6,
  "unidad": "Celsius",
  "ubicacion": "Cocina"
}
```

Este mensaje puede ser procesado por una plataforma que almacena, analiza y muestra los datos en tiempo real.

---

###  En almacenamiento local de datos estructurados:

Una aplicación puede guardar configuraciones de usuario en un archivo JSON.

```json
{
  "tema": "oscuro",
  "idioma": "es",
  "notificaciones": true
}
```

---

# 🔗 Relación entre JSON y REST

En arquitecturas RESTful, JSON es el formato más utilizado para el intercambio de datos.  
La comunicación suele seguir el siguiente esquema:

- **Cliente ➡️ Servidor (Request):** El cliente envía datos en formato JSON mediante métodos HTTP como `POST`, `PUT` o `PATCH`.
- **Servidor ➡️ Cliente (Response):** El servidor responde con datos estructurados en JSON.

Esto permite una interacción clara, predecible y sencilla entre sistemas, sin importar el lenguaje o plataforma que utilicen.

---

#  Ventajas del formato JSON

- Legible para humanos  
- Ligero (menor tamaño que XML, por ejemplo)  
- Compatible con la mayoría de lenguajes de programación  
- Ideal para sistemas distribuidos y en tiempo real
