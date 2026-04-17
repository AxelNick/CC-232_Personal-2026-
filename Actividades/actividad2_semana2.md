# Actividad 2 - Semana 2

## Integrantes
- Axel Alberto Reyes Baldeon
- Andre Dylan Chumbimuni Ricci

## Bloque 0 - Instalación y preparación

- [x] Carpeta de trabajo lista
- [x] Acceso a Semana2, lecturas y archivos de entrega verificados
- [x] Archivo `actividad2_semana2.md` creado
- [x] Compilación y ejecución de demos y pruebas públicas completadas

### Compilación realizada
```bash
cmake -S . -B build
cmake --build build --config Debug
```

### Demo ejecutada
- **sem2_demo_array_basico.exe**
  ```
  array.length = 5
  contenido: 10 20 30 40 50
  antes de la asignacion, b[0] = -1
  despues de b = a, b.length = 5
  b: 10 20 30 40 50
  nota: esta version de array usa una asignacion por transferencia de ownership.
  ```
  **Observación**: Muestra creación de arreglo con 5 elementos, acceso por índice y asignación con transferencia de ownership (no copia profunda).

### Prueba pública ejecutada
```
Test project C:/Users/AXEL/OneDrive/Documentos/Codes/2026_1/Algoritmos y estructura de datos/CC-232-main/cc-232/CC-232/Libreria_cc232/Semana2/build
    Start 1: semana2_public
1/5 Test #1: semana2_public ...................   Passed    0.01 sec
    Start 2: semana2_internal
2/5 Test #2: semana2_internal .................   Passed    0.02 sec
    Start 3: semana2_resize_stress
3/5 Test #3: semana2_resize_stress ............   Passed    0.02 sec
    Start 4: semana2_public_cap2
4/5 Test #4: semana2_public_cap2 ..............   Passed    0.02 sec
    Start 5: semana2_internal_cap2
5/5 Test #5: semana2_internal_cap2 ............   Passed    0.02 sec

100% tests passed, 0 tests failed out of 5
Total Test time (real) =   0.09 sec
```
**Resultado**: **5/5 tests pasaron** - Todas las pruebas públicas e internas funcionan correctamente.

---

## Bloque 1 - Núcleo conceptual de la semana

### Preguntas fundamentales

1. **Memoria contigua**:
   - La memoria contigua significa que los elementos del arreglo se almacenan uno tras otro, ocupando posiciones consecutivas en la RAM sin espacios intermedio. La dirección física de cualquier elemento se calcula mediante una fórmula lineal: `dirección = dirección_base + índice × tamaño_elemento`. Esta característica es el fundamento del acceso directo.

2. **Acceso O(1) a A[i]**:
   - Acceder a un elemento por índice es O(1) porque la CPU puede calcular directamente su dirección de memoria sin necesidad de recorrer elementos anteriores. Dado que el vector es contiguo, la operación se reduce a una simple suma y un acceso a memoria, que son operaciones de hardware con tiempo constante.

3. **Diferencia entre size y capacity**:
   - `size` es la cantidad **lógica** de elementos realmente almacenados en el vector. `capacity` es la cantidad **física** de celdas que han sido reservadas en memoria. La capacidad es siempre ≥ al size. Esta diferencia permite crecer dinámicamente: cuando insertamos, usamos espacio libre antes de expandir.

4. **Por qué resize() necesita un nuevo bloque**:
   - Un arreglo requiere memoria contigua. Cuando la capacidad se agota, no podemos "crecer" en el mismo sitio porque la RAM que viene inmediatamente después puede estar ocupada por otros datos del programa. 
   Por eso `resize()` debe: (1) reservar un nuevo bloque más grande, (2) copiar todos los elementos antiguos al nuevo bloque, (3) liberar el bloque antiguo.


5. **Costo amortizado O(1) con duplicación de capacidad**:
   - Si duplicamos capacidad, entre dos expansiones sucesivas deben ocurrir muchas inserciones. El costo total de expandir a lo largo de n inserciones es O(n) porque las expansiones forman una suma geométrica (costo 1, luego 2, luego 4, 8, 16... que suma ~2n). Repartido entre n operaciones, da O(1) por operación. Si creciéramos por una cantidad fija, necesitaríamos muchas más expansiones.

6. **Comparación ArrayStack vs DengVector**:
   - Ambos implementan un stack con arreglo dinámico. `ArrayStack` (del autor Morin) es una implementación clásica y general que sirve de base para variantes. `DengVector` (del autor Deng) es una implementación de propósito educativo que ilustra explícitamente los conceptos de size, capacity, expand(), shrink() y operaciones como inserción, eliminación y búsqueda. Comparten la misma lógica básica pero DengVector es más completo.

7. **Mejoras de FastArrayStack**:
   - `FastArrayStack` hereda de `ArrayStack` pero reemplaza los bucles manuales de copia y desplazamiento por rutinas optimizadas como `std::copy` y `std::copy_backward`. Esto no cambia la complejidad asintótica, pero mejora significativamente el rendimiento práctico porque esas rutinas están ajustadas a bajo nivel y aprovechan instrucciones especiales del procesador.

8. **Idea espacial de RootishArrayStack**:
   - En lugar de un único arreglo grande, usa múltiples bloques más pequeños de tamaños 1, 2, 3, 4, 5, ... El primer bloque almacena 1 elemento, el segundo 2, el tercero 3, etc. Los bloques se almacenan en un `ArrayStack<T*>` de apuntadores. Esto reduce significativamente el desperdicio de memoria en comparación con duplicar un arreglo grande.

9. **Por qué bloques de tamaños 1, 2, 3, ...**:


10. **Relación entre representación, costo y desperdicio espacial**:
   

---

## Bloque 2 - Demostración y trazado guiado

### Tabla de análisis de demos

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo o espacio |
|---------|--------------------------------|------------------|-----|
| demo_array_basico.cpp | [Pendiente] | [Pendiente] | [Pendiente] |
| demo_arraystack.cpp | [Pendiente] | [Pendiente] | [Pendiente] |
| demo_arraystack_explicado.cpp | [Pendiente] | [Pendiente] | [Pendiente] |
| demo_fastarraystack.cpp | [Pendiente] | [Pendiente] | [Pendiente] |
| demo_rootisharraystack.cpp | [Pendiente] | [Pendiente] | [Pendiente] |
| demo_rootisharraystack_explicado.cpp | [Pendiente] | [Pendiente] | [Pendiente] |
| demo_deng_vector.cpp | [Pendiente] | [Pendiente] | [Pendiente] |
| demo_stl_vector_contraste.cpp | [Pendiente] | [Pendiente] | [Pendiente] |

---

## Bloque 3 - Ejercicios

1. ¿Qué operaciones mínimas valida la prueba pública para ArrayStack?

Inserción: add(x) (agregar al final) y add(i, x) (insertar en un índice específico).

Consulta: size() (obtener la cantidad de elementos) y get(i) (leer un elemento en un índice).

Eliminación: remove(i) (eliminar un elemento en un índice y retornarlo).

2. ¿Qué operaciones mínimas valida la prueba pública para FastArrayStack?

Para ods::FastArrayStack, la prueba pública valida exactamente lo mismo que el anterior, pero usando exclusivamente la inserción por índice:

Inserción: add(i, x) (usado tanto para insertar al final usando s.size() como en posiciones intermedias).

Consulta: size() y get(i).

Eliminación: remove(i).

3. ¿Qué operaciones mínimas valida la prueba pública para RootishArrayStack?

Para ods::RootishArrayStack, la prueba introduce una operación adicional de modificación:

Inserción: add(i, x) (dentro de un bucle).

Consulta: size() y get(i).

Modificación: set(i, x) (sobreescribir un valor existente y retornar el antiguo).

Eliminación: remove(i).

4. ¿Qué sí demuestra una prueba pública sobre una estructura?

Una prueba pública demuestra que la estructura cumple con el happy path y los requisitos de interfaz básicos. 

Confirma que:

- El código compila correctamente.
- Los métodos existen con las firmas esperadas.
- La lógica básica de las operaciones funciona para casos de uso pequeños y secuenciales (las precondiciones y postcondiciones elementales se cumplen).

5. ¿Qué no demuestra una prueba pública?

No demuestra la robustez ni la eficiencia del código bajo condiciones reales o extremas. Específicamente, no garantiza:

- Complejidad algorítmica: Que las operaciones se ejecuten en el tiempo esperado (ej. O(1) vs O(n)).
- Manejo de memoria: Que la estructura libere la memoria adecuadamente o redimensione sus arreglos sin causar fugas o corrupción.
- Casos borde: Qué ocurre al pedir un índice fuera de rango o eliminar elementos en una lista vacía.

6. En resize_stress_week2.cpp, ¿qué comportamiento intenta estresar sobre crecimiento, reducción o estabilidad?

Este archivo está diseñado para estresar la lógica de redimensionamiento de los arreglos subyacentes (grow y shrink). Al forzar la inserción masiva de cientos de elementos (crecimiento) seguida de la eliminación masiva (reducción), la prueba verifica que:

La estructura pueda reasignar memoria dinámicamente y copiar los datos sin perderlos ni corromperlos.

El cálculo del tamaño de los nuevos arreglos sea correcto tanto al expandirse (para no quedarse sin espacio) como al contraerse (para no desperdiciar memoria excesiva).

7. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes y complejidad?

Porque las pruebas evalúan el resultado empírico, pero la explicación de invariantes y complejidad justifica el diseño.

Puedes escribir un ArrayStack donde add(i, x) tarde O(n^2) debido a una mala implementación del copiado de arreglos, o donde el arreglo nunca se encoja (shrink). El código pasaría la prueba pública sin problemas porque el estado final es correcto, pero sería un desastre en un entorno de producción. Explicar los invariantes demuestra que entiendes por qué la estructura siempre es segura, y el análisis de complejidad demuestra que entiendes cómo escala matemáticamente.

---

## Bloque 4 - Defensa

1. ¿Qué papel cumplen `_size`, `_capacity` y `_elem`?

- `_elem` : apunta al arreglo interno 
- `_size` : registra el número real de elementos válidos
- `_capacity` : indica cuántas celdas han sido reservadas.

2. ¿Cuándo debe ejecutarse `expand()`?

DEbe ejecutarse antes de una inserccion si el tamaño actual alcanza su maxcima capacidad 
3. ¿Por qué `insert(r, e)` necesita desplazar elementos?
4. ¿Qué diferencia conceptual hay entre `remove(r)` y `remove(lo, hi)`?
5. ¿Qué evidencia de copia profunda aparece en la demo?
6. ¿Por qué `traverse()` es una buena interfaz didáctica?
7. ¿Qué ventaja tiene implementar un vector propio antes de depender de `std::vector`?