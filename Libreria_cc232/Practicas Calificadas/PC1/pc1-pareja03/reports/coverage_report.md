# Reporte de Cobertura de Pruebas

Para asegurarnos de que el algoritmo es robusto, escribimos nuestra propia batería de pruebas utilizando la librería estándar `<cassert>`. Estructuramos el código siguiendo el patrón AAA (Arrange, Act, Assert) para que las pruebas sean fáciles de leer y mantener.

Nuestras pruebas cubren el 100% de las ramas lógicas de la función `searchBinary`. Evaluamos tres escenarios clave:

1. **El caso ideal:** Que el programa encuentre el número exacto justo en el medio (esto valida el `if` principal).

2. **Descarte izquierdo/derecho:** Que el algoritmo sepa recortar el arreglo hacia ambos lados correctamente dependiendo de si el número es mayor o menor (valida el `else if` y el `else`).

3. **Casos borde y trampas:** Le pasamos un arreglo de un solo elemento, un arreglo completamente vacío, y le pedimos buscar números exageradamente grandes o negativos que ni siquiera existían en la lista.

En todos los escenarios, el bucle `while` demostró su **finitud**. Siempre terminó la ejecución correctamente y devolvió `-1` cuando no encontró el objetivo, sin quedarse congelado en un bucle infinito ni romper el programa por errores de memoria.