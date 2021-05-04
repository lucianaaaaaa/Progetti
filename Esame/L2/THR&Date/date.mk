date: dateTest.o 
	g++ -o date dateTest.o
dateTest.o: dateTest.cpp Date.h
	g++ -c dateTest.cpp -std=c++11