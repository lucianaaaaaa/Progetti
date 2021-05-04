
InsertionTest: InsertionTest.o Insertion.o
	g++ InsertionTest.o Insertion.o -o InsertionTest 

Insertion.o: Insertion.cpp Insertion.h
	g++ -c Insertion.cpp -std=c++11 -Wall -Wextra -Werror -pedantic

InsertionTest.o: InsertionTest.cpp Insertion.h
	g++ -c InsertionTest.cpp -std=c++11 -Wall -Wextra -Werror -pedantic
