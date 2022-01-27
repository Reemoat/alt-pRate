CC=g++
CFLAGS=-I ~/.local/include/pbc -L ~/.local/lib -Wl,-rpath ~/.local/lib -l pbc -lgmp

alt-pRate: alt-pRate.cpp
	$(CC) -o alt-pRate -g alt-pRate.cpp $(CFLAGS)
