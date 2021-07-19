CC=g++
CFLAGS=-std=c++11
DEPS = Box.h Container.h LinkedList.h Node.h Date.h
OBJ = Box.cpp Container.cpp customs.cpp Date.cpp

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

customs: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)