CC=g++
CFLAGS=-g -I/usr/local/include/pbc
DEPS = pbc.h

alt-pRate: alt-pRate.o
	$(CC) -o alt-pRate alt-pRate.o -L/usr/lib/x86_64-linux-gnu -Wl,-rpath /usr/lib/x86_64-linux-gnu -lpbc -lgmp
