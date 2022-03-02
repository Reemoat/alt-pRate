CC=g++
CFLAGS=-I ~/.local/include/pbc -L ~/.local/lib -Wl,-rpath ~/.local/lib -l pbc -lgmp

alt-pRate: setup.cpp
	$(CC) -o setup -g setup.cpp $(CFLAGS)
