CC=g++
CFLAGS=-std=c++11
DEPS = Box.h Container.h LinkedList.h Node.h CLinkedList.h CNode.h Queue.h
OBJ = Box.cpp Container.cpp customs.cpp

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

customs: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)