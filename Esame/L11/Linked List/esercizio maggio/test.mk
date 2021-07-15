CC=g++
CFLAGS=-std=c++11
DEPS = LinkedLIst.h Node.h
OBJ = doubleList.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)