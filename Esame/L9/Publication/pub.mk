CC=g++
CFLAGS=-std=c++11
DEPS = Publication.h Conference.h Book.h Article.h
OBJ = testpub.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

testpub: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)
