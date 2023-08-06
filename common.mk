
# Blas library include file (only neccessary for benchmarks)
BLAS_LIB  := /usr/local/lib/libblis.a
BLAS_INC  := /usr/local/include/blis

# this forces to include mdspan/mdspan.hpp, which is good in case there is a conflicting name of
# the header file with a file from a different include dir
MDSPAN_INC	:= /Users/johan/code/libs/mdspan/include

# Compilers and Linkers
CXX			:= clang++
LINKERXX	:= $(CXX)
