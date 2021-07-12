CC=g++
CFLAGS=-std=c++11
DEPS = Shape.h Rectangle.h Circle.h
OBJ = test.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)