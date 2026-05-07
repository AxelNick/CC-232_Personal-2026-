# Actividad 4 - Semana 4

## Integrantes
- Axel Alberto Reyes Baldeon

## Bloque 0 - Instalación y preparación

- [x] Carpeta de trabajo lista.
- [x] Verificación de acceso a lecturas y archivo de entrega.
- [x] Creación del archivo `Actividad4-CC232.md`.
- [x] Registro de nombre completo.
- [x] Compilación y ejecución de demostraciones y pruebas.

### Verificación de Entorno (Semana 4)

**Estado de Compilación y Ejecución:**
*   **Demo ejecutada:** `demo_stack_queue.cpp`

```
$ ./sem4_demo_stack_queue
Tope de la pila = 9
Elemento desapilado = 9
Frente de la cola = 10
Elemento desencolado = 10
```

*   **Prueba pública ejecutada:**

```
$ ctest --test-dir build-debug -C Debug -R semana4 --output-on-failure
Test project C:/Users/AXEL/OneDrive/Escritorio/uni/2026-1/AED/Repositorio/Personal/CC232/Libreria_cc232/build-debug
    Start 18: semana4_public
1/2 Test #18: semana4_public ...................   Passed    0.20 sec
    Start 19: semana4_internal
2/2 Test #19: semana4_internal .................   Passed    0.20 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.49 sec
```

> *Nota: Se confirma que el entorno de desarrollo está correctamente configurado para trabajar con las estructuras de la Semana 4.*

## Bloque 1 - Núcleo conceptual de la semana

### Material de Revisión:
- `Semana4/README.md`
- `Semana4/include/Stack.h`
- `Semana4/include/Queue.h`
- `Semana4/include/BaseConversion.h`
- `Semana4/include/Parentheses.h`
- `Semana4/include/ExpressionEvaluator.h`
- `Semana4/include/NQueens.h`
- `Semana4/include/Maze.h`
- `Semana4/include/BankSimulation.h`
- `Capítulo 4 de Deng `

### 1. Explica con tus palabras la diferencia entre acceso LIFO y acceso FIFO.

La diferencia se encuentra en el orden de extracción. 
**LIFO** (*Last In, First Out* / Pila) significa que siempre se retira el último elemento que ingresó. 
**FIFO** (*First In, First Out* / Cola) significa que se retira el primer elemento que ingresó, manteniendo un estricto orden de llegada.

### 2. Explica por qué Stack resuelve naturalmente problemas donde importa "lo último pendiente".

Porque su disciplina LIFO garantiza que el elemento guardado más recientemente sea el primero en recuperarse. Esto es ideal para tareas que se interrumpen para ejecutar una subtarea; la pila permite recordar exactamente el último contexto en el que estábamos para retomarlo inmediatamente al terminar.

### 3. Explica por qué Queue modela naturalmente procesos de espera y atención.

Porque su política FIFO asegura "justicia secuencial". Los elementos son procesados exactamente en el mismo orden temporal en el que llegaron, lo cual es la definición operativa de cualquier fila de atención o sistema de planificación de tareas en tiempo real.

### 4. Explica qué significa reemplazar recursión implícita por una estructura explícita.

Significa dejar de depender de la memoria invisible del sistema (la "pila de llamadas" gestionada por el SO), y en su lugar crear manualmente un objeto `Stack` en el código. Esto permite controlar el flujo mediante un bucle iterativo, evitando desbordamientos de pila (*stack overflow*) en problemas de gran profundidad.

### 5. Explica qué información mínima debe guardarse para que una pila permita reconstruir una solución parcial.

Debe guardarse la "decisión válida más reciente" (por ejemplo, la coordenada de la última reina colocada o la última celda visitada). Esto funciona como un punto de control (*save point*) que permite deshacer solo el último paso si el camino actual resulta ser un callejón sin salida.

### 6. Compara la conversión de base recursiva e iterativa: ¿qué comparten y qué cambia en el control del proceso?

Comparten la lógica matemática (divisiones sucesivas y cálculo del residuo). Lo que cambia es el mecanismo de inversión: la recursiva delega el ordenamiento de los dígitos a la pila del sistema, mientras que la iterativa gestiona esa inversión manualmente haciendo `push` y `pop` en un objeto `Stack` explícito.

### 7. Explica por qué la verificación iterativa de paréntesis necesita almacenar aperturas pendientes.

Al leer una cadena de izquierda a derecha, cuando se encuentra un símbolo de apertura `(`, no se conoce aún su posición de cierre. La pila actúa como una memoria temporal que retiene las aperturas para asegurar que el último símbolo abierto sea el primero en cerrarse, validando la anidación correcta.

### 8. Explica por qué el evaluador de expresiones necesita dos pilas y no una sola.

Debido a que operandos y operadores tienen ciclos de vida distintos por las reglas de precedencia. Se requiere una pila para los números y otra separada para "aplazar" los operadores hasta confirmar que no existe uno de mayor prioridad (como una multiplicación) que deba ejecutarse antes.

### 9. Explica por qué N-Reinas y laberinto son ejemplos naturales de backtracking.

Porque en ambos problemas la solución se construye por etapas y es probable tomar decisiones que lleven a estados inválidos. El **backtracking** permite avanzar y, al detectar un bloqueo, desapilar la última decisión para probar una alternativa distinta sin reiniciar todo el proceso.

### 10. Explica por qué la simulación bancaria no se modela bien con pila, pero sí con colas.

Modelar un banco con una pila (LIFO) implicaría atender primero al último cliente que llegó, lo cual rompe la lógica de servicio. La cola (FIFO) es la única estructura que respeta el orden cronológico de llegada, garantizando una atención equitativa.

### 11. Explica qué relación hay entre estructura auxiliar, estado parcial y correctitud.

La estructura auxiliar (ej. `Stack`) es el contenedor físico que protege el "estado parcial" (el progreso actual). Mantener esta relación sincronizada garantiza la **correctitud**, impidiendo que el algoritmo pierda datos, repita estados o procese información en un orden lógicamente incorrecto.

### 12. Explica qué diferencia conceptual hay entre "resolver un problema" y "simular un proceso".

- Resolver un problema : es un enfoque estático que busca una respuesta final óptima (como la salida de un laberinto). 
- Simular un proceso: es un enfoque dinámico que imita el comportamiento de un sistema (como el flujo en un banco) para analizar métricas y comportamientos a lo largo del tiempo.


## Bloque 2 - Demostración y trazado guiado

### Material de Revisión:
- `Semana4/demos/demo_stack_queue.cpp`
- `Semana4/demos/demo_base_conversion.cpp`
- `Semana4/demos/demo_paren_rpn.cpp`
- `Semana4/demos/demo_nqueens.cpp`
- `Semana4/demos/demo_maze.cpp`
- `Semana4/demos/demo_bank.cpp`
- `Semana4/demos/demo_capitulo4_panorama.cpp`

### Tabla de análisis de demos

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
| :--- | :--- | :--- | :--- |
| **`demo_stack_queue.cpp`** | `Tope = 9`, `Frente = 10` | Implementación directa de interfaces LIFO (Pila) y FIFO (Cola). | Garantiza operaciones de inserción y extracción en $O(1)$. La restricción de acceso simplifica el diseño para procesos de "último en llegar" o "orden de llegada". |
| **`demo_base_conversion.cpp`** | `12345 en base 8 = 30071` | Uso de una pila para invertir el orden de los residuos obtenidos. | Demuestra la equivalencia entre la recursión (pila del sistema) y la iteración con pila explícita, controlando el uso de memoria de forma manual. |
| **`demo_paren_rpn.cpp`** | `true`, `RPN: 0 ! 1 + 2 3 ! ...` | Uso de pilas para gestionar la precedencia de operadores y el anidamiento. | Permite transformar expresiones complejas en secuencias lineales procesables sin paréntesis, optimizando la evaluación sintáctica en tiempo lineal. |
| **`demo_nqueens.cpp`** | `solutions = 2`, `checks = 84` | Algoritmo de backtracking iterativo usando una pila para guardar la solución parcial. | La pila funciona como memoria de decisiones; permite retroceder al estado anterior en $O(1)$ cuando se alcanza un bloqueo lógico en el tablero. |
| **`demo_maze.cpp`** | `Medida del camino = 5` | Exploración de caminos mediante una pila de celdas (retroceso espacial). | Representa el "hilo de Ariadna" en la búsqueda: la pila almacena la ruta actual y permite la poda de caminos que no conducen a la meta. |
| **`demo_bank.cpp`** | `Llegadas = 7, t=9: [78,59,74]` | Simulación de eventos discretos usando un vector de colas dinámicas. | Modela la justicia temporal y el reparto de carga. El uso de colas asegura que el tiempo de espera sea proporcional al orden de llegada de los clientes. |
| **`demo_capitulo4_panorama.cpp`** | Resumen de todas las aplicaciones integradas. | Prueba de integración de todas las aplicaciones del capítulo 4. | Valida la robustez y modularidad de la librería, demostrando que un mismo núcleo de datos puede resolver desde matemáticas hasta simulaciones. |

### Evidencias de Compilación y Ejecución

#### demo_stack_queue.cpp
```bash
$ ./sem4_demo_stack_queue
Tope de la pila = 9
Elemento desapilado = 9
Frente de la cola = 10
Elemento desencolado = 10
```

#### demo_base_conversion.cpp
```bash
$ ./sem4_demo_base_conversion
12345 en base 8 (recursivo) = 30071
12345 en base 8 (iterativo) = 30071
```

#### demo_paren_rpn.cpp
```bash
$ ./sem4_demo_paren_rpn
Parentesis balanceados (iterativo) = true
Expresion en RPN = 0 ! 1 + 2 3 ! 4 + ^ * 5 ! 67 - 8 9 + - -
Valor de la expresion = 2012
```

#### demo_nqueens.cpp
```bash
$ ./sem4_demo_nqueens
N = 4, soluciones = 2, verificaciones = 84
1 3 0 2 
2 0 3 1 
```

#### demo_maze.cpp
```bash
$ ./sem4_demo_maze
Medida del camino = 5
(1,1) (1,2) (1,3) (2,3) (3,3) 
```

#### demo_bank.cpp
```bash
$ ./sem4_demo_bank
Llegadas = 7, atendidos = 0
t=0: [87] [] []
t=5: [82] [8] [55]
t=9: [78,59,74] [4,95] [51,65]
```

#### demo_capitulo4_panorama.cpp
```bash
$ ./sem4_demo_capitulo4_panorama
Semana 4 cargada correctamente
Tope de la pila = 2
Frente de la cola = 10
12345 en base 8 = 30071
Parentesis balanceados = true
Expresion en RPN = 0 ! 1 + 2 3 ! 4 + ^ * 5 ! 67 - 8 9 + - -
Valor = 2012
Soluciones de N-Reinas(4) = 2
Longitud del camino en el laberinto = 5
Llegadas al banco = 5, atendidos = 0
```

### Análisis de Demos y Observables (Semana 4)

**1. En `demo_stack_queue.cpp`, ¿qué parte de la salida deja más clara la diferencia entre tope y frente?**

La diferencia se nota en los valores recuperados: el tope de la pila es 9 (el último en entrar), mientras que el frente de la cola es 10 (el primero en entrar). Esto confirma visualmente las políticas **LIFO** y **FIFO**.

**2. En `demo_base_conversion.cpp`, ¿qué observable permite afirmar que las versiones recursiva e iterativa producen la misma representación?**

El resultado idéntico impreso por ambos métodos (30071). Esto demuestra que una pila gestionada por el programador (iterativa) puede replicar con exactitud el comportamiento de la pila de llamadas del sistema (recursiva).

**3. En `demo_paren_rpn.cpp`, ¿qué relación observas entre paréntesis balanceados, RPN y valor final?**

Es un proceso en cadena: la validación de paréntesis asegura que la expresión es procesable; la conversión a **RPN** elimina la ambigüedad de los paréntesis para la máquina; y esto permite calcular el valor final de forma lineal y eficiente.

**4. En `demo_nqueens.cpp`, ¿qué significan solutions y checks, y por qué no miden lo mismo?**

`solutions` es el número de configuraciones ganadoras halladas, mientras que `checks` es la cantidad total de validaciones realizadas. `checks` es mucho mayor porque incluye todos los intentos fallidos que el algoritmo tuvo que probar antes de retroceder.

**5. En `demo_maze.cpp`, ¿qué muestra la secuencia de coordenadas sobre el camino encontrado?**

Muestra la ruta crítica exitosa. Las coordenadas impresas son aquellas que permanecieron en la pila tras descartar todos los caminos que terminaron en muros o callejones sin salida.

**6. En `demo_bank.cpp`, ¿qué representa cada lista impresa en cada instante t?**

Representa el estado de las filas en ese momento. Cada lista (ej. `[78, 59, 74]`) muestra a los clientes esperando en una ventanilla específica, donde el número es el tiempo restante de atención para cada uno.

**7. En `demo_capitulo4_panorama.cpp`, ¿qué salida resume mejor la idea de que una misma semana reúne estructuras y aplicaciones?**

La integración final de los resultados en un solo reporte: permite ver desde una operación básica de pila hasta problemas complejos como N-Reinas y simulación bancaria, validando que un mismo núcleo estructural soporta múltiples dominios.

## Bloque 3 - Pruebas públicas, pruebas internas y correctitud

### Material de Revisión:

- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

### 1. ¿Qué operaciones mínimas valida la prueba pública para Stack?

Valida el ciclo de vida básico de la pila: estado inicial vacío (`empty`), inserción de datos (`push`), lectura del elemento superior (`top`) y extracción destructiva (`pop`), comprobando que se respete estrictamente el orden **LIFO**.

### 2. ¿Qué operaciones mínimas valida la prueba pública para Queue?

Valida las funciones equivalentes para la cola: inicialización (`empty`), encolado (`enqueue`), lectura del primer elemento (`front`) y desencolado (`dequeue`), garantizando matemáticamente que se cumpla el orden **FIFO**.

### 3. ¿Qué valida la prueba pública sobre conversión de base?

Confirma empíricamente la equivalencia algorítmica: verifica que tanto el método recursivo como el iterativo produzcan exactamente la misma cadena de texto final al convertir un número a base octal.

### 4. ¿Qué valida la prueba pública sobre paréntesis balanceados?

Evalúa tres escenarios estructurales: la aceptación de expresiones simples y complejas (que combinan paréntesis, corchetes y llaves), y el rechazo explícito de expresiones que sufren de mal anidamiento o cruce de cierres (ej. `([)]`).

### 5. ¿Qué valida la prueba pública sobre evaluación de expresiones y RPN?

Verifica dos procesos simultáneos: que la cadena original se traduzca perfectamente a **Notación Polaca Inversa** respetando las precedencias (incluyendo potencias y factoriales), y que el cómputo final coincida con el valor matemático esperado (tolerancia `1e-9`).

### 6. ¿Qué valida la prueba pública sobre NQueens?

Confirma el conteo de soluciones. Para un tablero estándar reducido ($N=4$), verifica que el algoritmo de búsqueda encuentre exactamente las 2 únicas soluciones posibles y almacene correctamente las configuraciones resultantes en memoria.

### 7. ¿Qué valida la prueba pública sobre Maze?

Verifica el caso de éxito en la búsqueda espacial. Asegura que en un laberinto transitable, la función devuelva una ruta válida (no vacía) cuyo primer paso sea la coordenada de inicio y el último sea exactamente la de la meta.

### 8. ¿Qué valida la prueba pública sobre bestWindow en la simulación bancaria?

Comprueba la lógica de distribución de carga, asegurando que, al procesar un arreglo de ventanillas con distintos tamaños de fila, el algoritmo identifique y retorne correctamente el índice de la cola más vacía.

### 9. ¿Qué casos adicionales cubre la prueba interna y no aparecen de forma explícita en la pública?

Atacan los **casos borde** y manejo de errores: conversiones del número cero, uso de base hexadecimal, excepciones ante bases inválidas ($< 2$), reconocimiento del símbolo negativo como operador unario, laberintos sin solución física y escenarios triviales (tableros 1x1).

### 10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, estado y complejidad?

Porque las pruebas solo verifican que una entrada específica produce una salida correcta (**caja negra**). No demuestran que el consumo de memoria sea eficiente, que el tiempo de ejecución no se dispare con datos masivos o que la estructura no se corrompa internamente tras miles de operaciones.

### 11. Da un ejemplo de un error conceptual que podría sobrevivir si solo se ejecutaran los casos mínimos.

En el laberinto: si el algoritmo no marca las celdas como "visitadas" correctamente, en un mapa pequeño podría encontrar la meta por azar. Sin embargo, conceptualmente caería en un **bucle infinito** (desbordamiento de pila) al enfrentarse a un laberinto más grande con pasillos circulares.

## Bloque 4 - Comparación recursivo vs iterativo

### Material de Revisión:

- `Semana4/include/BaseConversion.h`
- `Semana4/include/Parentheses.h`
- `Semana4/demos/demo_base_conversion.cpp`
- `Semana4/demos/demo_paren_rpn.cpp`

### 1. En conversión de base, ¿qué papel juegan el cociente, el residuo y la pila?

El **cociente** es el valor numérico que queda por seguir dividiendo para encontrar los siguientes dígitos. El **residuo** es el valor del dígito actual calculado en esa iteración. La **pila** actúa como un invertidor de secuencias, guardando temporalmente los residuos en el orden en que se calculan.

### 2. ¿Por qué los residuos se apilan antes de formar la cadena final?

Porque el proceso matemático de divisiones sucesivas calcula primero el dígito menos significativo (el de la derecha) y termina con el más significativo (el de la izquierda). La pila invierte este "orden de descubrimiento" al orden normal de lectura de izquierda a derecha.

### 3. ¿Qué cambia entre dejar que el call stack haga el trabajo y manejar una pila explícita?

Cambia el **control de memoria** y el riesgo de colapso. La recursión consume un bloque de memoria completo por cada llamada (variables, direcciones de retorno), lo que puede causar un *Stack Overflow* con números gigantescos. Una **pila explícita** solo guarda los caracteres necesarios, optimizando el uso de recursos y evitando errores del sistema.

### 4. En `parenRecursive`, ¿qué idea intenta capturar `divideParentheses`?

Intenta capturar la idea de **"divide y vencerás"**. Busca el punto exacto donde un bloque de paréntesis se divide en dos bloques adyacentes independientes (ej. el punto central en `(A)(B)`), para poder validar cada mitad por separado mediante llamadas recursivas.

### 5. ¿Qué limitación conceptual tiene la versión recursiva mostrada frente a la iterativa cuando aparecen [] y {}?

La versión recursiva es frágil y poco escalable; soportar corchetes y llaves requeriría condicionales complejos en `divideParentheses` para rastrear cada tipo de cierre. La **versión iterativa** con pila simplifica esto, pues solo compara el símbolo entrante con el último símbolo de apertura apilado.

### 6. En `parenIterative`, ¿por qué un cierre incorrecto puede detectarse apenas aparece?

Porque el único símbolo de apertura que es legal cerrar es estrictamente el último que se abrió (el que está en la **cima de la pila**). Si el símbolo de cierre leído no coincide con esa cima, se detecta instantáneamente que la estructura está corrupta sin necesidad de procesar el resto del texto.

### 7. Compara ambas parejas de funciones: ¿en cuál caso la versión iterativa te parece más natural y en cuál la recursiva resulta más expresiva?

La **conversión de base** es más natural en su versión **iterativa**, ya que el bucle `while (n > 0)` refleja el proceso manual de división continua. Por el contrario, la **validación de paréntesis** es más expresiva en su versión **recursiva** al representar bloques dentro de bloques, aunque la iterativa es superior en eficiencia práctica.

### Experimento 1:

Para realizar las pruebas del **Experimento 1**, se utilizó el archivo base `Libreria_cc232/Semana4/demos/demo_base_conversion.cpp`.

### Código original:
```cpp
#include <iostream>
#include "BaseConversion.h"

int main() {
    const unsigned long long n = 12345;
    std::cout << "12345 en base 8 (recursivo) = " << ods::toBaseRecursive(n, 8) << "\n";
    std::cout << "12345 en base 8 (iterativo) = " << ods::toBaseIterative(n, 8) << "\n";
    return 0;
}
```

### Metodología de modificación:

Para cada uno de los casos de la tabla, se modificaron exactamente dos valores directamente en el código antes de compilar y ejecutar:

1.  **El valor de la variable `n`**: Se reemplazó `12345` por el número a evaluar (ej. 255, 2748).
2.  **El segundo argumento** de las funciones `toBaseRecursive` y `toBaseIterative`: Se reemplazó el `8` estático por la base de destino deseada (ej. 2, 16).

**Ejemplo de código modificado para la Prueba 2 (Hexadecimal):**

```cpp
#include <iostream>
#include "BaseConversion.h"

int main() {
    const unsigned long long n = 2748;
    std::cout << "2748 en base 16 (recursivo) = " << ods::toBaseRecursive(n, 16) << "\n";
    std::cout << "2748 en base 16 (iterativo) = " << ods::toBaseIterative(n, 16) << "\n";
    return 0;
}
```

### Tabla de Resultados: Experimento 1 

| Número (n) | Base | Salida recursiva | Salida iterativa | ¿Coinciden? | Comentario analítico |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **255** | 2 (Binario) | 11111111 | 11111111 | **Sí** | Validamos el límite de un byte completo (8 bits en 1). Ambas lógicas procesan correctamente los residuos idénticos. |
| **2748** | 16 (Hex) | ABC | ABC | **Sí** | Comprobamos que el arreglo estático `digit[]` mapea correctamente los residuos puros mayores a 9 hacia caracteres alfabéticos. |
| **100** | 8 (Octal) | 144 | 144 | **Sí** | Caso estándar intermedio. Confirma que la base 8 funciona sin alterar la lógica de extracción matemática. |
| **42** | 5 | 132 | 132 | **Sí** | Prueba con una base no tradicional. El algoritmo matemático (división y residuo) es universal y no depende de potencias de 2. |
| **0** | 10 (Decimal) | 0 | 0 | **Sí** | Caso borde fundamental. Ambas funciones tienen una condición explícita para evitar devolver cadenas vacías cuando la entrada es nula. |

### Experimento 2:

Para realizar las pruebas del **Experimento 2**, se utilizó el archivo `Libreria_cc232/Semana4/demos/demo_paren_rpn.cpp`.

### Código original:

```cpp
#include <iostream>
#include "ExpressionEvaluator.h"
#include "Parentheses.h"

int main() {
    const std::string expr = "(0!+1)*2^(3!+4)-(5!-67-(8+9))";
    const auto evaluated = ods::evaluateExpression(expr);

    std::cout << "Parentesis balanceados (iterativo) = "
              << std::boolalpha << ods::parenIterative(expr) << "\n";
    return 0;
}
```

### ¿Qué se modificó?

1.  **La variable `expr`**: Se reemplazó la expresión original por cada una de las cadenas de prueba.
2.  **La impresión de resultados**: Se agregó una línea extra para imprimir el resultado de la función recursiva (`ods::parenRecursive`) y comparar ambos booleanos.

**Ejemplo de código modificado para la Prueba 5 (Cruce incorrecto):**

```cpp
#include <iostream>
#include "Parentheses.h"

int main() {
    const std::string expr = "([)]"; 

    std::cout << "Recursivo: " << std::boolalpha << ods::parenRecursive(expr) << "\n";
    std::cout << "Iterativo: " << std::boolalpha << ods::parenIterative(expr) << "\n";

    return 0;
}
```

### Tabla de Resultados: Experimento 2


| Caso requerido | Expresión de prueba | Res. Recur. | Res. Iter. | ¿Coinciden? | Explicación del caso |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Vacía** | `""` | true | true | **Sí** | La ausencia de símbolos implica que no hay cierres pendientes; está balanceada por defecto. |
| **Sin paréntesis** | `"hola + mundo"` | true | true | **Sí** | El código ignora caracteres alfanuméricos. Al no haber símbolos de apertura, no se viola ninguna regla. |
| **Correctamente anidada**| `"a * (b + c)"` | true | true | **Sí** | Flujo estándar. Se abre un bloque, se guarda en memoria y se cierra adecuadamente. |
| **Con desbalance** | `"(a + b) )"` | false | false | **Sí** | Exceso de cierres. La versión iterativa intenta hacer `pop()` a una pila vacía y falla de inmediato. |
| **Cruce incorrecto** | `"([)]"` | false | false | **Sí** | La pila iterativa detecta que el tope es `[` pero el texto exige cerrar un `)`. |
| **Varios tipos** | `"{ [ ( a ) ] }"` | true | true | **Sí** | La iterativa valida el orden estricto. La recursiva da true por casualidad al validar solo el `(a)` interno. |
| **Larga** | `"((((a))))"` | true | true | **Sí** | Profundidad alta. La iterativa acumula 4 elementos en pila; la recursiva crea 4 niveles de llamadas al sistema. |
| **Inventada (Trampa)** | `"{ ( } )"` | true | **false** | **NO** | **Falla de diseño:** `parenRecursive` ignora que la llave `}` rompe la lógica interna. Solo la versión **iterativa** es 100% robusta aquí. |

## Bloque 5 - Evaluación de expresiones y prioridad de operadores

### Material de Revisión:

- `Semana4/include/OperatorPriority.h`
- `Semana4/include/ExpressionEvaluator.h`
- `Semana4/demos/demo_paren_rpn.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

### 1. Explica qué información guarda `EvaluationResult`.

Guarda dos elementos fundamentales: el **resultado numérico** final del cálculo (`value`) y la versión de texto de esa misma expresión traducida a **Notación Polaca Inversa** (`rpn`).

### 2. Explica por qué primero se eliminan espacios.

Se realiza para "limpiar" los datos y facilitar el **análisis sintáctico** (*parsing*). De esta forma, el algoritmo avanza analizando los caracteres uno tras otro sin necesidad de incluir lógica extra para saltarse los espacios en blanco entre los números y los símbolos.

### 3. Explica cómo se detecta el signo menos unario.

El algoritmo deduce la función del guion `-` observando su entorno. Identifica que es un **signo unario** (negativo) si está al principio de la expresión, o si está inmediatamente precedido por un paréntesis de apertura u otro operador matemático (por ejemplo, en la secuencia `* - 5`).

### 4. Explica por qué el factorial se trata como operador unario y qué restricción impone el código.

El factorial (`!`) es unario porque afecta a un solo valor. El código impone una **restricción matemática estricta**: obliga a que el operando sea un **número entero**, lanzando una excepción si se intenta calcular el factorial de un decimal puro (como `3.14!`).

### 5. Explica cómo la RPN se va construyendo durante la evaluación y no al final.

A medida que el algoritmo recorre la fórmula, escribe los números directamente en la cadena **RPN**. Los operadores se agregan a la cadena RPN en el instante exacto en que son expulsados de la pila para ser calculados, reflejando el **orden temporal real** de las operaciones.

### 6. Explica qué significa la relación entre operador del tope y símbolo actual.

Esta relación de precedencia es el "**semáforo**" lógico del algoritmo. Si el símbolo actual es "más fuerte" (ej. `*` sobre `+`), entra a la pila. Si el tope de la pila es más fuerte o igual, este sale y se ejecuta. Si la relación es de igualdad estructural (como `(` y `)`), los símbolos se cancelan entre sí.

### 7. Explica por qué una expresión mal formada debe terminar en error y no en un valor arbitrario.

Forzar un resultado arbitrario ante una fórmula mal escrita es peligroso porque oculta errores lógicos graves. Interrumpir el flujo lanzando un **error o excepción** protege la integridad de los datos del sistema y asegura la validez de los cálculos.

### 8. ¿Qué ventaja conceptual tiene obtener a la vez el valor y la RPN?

Demuestra que comprender la estructura lógica de una expresión (RPN) y calcular su resultado son el mismo problema algorítmico. Aprovechando el uso de **pilas**, con una sola lectura lineal del texto se resuelven ambas necesidades, optimizando el tiempo de ejecución.

### Experimento 3:

A continuación, se presenta la tabla con la ejecución de los casos diseñados para poner a prueba el motor de evaluación y la generación de la **Notación Polaca Inversa (RPN)**.

### Tabla de Resultados: Experimento 3

| Caso | Expresión | RPN Obtenida | Valor / Error obtenido | Explicación breve |
| :--- | :--- | :--- | :--- | :--- |
| **Válida sin paréntesis (1)** | `10 + 2 * 3` | 10 2 3 * + | 16 | La multiplicación tiene mayor prioridad; el operador `*` se ejecuta antes que el `+`. |
| **Válida sin paréntesis (2)** | `8 / 2 - 1` | 8 2 / 1 - | 3 | La división tiene precedencia y se evalúa de izquierda a derecha antes de la resta. |
| **Válida con anidamiento (1)** | `(4 + 5) * 2` | 4 5 + 2 * | 18 | El cierre `)` fuerza a que el operador `+` salga de la pila y se ejecute antes del `*`. |
| **Válida con anidamiento (2)** | `3 ^ (2 + 1)` | 3 2 1 + ^ | 27 | El bloque en paréntesis aísla la suma. El resultado (3) queda como exponente pendiente. |
| **Con menos unario** | `-5 + 3` | -5 3 + | -2 | `isUnaryMinus` detecta el `-` al inicio y lo fusiona con el número como operando `-5`. |
| **Inválida (Matemática)** | `7 / 0` | (Genera error) | Error: "division entre cero" | La función `calcu()` intercepta el divisor igual a 0.0 y lanza la excepción de seguridad. |

### Extensión Opcional: Agregar el operador Módulo (%)

Para demostrar la extensibilidad del código, se ha incorporado el operador de **módulo** (resto de una división), no contemplado en la base original.

- **Símbolo:** `%`
- **Aridad:** Binario (requiere dos operandos).
- **Prioridad:** Misma jerarquía que la multiplicación (`*`) y división (`/`).

### Casos probados

1.  **Caso válido:** `10 % 3` -> RPN: `10 3 %` -> Valor: **1**
2.  **Caso combinado:** `10 + 5 % 2` -> RPN: `10 5 2 % +` -> Valor: **11**
3.  **Caso inválido:** `10 % 0` -> Lanza `std::runtime_error("modulo por cero")`.

### Modificaciones realizadas

#### 1. En `OperatorPriority.h`:
- Se aumentó la constante de tamaño: `constexpr int N_OPTR = 10;`.
- Se añadió el operador al enumerador: `MOD` justo antes de `L_P`.
- Se expandió la matriz `pri` agregando una fila y columna para `%`, asignando relaciones `>` sobre sumas y `<` frente a potencias.
- En `optr2rank(char op)`, se agregó: `case '%': return MOD;`.

#### 2. En `ExpressionEvaluator.h`:
- En `isOperatorChar(char ch)`, se añadió `case '%':`.
- En `isUnaryMinus`, se actualizó la lógica con `prev == '%'` para permitir expresiones como `10 % -3`.
- En la función `calcu(double a, char op, double b)`, se implementó el comportamiento usando `<cmath>`:

```cpp
case '%':
    if (b == 0.0) throw std::runtime_error("modulo por cero");
    return std::fmod(a, b);
```
