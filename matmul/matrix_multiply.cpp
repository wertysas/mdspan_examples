
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

#include "experimental/mdspan"
#include "matrix_helpers.hpp"
#include "matrix_multiply.hpp"

int main() {
   
    const int matrix_dim= 5;
    std::vector<double> Av(matrix_dim*matrix_dim);
    std::vector<double> Bv(matrix_dim*matrix_dim, 0);
    std::vector<double> Cv(matrix_dim*matrix_dim, 0);

    // Initialize Av to random vector
    const auto seed = 2417;
    std::mt19937 rng(seed);
    auto normal = std::normal_distribution(5.0, 1.0);
    for (auto& a: Av) {
        a = normal(rng);
    }

    // Static mdspan objects to hold the matrices
    stdex::mdspan A(Av.data(), matrix_dim, matrix_dim);
    stdex::mdspan B(Bv.data(), matrix_dim, matrix_dim);
    stdex::mdspan C(Cv.data(), matrix_dim, matrix_dim);
    
    // Set B to Identity Matrix
    for (int i=0; i<B.size(); i++) { B(i,i) = 1.0; }
    

    // print matrices
    std::cout << "\n\t MATRIX A:" << std::endl;
    print_matrix(A);
    std::cout << "\n\t MATRIX B:" << std::endl;
    print_matrix(B);
    std::cout << "\n\t MATRIX C:" << std::endl;
    print_matrix(C);

    // Applying Matrix Kernel C+=A*B result after should be C = A
    std::cout << std::string( 80, '-') << "\n\t Applying gemm kernel C += A*B" << std::endl;
    MyGemm(A, B, C);
    std::cout << std::string(80, '-') << std::endl;

    // print matrices again 
    std::cout << "\n\t MATRIX A:" << std::endl;
    print_matrix(A);
    std::cout << "\n\t MATRIX B:" << std::endl;
    print_matrix(B);
    std::cout << "\n\t MATRIX C:" << std::endl;
    print_matrix(C);


}
