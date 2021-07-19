CC=g++
CFLAGS=-std=c++11
DEPS = Date.h DLinkedList.h DNode.h Measurer.h Measurement.h
OBJ = Date.cpp Measurer.cpp Measurement.cpp driver.cpp

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)