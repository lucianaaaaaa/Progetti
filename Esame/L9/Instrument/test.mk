CC=g++
CFLAGS=-std=c++11
DEPS = Instrument.h Brass.h Stringed.h Wind.h
OBJ = test.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)