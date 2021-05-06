CC=g++
CFLAGS=-std=c++11
DEPS = BasicVector.h BasicVector.cpp
OBJ = VectorTest.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

VectorTest: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)
