// #define alpha(i, j) A[ (j)*ldA + i ]   // map alpha( i,j ) to array A
// #define beta(i, j)  B[ (j)*ldB + i ]   // map beta( i,j )  to array B
// #define gamma(i, j) C[ (j)*ldC + i ]   // map gamma( i,j ) to array C

#include <vector>
#include <iostream>
#include <iomanip>
#include "experimental/mdspan"


namespace stdex = std::experimental;

template <typename T, typename IndexType=size_t>
using dynamic_matrix = stdex::mdspan<T, stdex::extents<size_t, std::dynamic_extent, std::dynamic_extent>>;

template <typename T, typename IndexType=size_t>
using static_matrix = stdex::mdspan<T, stdex::extents<IndexType, 1, 2>>;

enum class LoopOrder {
    IJP,
    IPJ,
    JIP,
    JPI,
    PIJ,
    PJI
};


template <typename T,
        typename ExtsA, typename LayA, typename AccA,
        typename ExtsB, typename LayB, typename AccB,
        typename ExtsC, typename LayC, typename AccC
        >
void MyGemm(stdex::mdspan<T, ExtsA, LayA, AccA> A,
            stdex::mdspan<T, ExtsB, LayB, AccB> B,
            stdex::mdspan<T, ExtsC, LayC, AccC> C) {
    for (int i = 0; i < A.extent(0); i++) {
        for (int j=0; j < B.extent(1); j++) {
            for (int k=0; k < A.extent(1); k++) {
                C(i,j) += A(i,k)*B(k,j);
            }
        }
    }
}

