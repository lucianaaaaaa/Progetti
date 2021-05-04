MotorTest: MotorTest.o
	g++ -o MotorTest MotorTest.o
MotorTest.o: MotorTest.cpp MotorVehicle.h
	g++ -Wall -pedantic -std=c++11 -c MotorTest.cpp