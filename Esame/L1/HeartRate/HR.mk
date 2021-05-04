HR: HR.o
	g++ -o HR HR.o
HR.o: HR.cpp
	g++ -c HR.cpp -std=c++11 -Wall -pedantic