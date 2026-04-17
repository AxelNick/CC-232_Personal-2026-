#include <iostream>
#include <vector>
#include <chrono>

// Función auxiliar para medir el tiempo de inserción
double measureInsertionTime(int n, bool useReserve) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> nums;
    
    // Si la bandera es verdadera, pre-asignamos la memoria
    if (useReserve) {
        nums.reserve(n);
    }

    // Llenamos el vector
    for (int i = 0; i < n; i++) {
        nums.push_back(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    return duration.count();
}

int main() {
    const int N = 10000000; // 10 millones de elementos

    std::cout << "--- Benchmark: push_back vs reserve ---\n";
    std::cout << "Elementos a insertar: " << N << "\n\n";

    // Ejecutamos ambas pruebas
    double timeWithout = measureInsertionTime(N, false);
    double timeWith = measureInsertionTime(N, true);

    // Mostramos los resultados
    std::cout << "> Tiempo normal (sin reserve): " << timeWithout << " ms\n";
    std::cout << "> Tiempo optimizado (con reserve): " << timeWith << " ms\n";

    return 0;
}