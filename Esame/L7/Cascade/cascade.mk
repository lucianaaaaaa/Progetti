CC=g++
CFLAGS=-std=c++11
DEPS = Time.h
OBJ = Time.cpp cascade.cpp

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

cascade: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)