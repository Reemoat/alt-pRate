CC=g++
CFLAGS=-I ~/.local/include/pbc -L ~/.local/lib -Wl,-rpath ~/.local/lib -l pbc -lgmp

setup: setup.cpp ../public/public_parameters.cpp
	$(CC) -o setup -g setup.cpp ../public/public_parameters.cpp $(CFLAGS)

