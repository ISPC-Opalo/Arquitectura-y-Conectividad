## 2) ¿Cómo se aplica la Amplitud Modulada (AM) en sistemas IoT? ¿Dónde se usa? Ejemplifique.

### ¿Qué es la Amplitud Modulada (AM)?

La **modulación en amplitud (AM)** es una técnica de modulación analógica en la cual la **amplitud de una señal portadora (de alta frecuencia)** varía proporcionalmente a los valores de la **señal de información** (baja frecuencia).

Es una de las técnicas más antiguas y simples, utilizada históricamente en radiodifusión AM y todavía vigente en aplicaciones específicas de bajo costo.

![alt text](<amplitud modulada.png>)

---

### Aplicación de AM en IoT

Aunque no es la técnica más usada en IoT moderno, la AM puede aplicarse en situaciones donde se requiera una solución **económica, simple y de baja complejidad**.

#### Aplicaciones típicas:

- **Educativas o experimentales**: Ideal para explicar conceptos básicos de modulación.
- **Sistemas de muy bajo costo**: Cuando el presupuesto o hardware son muy limitados.
- **Ambientes con poco ruido electromagnético**: Laboratorios, zonas rurales, etc.



---


### Ejemplo de uso

**Escenario:** Un sistema de monitoreo de humedad en el suelo en una finca rural, transmite datos con módulos de RF AM a 433 MHz.

**Funcionamiento:**

1. Un sensor analógico mide la humedad.
2. Esa señal se usa para modular en amplitud una señal portadora.
3. El receptor AM capta y demodula la señal para obtener el valor.

Este sistema puede ser útil en **aplicaciones de agricultura inteligente** sin acceso a redes complejas.

---

### Desventajas de la AM en IoT

| Limitación | Descripción |
|------------|-------------|
| **Baja inmunidad al ruido** | Susceptible a interferencias. |
| **Eficiencia espectral baja** | Poco aprovechamiento del ancho de banda. |
| **Calidad de señal limitada** | Se degrada con la distancia. |
| **Tecnología obsoleta** | En comparación con modulaciones digitales modernas. |

---

