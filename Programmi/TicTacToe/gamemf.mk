game: TicTacToe.o game.o
	g++ -o game TicTacToe.o game.o
TicTacToe.o: TicTacToe.cpp TicTacToe.h
	g++ -c TicTacToe.cpp -std=c++11 -Wall -pedantic
game.o: game.cpp TicTacToe.h
	g++ -c game.cpp -std=c++11 -Wall -pedantic