# Reporte de Profiling y Benchmark

Para el bloque experimental, nos propusimos demostrar que entender cómo funciona una estructura de datos por debajo tiene mucho más impacto que solo activarle optimizaciones mágicas al compilador.

### Benchmark: `push_back` vs `reserve`
Diseñamos un experimento midiendo el tiempo exacto que tarda la computadora en insertar 10 millones de números dentro de un `std::vector`.

* Tiempo insertando datos a ciegas (solo `push_back`): **~17.40 ms**
* Tiempo avisándole al vector cuánta memoria iba a necesitar (`reserve`): **~7.06 ms**

**Conclusión:** Solo con entender cómo el vector reasigna su memoria dinámicamente, y avisarle mediante `reserve()` cuánto espacio íbamos a usar, redujimos el tiempo a menos de la mitad. El buen diseño le ganó a la fuerza bruta.

### Resultados de Profiling (`gprof`)
Al analizar la ejecución del programa con la herramienta `gprof`, comprobamos en la práctica la teoría de la clase. 

Dado que la Búsqueda Binaria tiene una complejidad logarítmica de $O(\log n)$, el procesador la resuelve a tal velocidad que el tiempo de ejecución registrado es prácticamente **0.00 segundos**. Esto nos demostró que casi la totalidad del tiempo real de CPU se gasta en la tarea lineal ($O(n)$) de inicializar y poblar el arreglo de prueba, no en la búsqueda matemática en sí.