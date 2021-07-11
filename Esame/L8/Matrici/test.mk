testMat: matrix.o matTest.o
	g++ -o testMat matrix.o matTest.o
matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp -std=c++11 -Wall -pedantic
matTest.o: matTest.cpp matrix.h
	g++ -c matTest.cpp -std=c++11 -Wall -pedantic