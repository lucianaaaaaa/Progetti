AccountTest2: AccountTest2.o
	g++ -o AccountTest2 AccountTest2.o
AccountTest2.o: AccountTest2.cpp Account.h
	g++ -Wall -pedantic -std=c++11 -c AccountTest2.cpp