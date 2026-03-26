### Preguntas de sustentacion - Semana 2

Esta sustentación busca verificar que el estudiante comprende las ideas centrales de la semana y sabe relacionarlas con las implementaciones desarrolladas en código.

#### 1. Arreglo, memoria contigua y vector

1. ¿Qué significa que un arreglo use memoria contigua?
2. ¿Por qué acceder a `A[i]` es una operación de costo `O(1)`?
3. ¿Qué diferencia hay entre `size` y `capacity`?
4. ¿Por qué un arreglo dinámico necesita espacio libre además de los elementos válidos?
5. ¿Qué ventaja ofrece la memoria contigua frente a una lista enlazada?
6. **[Código]** En `ArrayStackExplicado`, ¿qué invariante debe cumplirse siempre entre `n_` y `capacity_`?

#### 2. ArrayStack y resizing

7. ¿Qué hace `ArrayStack` cuando ya no hay espacio para insertar un nuevo elemento?
8. ¿Por qué `resize()` crea un arreglo nuevo en lugar de "alargar" el mismo bloque?
9. ¿Qué costo tiene una expansión aislada?
10. ¿Por qué `add(size(), x)` puede ser `O(1)` amortizado aunque a veces active una copia completa?
11. **[Código]** En `ArrayStack.h`, ¿por qué `resize()` usa `max(2*n, 1)`?
12. **[Código]** ¿Por qué `add(i, x)` desplaza elementos desde `j = n` hasta `i + 1`?
13. **[Código]** ¿Qué pasa en `remove(i)` y por qué luego puede ejecutarse un `resize()` si `a.length >= 3*n`?
14. **[Código]** En las pruebas públicas, ¿qué propiedades se validan cuando se inserta `99` en medio y luego se elimina?

#### 3. FastArrayStack

15. ¿Qué idea mejora `FastArrayStack` respecto a `ArrayStack`?
16. **[Código]** ¿Qué papel cumplen `std::copy` y `std::copy_backward` en `FastArrayStack`?
17. **[Código]** ¿Por qué `copy_backward` es apropiado al insertar y no `copy` directo?
18. ¿La complejidad asintótica de `FastArrayStack` cambia respecto a `ArrayStack`, o cambia más bien la constante oculta?
19. **[Código]** En la prueba pública, ¿qué se verifica cuando se inserta `7` entre `5` y `6` y luego se elimina el índice `0`?

#### 4. Análisis amortizado

20. ¿Qué diferencia hay entre costo peor caso y costo amortizado?
21. ¿Por qué no basta decir "una inserción a veces cuesta `O(n)`, entonces todas cuestan `O(n)`"?
22. ¿Cómo se reparte el costo de una expansión entre muchas inserciones?
23. ¿Qué pasaría si la capacidad creciera de uno en uno en vez de duplicarse?
24. ¿Por qué usar el umbral `3*n` para reducir evita redimensionamientos demasiado frecuentes?
25. **[Código]** ¿Qué tipo de comportamiento intenta estresar `resize_stress_week2.cpp` cuando inserta cientos de elementos y luego elimina muchos?

#### 5. ArrayQueue y arreglos circulares

26. ¿Qué problema intenta resolver `ArrayQueue` frente a usar un arreglo lineal con corrimientos para una cola?
27. ¿Qué representa el índice `j` en `ArrayQueue`?
28. **[Código]** ¿Por qué `add(x)` escribe en `a[(j+n) % a.length]`?
29. **[Código]** ¿Por qué `remove()` avanza con `j = (j + 1) % a.length` en lugar de desplazar todos los elementos?
30. ¿Por qué se habla de arreglo circular aunque físicamente siga siendo un arreglo lineal?
31. **[Código]** En la prueba extendida, ¿qué propiedad FIFO se confirma cuando salen `1, 2, 3, 4` en ese orden?
32. **[Código]** En la prueba interna extendida, ¿qué demuestra el patrón "entra `1..20`, salen `1..10`, entra `21..30`, salen `11..30`"?

#### 6. ArrayDeque

33. ¿Qué operaciones adicionales permite un deque frente a una cola simple?
34. **[Código]** En `ArrayDeque`, ¿por qué `get(i)` y `set(i, x)` usan `(j+i) % a.length`?
35. **[Código]** ¿Por qué `add(i, x)` decide entre mover la mitad izquierda o la mitad derecha según `i < n/2`?
36. **[Código]** ¿Cuál es la intuición para que un deque mueva el lado más corto?
37. **[Código]** En la prueba pública, ¿qué se verifica cuando se agrega `10`, `30` y luego `20` en el medio?
38. **[Código]** En la prueba interna extendida, ¿qué validan las inserciones `deq.add(0, 100)` y `deq.add(4, 200)`?

#### 7. DualArrayDeque y rebalanceo

39. ¿Qué idea central tiene `DualArrayDeque`?
40. **[Código]** ¿Por qué `front` guarda los elementos en orden invertido respecto a la vista lógica?
41. **[Código]** ¿Cómo se explica que `get(i)` use `front.get(front.size() - i - 1)` en la parte delantera?
42. **[Código]** ¿Cuándo se activa `balance()` y por qué la condición usa un factor `3` entre ambos lados?
43. **[Código]** ¿Qué ocurre durante el rebalanceo con `nf = n/2` y `nb = n - nf`?
44. **[Código]** En la prueba pública, ¿qué propiedad se verifica cuando `dual` contiene `5, 6, 7` y luego se elimina el del medio?
45. **[Código]** En la prueba interna extendida, ¿qué intenta comprobar la secuencia de insertar 40 elementos y luego borrar 10 del inicio y 10 del final?

#### 8. RootishArrayStack

46. ¿Qué problema de espacio intenta mejorar `RootishArrayStack` frente a `ArrayStack`?
47. ¿Por qué en `RootishArrayStack` los bloques tienen tamaños `1, 2, 3, ..., r`?
48. **[Código]** ¿Por qué la capacidad total con `r` bloques es `r(r+1)/2`?
49. **[Código]** ¿Qué hace la función `i2b(i)` y por qué necesita una fórmula con raíz cuadrada?
50. **[Código]** ¿Cómo se obtiene el offset local `j = i - b*(b+1)/2` dentro del bloque?
51. ¿Por qué `RootishArrayStack` ya no depende de un único bloque contiguo de memoria?
52. **[Código]** ¿Qué ocurre en `grow()` y `shrink()`?
53. **[Código]** En la prueba pública, ¿qué se comprueba cuando se hace `set(4, 40)` después de insertar 6 elementos?
54. **[Código]** En la prueba interna extendida, ¿qué valida que luego de `remove(10)` el elemento en `get(10)` pase a ser `22`?

#### 9. FastSqrt como apoyo matemático

55. ¿Por qué aparece `FastSqrt` dentro de una semana sobre estructuras basadas en arreglo?
56. **[Código]** ¿Qué relación tiene `FastSqrt` con el cálculo de bloques en `RootishArrayStack`?
57. **[Código]** ¿Qué valida la prueba pública al comparar `FastSqrt::sqrt(x)` con `floor(sqrt(x))` en varios valores?
58. **[Código]** ¿Qué aporta la prueba interna que recorre todos los valores entre `0` y `50000`?

#### 10. Preguntas integradoras

59. Explica la relación entre memoria contigua, `resize()`, costo amortizado y `ArrayStack`.
60. Compara `ArrayStack`, `ArrayQueue` y `ArrayDeque` en términos de corrimientos y uso de índices modulares.
61. Compara `ArrayDeque` y `DualArrayDeque`: ¿qué gana cada uno y qué complica cada uno?
62. Compara `ArrayStack` y `RootishArrayStack` en tiempo, simplicidad y desperdicio espacial.
63. ¿Qué estructuras de semana 2 dependen directamente de la idea de arreglo circular?
64. ¿Qué estructuras de semana 2 dependen directamente de redimensionamiento amortizado?
65. ¿Cuál dirías que es la idea más importante de la semana: contigüidad, circularidad, rebalanceo o amortización? Sustenta tu respuesta.
