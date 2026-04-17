# Práctica Calificada 1: Estructuras de Datos y Algoritmos (CC232)

**Integrantes:**
* Axel Alberto Reyes Baldeon 
* Andre Dylan Chumbimuni Ricci

**Problema Asignado:** [704. Binary Search - LeetCode](https://leetcode.com/problems/binary-search/)

---

## 1. Análisis del Problema y Algoritmo

### Especificación

* **Entrada:** Un arreglo de enteros `nums` ordenado ascendentemente y un entero `target`.
* **Salida:** El índice del `target` si existe; de lo contrario, `-1`.
* **Tamaño de entrada relevante ($n$):** La cantidad de elementos en el arreglo `nums`.

### Descripción de la Solución

Implementamos una Búsqueda Binaria de forma **iterativa** utilizando un bucle `while`. La estrategia consiste en calcular el punto medio del subarreglo actual y comparar el valor en esa posición con el `target`. Dependiendo del resultado, descartamos la mitad izquierda o derecha, reduciendo el espacio de búsqueda a la mitad en cada paso hasta encontrar el elemento o cruzar los punteros.

### Propiedades del Algoritmo

* **Determinismo:** El algoritmo es determinista, ya que para una misma entrada siempre sigue la misma secuencia de particiones y comparaciones.
* **Factibilidad:** Con un máximo de 10,000 elementos, el algoritmo es altamente factible, utiliza máximo 14 comparaciones.
* **Finitud:** Se garantiza la finitud porque en cada iteración el intervalo `[left, right]` se reduce estrictamente, convergiendo a una condición donde `left > right`, terminando el bucle.
* **Correctitud:** Basada en el **invariante de bucle**: "Si el target está en el arreglo, siempre cumple que esté en `[left, right]`". Se utiliza la **monotonicidad** del arreglo ordenado (estrictamente creciente) para descartar mitades de forma segura.

### Complejidad Computacional

* **Temporal (Peor Caso):** $O(\log n)$ (cuando el elemento no está o se encuentra en los extremos de la partición).
* **Temporal (Mejor Caso):** $\Omega(1)$ (si el elemento está exactamente en el centro en el primer intento).
* **Temporal (Promedio):** $O(\log n)$
* **Espacial:** $O(1)$ (solo utiliza variables enteras auxiliares `left`, `right` y `mid`).
* **Jerarquía de crecimiento:** Se ubica en la categoría logarítmica, siendo inmensamente más eficiente que la jerarquía lineal $O(n)$.

### Robustez y Diseño

* **Alternativa ingenua:** Búsqueda lineal con complejidad $O(n)$, la cual recorre elemento por elemento. Por ejemplo, si queremos encontrar un elemento en 10,000 elementos, se requerirían 10,000 comparaciones en el peor caso, frente a las 14 comparaciones máximas de la búsqueda binaria.
* **Discusión de robustez y degeneración:** Ante arreglos vacíos o con un solo elemento, el algoritmo es robusto y no falla. El caso de degeneración (fallo) ocurriría únicamente si la precondición se rompe y el arreglo no está ordenado.
* **Reutilización:** La lógica está encapsulada y se puede adaptar fácilmente mediante plantillas (templates) para cualquier tipo de dato que soporte operadores de comparación.

### Instrucciones de Ejecución

Para compilar y ejecutar todo el proyecto usando **CMake**, abre tu terminal en la raíz del proyecto y ejecuta:

* **1. Crear y entrar a la carpeta de compilación:**

* **Compilacion en Cmake(en carpeta build):** 
```bash
cmake ..
cmake --build .
```
* **Ejecutar:**
```bash
./run_bench
```
* **Ctest:**
```bash
ctest -V
```
---

## 2. Evidencia Experimental

### Comparación de Builds (Compilación)
| Build | Bandera | Tamaño del Ejecutable | Observaciones |
|-------|---------|-----------------------|---------------|
| Depuración | `-O0` | 151 KB | Fácil de depurar, sin optimizaciones. |
| Compacto | `-Os` | 140 KB | Optimizado para espacio. |
| Release | `-O2` | 137 KB | El más ligero y rápido. |

### Profiling y Cobertura

* **Profiling (`gprof`):** El tiempo se concentra en la creación de la entrada $O(n)$; la búsqueda en sí es tan rápida que el profiler la registra en cerca de 0.00s debido a su eficiencia logarítmica.
* **Cobertura:** 100% de líneas y ramas cubiertas mediante el uso de `<cassert>`. Se probaron casos normales (happy path), bordes (arreglos vacíos y de 1 elemento) y fallidos (trampas matemáticas).
* **Observación de Sanitizers:** Al probar en entornos compatibles, ASan y UBSan no detectaron errores de memoria, confirmando la robustez de la solución matemática (como el cálculo anti-overflow del punto medio) en el manejo de índices.

### Microoptimización vs Algoritmo

Diseñamos un benchmark (usando la librería `<chrono>`) para medir el impacto de la preasignación de memoria. Comparamos el tiempo de inserción de 10 millones de enteros en un `std::vector` de forma ingenua versus usar la función de reserva de memoria de la STL:
* **Sin reserve (inserción ingenua con `push_back`):** 73.31 ms (promedio)
* **Con reserve (preasignación de memoria):** 59.89 ms (promedio)

* **Conclusión:** La elección correcta de herramientas de la STL (`reserve`) tuvo un impacto de mejora masivo, evitando reasignaciones internas por debajo de la mesa. Esto superó ampliamente los escasos kilobytes o milisegundos ahorrados por cualquier bandera de compilación.

### 3. Uso de GitHub Copilot

* **Uso:** Se utilizó como asistente de autocompletado para la generación de la estructura base de los archivos de prueba (`tests.cpp`), la redacción del boilerplate inicial de `CMakeLists.txt`, y consultas rápidas sobre comandos de Git y configuración de builds.

* **Validación:** No se aceptó código a ciegas. Se validó estrictamente mediante la revisión lógica de los asserts y garantizando que los casos borde fueran cubiertos manualmente. Asimismo, se corrigieron y ajustaron las sugerencias de código de la IA para asegurar que implementaran el cálculo de `mid = left + (right - left) / 2`, evitando así el *integer overflow* que las sugerencias básicas solían pasar por alto.