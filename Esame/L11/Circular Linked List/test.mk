CC=g++
CFLAGS=-std=c++11
DEPS = CLinkedLIst.h CNode.h
OBJ = test.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)