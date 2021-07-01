CC=g++
CFLAGS=-std=c++11
DEPS = Employee.h Date.h
OBJ = Date.o Employee.o test.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)