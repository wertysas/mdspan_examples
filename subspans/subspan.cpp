
#include <iostream>
#include <vector>
#include <random>

#include "experimental/mdspan"
#include "matrix_helpers.hpp"
#include "matrix_multiply.hpp"

namespace stdex = std::experimental;

int main() {
  
    // row-major and column-major vectors representing 3x3 matrices
    std::vector<double> row_major = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12, 13, 14, 15, 16};
    std::vector<double> col_major = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7 , 11, 15, 4, 8, 12, 16};


    // Static mdspan objects to hold the matrices
    stdex::mdspan<double, stdex::extents<int, 4, 4>> A(row_major.data()); // layout_right by default
    stdex::mdspan<double, stdex::extents<int, 4, 4>, stdex::layout_left> B(col_major.data());
    
    // Submdspan object corresponding to upper left 2x2 matrix
   auto Asub = stdex::submdspan(A, std::tuple(0,2), std::tuple(0,2));
   auto Bsub = stdex::submdspan(B, std::tuple(0,2), std::tuple(0,2));
    

    // print matrices
    std::cout << "\n\t MATRIX A:" << std::endl;
    print_matrix(A);
    std::cout << "\n\t MATRIX B:" << std::endl;
    print_matrix(B);
   
    std::cout << "\nSUBMATRICES:" << std::endl;

    std::cout << "\n\t MATRIX Asub:" << std::endl;
    print_matrix(Asub);
    std::cout << "\n\t MATRIX Bsub:" << std::endl;
    print_matrix(Bsub);

}




