# mdspan_examples

This repo shows some basic usage of mdspan which was voted into the C++ 23 standard. There is a reference implementation by Kokkos available at the kokkos github: [kokkos/mdspan](https://github.com/kokkos/mdspan)

## Overview of examples
- matmul contains an example of using simple matrix-matrix multplication using mdspan for indexing.
- subspans contains an example of tiled matrix-matrix multiply and how comparable code would look with a BLAS like api and leading dimensions. **This really shows how mdspan can simplify code**
- layouts contains various examples showing how to use custom extents and overload templates based on extents.

## Installation/Usage of kokkos/mdspan
