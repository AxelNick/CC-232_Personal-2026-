#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

//La clase que implementa algoritmos de búsqueda.
//Separa la interfaz de la implementación (ADT).

class Solution {
public:
   //Solución Óptima: Búsqueda Binaria,condicionado por ser ordenado, complejidad temporal: O(log n)
  
    int searchBinary(const std::vector<int>& nums, int target) const;

    //Solución Ingenua: Búsqueda Lineal, complejidad temporal: O(n) 
   
    int searchLinear(const std::vector<int>& nums, int target) const;
};

#endif