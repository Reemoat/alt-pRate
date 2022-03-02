CC=g++
CFLAGS=-I ~/.local/include/pbc -L ~/.local/lib -Wl,-rpath ~/.local/lib -l pbc -lgmp

alt-pRate: generate_issuing_key.cpp
	$(CC) -o geni -g generate_issuing_key.cpp $(CFLAGS)
