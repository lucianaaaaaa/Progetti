complexTest: complexTest.o Complex.o
		g++ -o complexTest complexTest.cpp Complex.cpp
complexTest.o: complexTest.cpp Complex.h
		g++ -c complexTest.cpp -std=c++11 -Wall -pedantic
Complex.o: Complex.cpp Complex.h
		g++ -c Complex.cpp -std=c++11 -Wall -pedantic