// TicTacToe.h
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <array>
using std::array;
#define N 3


class TicTacToe {
    public:
    //costruttore
    explicit TicTacToe ();

    //input setplayer1
    void setPlayer1 (int x, int y);
    //input setplayer2
    void setPlayer2 (int x, int y);
    //getboard
    void getBoard ();
    //distruttore
    ~TicTacToe ();
    //checkWin
    bool checkWin ();

    private:
    array <array<int,N>,N> board{0};
    bool checkRow(int i);
    bool checkColumn (int j);
    bool checkDiag1 ();
    bool checkDiag2 ();
    bool checkMove (int x, int y);

};

#endif