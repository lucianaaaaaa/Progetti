dateTest: dateTest.o Date.o
		g++ -o dateTest dateTest.cpp Date.cpp
dateTest.o: dateTest.cpp Date.h
		g++ -c dateTest.cpp -std=c++11 -Wall -pedantic
Date.o: Date.cpp Date.h
		g++ -c Date.cpp -std=c++11 -Wall -pedantic