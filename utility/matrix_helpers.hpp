#include <__random/uniform_random_bit_generator.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include "experimental/mdspan"


namespace stdex = std::experimental;

// Print Matrix Function
template <typename T, typename Exts, typename Lay, typename Acc>
void print_matrix(stdex::mdspan<T, Exts, Lay, Acc> m) {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    for (int i=0; i<m.extent(0); i++) {
        std::cout << "| ";
        for (int j=0; j<m.extent(1); j++) {
            std::cout << m(i,j) << " ";
        }
        std::cout << " |\n";
    }
    std::cout << std::endl;
}




