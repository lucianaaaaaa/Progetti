CC=g++
CFLAGS=-std=c++11
DEPS = ClientData.h
OBJ = ClientData.o createFile.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

createFile: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)