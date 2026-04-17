#include "solution.hpp"

// Implementación de la Búsqueda Binaria
int Solution::searchBinary(const std::vector<int>& nums, int target) const{
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
        // calulamos el punto medio para evitar el overflow
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; 
        } 
        else if (nums[mid] < target) {
            left = mid + 1; 
        } 
        else {
            right = mid - 1; 
        }
    }
    return -1; 
}

// Implementación de la Búsqueda Lineal (ingenua)
int Solution::searchLinear(const std::vector<int>& nums, int target) const{
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}