#include <iostream>
#include <vector>
#include <cassert>
#include "solution.hpp"

void test_de_busqueda_binaria_basico() {
    Solution sol;
    // 1. Caso Normal (Arrange)

    std::vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    // Act & Assert
    assert(sol.searchBinary(nums1, target1) == 4);
    std::cout << "[PASO] Caso normal: Elemento encontrado en el medio." << std::endl;
}
void test_de_busqueda_binaria_no_encontrada() {
    Solution sol;
    // 2. Casos de No Existencia y Límites Externos

    std::vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    //caso 1: target no existe en el arreglo
    int target2 = -2;
    assert(sol.searchBinary(nums1, target2) == -1);
    //caso 2: target mayor que el último elemento
    int target3 = 100;
    assert(sol.searchBinary(nums1, target3) == -1);
    //caso 3: target menor que el primer elemento
    int target4 = -100;
    assert(sol.searchBinary(nums1, target4) == -1);
    std::cout << "[PASO] Casos de no existencia y limites externos." << std::endl;

}
void test_de_busqueda_binaria_caso_limite() {
    Solution sol;
    // 3. Caso Borde: Arreglo de 1 solo elemento

    std::vector<int> nums2 = {5};
    assert(sol.searchBinary(nums2, 5) == 0);
    assert(sol.searchBinary(nums2, -2) == -1);

    // Caso Borde: Arreglo vacío (sin elemento)
    std::vector<int> empty_vec;
    assert(sol.searchBinary(empty_vec, 5) == -1);
    std::cout << "[PASO] Casos borde: Arreglo de un elemento y sin elementos" << std::endl;
}

int main() {
    std::cout << "Iniciando Pruebas Unitarias" << std::endl;
    
    test_de_busqueda_binaria_basico();
    test_de_busqueda_binaria_no_encontrada();
    test_de_busqueda_binaria_caso_limite();

    std::cout << "Todos los tests pasaron scon exito" << std::endl;
    return 0;
}