# Implementar  un  pequeño  código  JASON,  donde  un  cliente  solicita  una pizza.(por lo menos 4 o 5 tipos de pizza) (2 tamaños) (precios).

Se crea el documento formato json "pizzas.json" en el directorio "/C prototipo/Actividad N°4/.." ["./C prototipo/Actividad N°4"]

En el documento definimos el objeto **pizza**, con 3 características: **nombre**, **tamaño**, **ingredientes**.

    {
    "pizzas": [
        {
        "nombre": "",
        "tamaños": { },
        "ingredientes": { }
        },
    ]
    }

- **nombre**: un string, solo sera el nombre de la variedad de pizza.

- **tamaño** es un diccionario con el formato "tamaño":"cantidad de porciones"

      "tamaños": {
        "chica": 4,
        "grande": 8
      },

- **ingredientes** se compone de 3 componenetes. "salsa" y "aceitunas" que funcionaran como booleanos segun tenga o no. y "topings" con la lista de posibles ingredientes.

      "ingredientes": {
        "salsa": true/false,
        "aceitunas": true/false,
        "topings": [ ]
      }
