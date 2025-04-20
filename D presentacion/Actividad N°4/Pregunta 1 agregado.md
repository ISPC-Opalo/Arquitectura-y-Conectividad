![Carátula](../../E%20assets/caratula.png)

# 1) ¿Qué es una Comunicación REST?, ¿Para qué se usan? Ejemplifique.

Una comunicación REST **(Representational State Transfer)** es un estilo de arquitectura de software que se utiliza comúnmente para construir servicios web. Sería una forma estandarizada y sencilla para que diferentes aplicaciones se comuniquen entre sí a través de internet.

**¿Qué es exactamente?**

En esencia, REST se basa en los siguientes principios clave:

-   **Arquitectura cliente-servidor:** Existe un cliente que realiza peticiones y un servidor que las responde. Están separados y pueden evolucionar independientemente.
-   **Sin estado (Stateless):** Cada petición del cliente al servidor contiene toda la información necesaria para entenderla. El servidor no guarda ninguna información sobre las peticiones anteriores del cliente. Esto simplifica el diseño y la escalabilidad.
-   **Cacheable:** Las respuestas del servidor deben indicar si pueden ser cacheadas por el cliente o por intermediarios, mejorando así la eficiencia.
-   **Interfaz uniforme:** La comunicación se realiza a través de un conjunto consistente de interfaces. Esto facilita la interacción entre diferentes sistemas. Los aspectos clave de esta interfaz uniforme son:
    -   **Identificación de recursos:** Cada pieza de información (un usuario, un producto, una orden, etc.) se identifica mediante un URI (Uniform Resource Identifier), como una dirección web.
    -   **Manipulación de recursos a través de representaciones:** Los recursos se transfieren entre el cliente y el servidor en diferentes formatos (por ejemplo, JSON, XML). La representación del recurso captura su estado actual.
    -   **Mensajes auto-descriptivos:** Cada mensaje contiene suficiente información para que el receptor pueda entenderlo. Por ejemplo, el tipo de contenido se especifica en las cabeceras HTTP.
    -   **Hipermedia como motor del estado de la aplicación (HATEOAS):** La respuesta del servidor puede incluir enlaces a otros recursos relacionados o acciones que el cliente puede realizar. Esto permite al cliente descubrir dinámicamente las posibles interacciones.
-   **Sistema de capas:** La arquitectura puede estar compuesta por múltiples capas (por ejemplo, cliente, servidor, caché, balanceador de carga) que interactúan de forma jerárquica, donde cada capa solo "ve" la capa inmediatamente inferior.
-   **Código bajo demanda (opcional):** El servidor puede enviar código ejecutable al cliente (por ejemplo, applets de Java o JavaScript) para extender su funcionalidad.

**¿Para qué se usan?**

Las comunicaciones REST son ampliamente utilizadas para:

-   **Construir APIs (Application Programming Interfaces) web:** Permiten que diferentes aplicaciones (móviles, web, de escritorio) interactúen con los datos y funcionalidades de un servidor. Por ejemplo, una aplicación móvil puede usar una API REST para obtener la lista de productos de una tienda en línea.
-   **Integrar sistemas:** Facilitan la comunicación entre diferentes sistemas de software, aunque estén desarrollados con diferentes tecnologías.
-   **Desarrollar aplicaciones web modernas:** Muchas aplicaciones web de una sola página (SPAs) utilizan APIs REST para comunicarse con el backend y actualizar la interfaz de usuario de forma dinámica.
-   **Servicios en la nube:** La mayoría de los servicios en la nube exponen sus funcionalidades a través de APIs REST.

### **Ejemplo:**

Imagina una aplicación para gestionar una biblioteca.

-   **Recurso:** Un libro. Cada libro tiene un ID único.
-   **URI para un libro específico:** `/libros/123` (donde 123 es el ID del libro).

Aquí hay algunos ejemplos de cómo un cliente (la aplicación de la biblioteca) podría interactuar con un servidor (el sistema de la biblioteca) usando comunicación REST:

1.  **Obtener información de un libro:**
    
    -   **Petición del cliente (HTTP GET):** `GET /libros/123`
    -   **Respuesta del servidor (HTTP 200 OK):**
        
        JSON
        
        ```
        {
          "id": 123,
          "titulo": "Cien años de soledad",
          "autor": "Gabriel García Márquez",
          "isbn": "978-0307474727"
        }
        
        ```
        
    -   Aquí, el servidor envía una representación del libro en formato JSON.
2.  **Crear un nuevo libro:**
    
    -   **Petición del cliente (HTTP POST):** `POST /libros`
    -   **Cuerpo de la petición (en formato JSON):**
        
        JSON
        
        ```
        {
          "titulo": "El principito",
          "autor": "Antoine de Saint-Exupéry",
          "isbn": "978-0156012195"
        }
        
        ```
        
    -   **Respuesta del servidor (HTTP 201 Created):** El servidor podría responder con un código de estado 201 (Creado) y la representación del nuevo libro, incluyendo su ID asignado.
3.  **Actualizar la información de un libro:**
    
    -   **Petición del cliente (HTTP PUT):** `PUT /libros/123`
    -   **Cuerpo de la petición (en formato JSON):**
        
        JSON
        
        ```
        {
          "autor": "Gabriel García Márquez",
          "editorial": "Vintage"
        }
        
        ```
        
    -   **Respuesta del servidor (HTTP 200 OK o 204 No Content):** El servidor podría responder con un código 200 si la actualización fue exitosa y devuelve la representación actualizada, o con un 204 si la actualización se realizó pero no hay contenido para devolver.
4.  **Eliminar un libro:**
    
    -   **Petición del cliente (HTTP DELETE):** `DELETE /libros/123`
    -   **Respuesta del servidor (HTTP 200 OK o 204 No Content):** El servidor podría responder con un código 200 si la eliminación fue exitosa, o con un 204 si se eliminó pero no hay contenido para devolver.

En este ejemplo, utilizamos los métodos HTTP estándar (GET, POST, PUT, DELETE) para realizar diferentes operaciones sobre el recurso "libro". La información se intercambia en formato JSON, que es legible tanto para humanos como para máquinas.  

> Otros formatos que se pueden utilizar para enviar y recibir datos de las peticiones REST.


La elección del formato a menudo depende de las necesidades específicas de la aplicación, la compatibilidad entre el cliente y el servidor, y las preferencias del desarrollador.

Aquí tienes algunos de los formatos más comunes:

-   **XML (Extensible Markup Language):** Fue uno de los formatos más populares antes de la adopción masiva de JSON. XML es un lenguaje de marcado que permite estructurar datos de forma jerárquica utilizando etiquetas. Aunque es más verboso que JSON, sigue siendo utilizado en muchos sistemas, especialmente en integraciones empresariales y servicios web legados.
    
    XML
    
    ```
    <libro>
      <id>123</id>
      <titulo>Cien años de soledad</titulo>
      <autor>Gabriel García Márquez</autor>
      <isbn>978-0307474727</isbn>
    </libro>
    
    ```
    
-   **Texto Plano (Plain Text):** En algunos casos muy simples, se pueden enviar datos como texto plano. Esto es adecuado para intercambiar información sencilla sin mucha estructura. Por ejemplo, un servicio podría devolver un simple mensaje de estado en texto plano.
    
    ```
    Estado: OK
    
    ```
    
-   **HTML (HyperText Markup Language):** Aunque principalmente se utiliza para la estructura y presentación de páginas web, en ciertos escenarios, una API REST podría devolver fragmentos HTML. Esto es menos común para el intercambio de datos puros, pero podría ser útil en casos donde se necesita renderizar directamente una porción de la interfaz de usuario.
    
    HTML
    
    ```
    <div>
      <strong>Título:</strong> Cien años de soledad
    </div>
    
    ```
    
-   **CSV (Comma Separated Values):** Se utiliza para representar datos tabulares. Cada línea representa una fila de datos, y los valores dentro de cada fila están separados por comas (u otro delimitador). Es un formato simple y ampliamente compatible, útil para importar y exportar grandes cantidades de datos.
    
    Fragmento de código
    
    ```
    id,titulo,autor,isbn
    123,"Cien años de soledad","Gabriel García Márquez","978-0307474727"
    ```