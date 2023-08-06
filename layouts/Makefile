include ../common.mk

UTIL_INC 	:= ../utility
MATMUL_INC	:= ../matmul
CPPFLAGS   	:= -O3 -I$(MDSPAN_INC) -I$(UTIL_INC) -I$(MATMUL_INC) -std=c++20 -march=native

# ---------------------

basic_layouts:
	$(CXX) $(CPPFLAGS) basic_layouts.cpp -o basic_layouts.x

clean:
	rm *.x

