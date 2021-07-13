CC=g++
CFLAGS=-std=c++11
DEPS = ClientData.h
OBJ = ClientData.o transaction.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

transaction: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)