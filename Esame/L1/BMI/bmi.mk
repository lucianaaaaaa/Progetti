bmi: bmi.o
	g++ -o bmi bmi.o
bmi.o: bmi.cpp
	g++ -c bmi.cpp -std=c++11 -Wall -pedantic