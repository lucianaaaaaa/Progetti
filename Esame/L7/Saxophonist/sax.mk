CC=g++
CFLAGS=-std=c++11
DEPS = Saxophonist.h
OBJ = sax.cpp

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

sax: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)