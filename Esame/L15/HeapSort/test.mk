CC=g++
CFLAGS=-std=c++11
OBJ = heapSort.o

%.o: %.cpp 
		$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)