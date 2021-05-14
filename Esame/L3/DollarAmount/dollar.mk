dollar: DollarTest.o
	g++ -o dollar DollarTest.o
DollarTest.o: DollarTest.cpp DollarAmount.h
	g++ -c DollarTest.cpp -std=c++11 -Wall -pedantic