CC=g++
CFLAGS=-std=c++11
DEPS = Item.h
OBJ = Item.o emptyStock.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

emptyStock: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)