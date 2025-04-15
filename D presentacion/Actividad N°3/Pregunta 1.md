![Carátula](../../E%20assets/caratula.png)

# Peticiones Más Comunes del Protocolo HTTPS

El protocolo HTTPS utiliza varios métodos de solicitud (también conocidos como "métodos HTTP") para interactuar con los recursos de un servidor web. A continuación se describen las 5 más comunes, su uso y un ejemplo para cada una:

## 1. GET

- **Uso:** Solicita datos de un recurso específico. No debe usarse para enviar datos sensibles.
- **Ejemplo:** Un usuario accede a una página web.

```http
GET /productos HTTP/1.1
Host: www.ejemplo.com
```

## 2. POST

- **Uso:** Envía datos al servidor, comúnmente para crear nuevos recursos o enviar formularios.
- **Ejemplo:** Un usuario envía un formulario de contacto.

```POST /contacto HTTP/1.1
Host: www.ejemplo.com
Content-Type: application/x-www-form-urlencoded

nombre=Juan&mensaje=Hola
```

## 3. PUT

- **Uso:** Envía datos al servidor para actualizar un recurso existente o crear uno si no existe.
- **Ejemplo:** Actualizar la información de un producto.

```PUT /productos/123 HTTP/1.1
Host: www.ejemplo.com
Content-Type: application/json

{
  "nombre": "Teclado",
  "precio": 45.99
}
```

## 4. DELETE 

- **Uso:** Elimina un recurso específico del servidor.
- **Ejemplo:** Eliminar un producto del inventario.

```
DELETE /productos/123 HTTP/1.1
Host: www.ejemplo.com
```

## 5. PATCH

- **Uso:** Realiza una actualización parcial a un recurso.
- **Ejemplo:** Actualizar solo el precio de un producto.

```
PATCH /productos/123 HTTP/1.1
Host: www.ejemplo.com
Content-Type: application/json

{
  "precio": 39.99
}
```
