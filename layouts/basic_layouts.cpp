/*
 * Example of mdspans layout_right and layout_left which correspond to
 * row-major and column-major storage order.
 */

#include <iostream>
#include <vector>
#include <random>

#include "experimental/mdspan"
#include "matrix_helpers.hpp"
#include "matrix_multiply.hpp"

namespace stdex = std::experimental;

int main() {
  
    // row-major and column-major vectors representing 3x3 matrices
    std::vector<double> row_major = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<double> col_major = {1, 4, 7, 2, 5, 8, 3, 6, 9};


    // Static mdspan objects to hold the matrices
    stdex::mdspan<double, stdex::extents<int, 3, 3>> A(row_major.data()); // layout_right by default
    stdex::mdspan<double, stdex::extents<int, 3, 3>, stdex::layout_left> B(col_major.data());
    

    // print matrices
    std::cout << "\n\t MATRIX A:" << std::endl;
    print_matrix(A);
    std::cout << "\n\t MATRIX B:" << std::endl;
    print_matrix(B);

}

