CC=g++
CFLAGS=-I ~/.local/include/pbc -L ~/.local/lib -Wl,-rpath ~/.local/lib -l pbc -lgmp

alt-pRate: distributed_key_gen.cpp
	$(CC) -o geni -g distributed_key_gen.cpp $(CFLAGS)
