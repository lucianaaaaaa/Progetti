CC=g++
CFLAGS=-std=c++11
DEPS = Point.h Rectangle.h
OBJ = Point.cpp Rectangle.cpp test.cpp

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)