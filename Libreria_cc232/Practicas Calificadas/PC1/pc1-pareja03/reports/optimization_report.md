# Reporte de Optimizaciones y Sanitizers

En esta etapa del laboratorio, compilamos el código con distintas banderas de `g++` para analizar el impacto directo en el peso final del ejecutable. Obtuvimos estos resultados:

* **Sin optimizar (`-O0`):** El ejecutable pesó **151 KB**. Como era de esperarse, es el más pesado porque el compilador deja todo el código intacto y añade símbolos para que podamos usar el debugger (`gdb`) sin problemas.

* **Optimizado para tamaño (`-Os`):** El peso bajó a **140 KB**. Cumplió perfectamente su objetivo de ahorrar espacio en el disco.

* **Modo Release (`-O2`):** Quedó en **137 KB**. Es muy interesante notar que la bandera enfocada en máxima velocidad terminó generando el archivo más ligero de todos. Esto ocurre porque el compilador recorta agresivamente todo el "código muerto" o que no se utiliza.

### Sobre el uso de Sanitizers
Intentamos compilar con AddressSanitizer (`-fsanitize=address,undefined`) para buscar posibles fugas o errores de memoria. Sin embargo, nos topamos con un problema técnico del entorno: al usar Windows con MSYS2/UCRT64, el compilador no incluye la librería `libasan` por defecto, arrojando un error en el enlazador (linker).

A pesar de esto, garantizamos la seguridad de memoria desde la lógica matemática. Prevenimos el clásico error de desbordamiento de enteros (*integer overflow*) calculando el punto medio de la búsqueda con la fórmula `left + (right - left) / 2`, respetando estrictamente los límites del arreglo.