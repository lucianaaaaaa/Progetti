THRtest: THRtest.o 
	g++ -o THRtest THRtest.o
THRtest.o: THRtest.cpp Date.h HeartRates.h
	g++ -c THRtest.cpp -std=c++11