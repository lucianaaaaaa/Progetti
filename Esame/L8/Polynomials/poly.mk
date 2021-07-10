polyTest: polyTest.o Poly.o
		g++ -o polyTest polyTest.cpp Poly.cpp
polyTest.o: polyTest.cpp Poly.h
		g++ -c polyTest.cpp -std=c++11 -Wall -pedantic
Poly.o: Poly.cpp Poly.h
		g++ -c Poly.cpp -std=c++11 -Wall -pedantic