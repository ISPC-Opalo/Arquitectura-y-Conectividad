*8) ¿Cuáles son los protocolos paralelos más usados? Nombra alguno y descríbelo.*
La comunicación paralela se caracteriza por transmitir múltiples bits simultáneamente, cada uno por una línea de datos diferente. Esto permite una alta velocidad de transferencia, pero con el costo de mayor complejidad y necesidad de sincronización precisa.

![alt text](<protocolos paralelos destacados.png>)


*Protocolo Centronics (IEEE 1284)*
**Descripción:**

Fue uno de los primeros estándares de comunicación paralela, diseñado en los años 70 por la empresa Centronics para impresoras.
![alt text](<inrterfaz centronics.png>)

Utiliza un conector DB-25 en la computadora y un conector de 36 pines en la impresora.

Transmite datos en bloques de 8 bits en paralelo.

Acompañado de señales de control como STROBE, ACK, BUSY, ERROR y SELECT.

**Características:**

◍ Originalmente unidireccional: solo enviaba datos desde la computadora a la impresora.

***Posteriormente evolucionó a un estándar bidireccional (IEEE 1284) con cinco modos:***

◍ Compatible (modo Centronics)

◍ Nibble (lectura desde la impresora)

◍ Byte (bidireccionalidad)

◍ ECP (Extended Capability Port)

◍ EPP (Enhanced Parallel Port)

**Uso:**

->Conexión de impresoras paralelas (impresoras matriciales, láser antiguas).

->Fue reemplazado por USB y otras tecnologías más modernas.

