timeTest: timetest.o Time.o
		g++ -o timeTest timetest.cpp Time.cpp
timetest.o: timetest.cpp Time.h
		g++ -c timetest.cpp -std=c++11 -Wall -pedantic
Time.o: Time.cpp Time.h
		g++ -c Time.cpp -std=c++11 -Wall -pedantic