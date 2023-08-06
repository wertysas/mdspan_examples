include ../common.mk

UTIL_INC 	:= ../utility
CPPFLAGS   	:= -O3 -I$(MDSPAN_INC) -I$(UTIL_INC) -std=c++20 -march=native
LDFLAGS    	:= -lpthread -m64 -lm

# ---------------------

matmul:
	$(CXX) $(CPPFLAGS) matrix_multiply.cpp -o matmul.x $(LDFLAGS)

clean:
	rm *.x

