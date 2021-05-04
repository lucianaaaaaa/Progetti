StudentTest: Student.o
	g++ -o StudentTest Student.o
Student.o: Student.cpp Student.h
	g++ -Wall -pedantic -std=c++11 -c Student.cpp