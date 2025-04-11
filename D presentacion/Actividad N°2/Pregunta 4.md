4. **¿Cómo se aplica la Cuadratura de Amplitud (QAM) en sistemas lot?. ¿Dónde se usa?. Ejemplifique.**

QAM es una tecnica de modulacion digital que combina las modulacion por amplitud (AM) y la modulacion en cuadratura de fase (QPSK), Aqui se transmiten datos utilizando dos señales defasadas en 90°. Una de estas señales modula el componenete I (in-phase o fase) y la otra el componente Q (cuadratura). Si lo representamos en un plano cartesiano, mediante estas dos señales obtenemos una coordenada dentro del plano. Esta coordenanda representa una combinacion de bits.

<img src="../../E assets/Cuestionario N2/P4Img1.png" alt="QAM"
     width="300"
     style="margin-left: 20px; margin-top: 15px;" />

Lo que esto permite es reducir la cantidad de informacion enviada, mediante una representacion entendida por las dos partes. Eficientiza la transferencia de informacionde forma drastica.  A medida que se dispone mas puntos por constelacion, mas se hace notar la eficiencia en relacion a los bits por simbolos requerido.
 
| Tipo     | Puntos en la constelación  | Bits por símbolo      |
|----------|----------------------------|-----------------------|
| QAM-4    | 4 puntos                   | 2 bits por símbolo    |
| QAM-16   | 16 puntos                  | 4 bits por símbolo    |
| QAM-64   | 64 puntos                  | 6 bits por símbolo    |
| QAM-256  | 256 puntos                 | 8 bits por símbolo    |

**Ejemplos de QAM disponibles/utilizados segun la tecnologia de transferencia**

- Wi-Fi (802.11n/ac/ax) → QAM-64, QAM-256, QAM-1024
- 4G/LTE y 5G → QAM-64, QAM-256, y hasta QAM-4096
- NB-IoT (Narrowband IoT) y LTE-M → versiones más simples, como QPSK y QAM-16

Concretamente para con el IoT, donde el espectro es un recurso limitado, QAM permite aprovechar al máximo cada Hz de ancho de banda, clave en zonas urbanas o industriales, donde conviven miles de sensores y dispositivos. Siguiendo el ejemplo de una fabrica, y tuviesemos muchos dispositivos juntos, un QAM mas alto nos permitiria aprovechas mejor el ancho de banda. Pero suponiendo que se encuentren distancias, podriamos rebajar el QAM a fin de hacerlo mas rebusto ante los ruidos e interferencias del entorno.


