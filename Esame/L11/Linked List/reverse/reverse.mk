CC=g++
CFLAGS=-std=c++11
DEPS = LinkedLIst.h Node.h
OBJ = reverse.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

reverse: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)