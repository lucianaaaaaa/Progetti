CC=g++
CFLAGS=-std=c++11
DEPS = Item.h
OBJ = Item.o stock.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

stock: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)