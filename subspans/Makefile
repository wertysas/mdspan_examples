include ../common.mk

UTIL_INC 	:= ../utility
MATMUL_INC	:= ../matmul
CPPFLAGS   	:= -O3 -I$(MDSPAN_INC) -I$(UTIL_INC) -I$(MATMUL_INC) -std=c++20 -march=native

# ---------------------

subspan:
	$(CXX) $(CPPFLAGS) subspan.cpp -o subspan.x

clean:
	rm *.x

