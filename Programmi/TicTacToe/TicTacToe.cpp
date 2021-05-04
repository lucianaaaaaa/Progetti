#include "TicTacToe.h"
#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;

//costruttore
TicTacToe::TicTacToe (): board{0} {
    cout << "Constructor runs" << endl;
    }

//distruttore
TicTacToe::~TicTacToe () {
    cout << "Destructor runs" << endl;
}

//mossa del giocatore 1
void TicTacToe::setPlayer1 (int x, int y) {
    cout << "Mossa del giocatore 1: " <<x << ", " << y << endl;
    if (checkMove(x,y)==false) {
        throw std::invalid_argument("");
    }
    else
    board[x][y]=1;
}

//mossa del giocatore 2
void TicTacToe::setPlayer2 (int x, int y) {
    cout << "Mossa del giocatore 2: " <<x << ", " << y << endl;
    if (checkMove(x,y)==false) {
        throw std::invalid_argument("");
    }
    else
    board[x][y]=2;
}

//getBoard
void TicTacToe::getBoard () {
    for (int i=0; i<3; i++) {
        cout << "   |   |   " << endl;
        for (int j=0; j<3; j++) {
            switch (board [i][j]) {
                case 1: 
                cout << " x ";
                break;
                case 2:
                cout << " o ";
                break;
                case 0:
                cout << "   ";
                break;
                default:
                cout << "Non dovresti essere qui" << endl;
            }
            if (j!=2)
            cout << "|";
        }
        cout << endl;
        if (i!=2)
        cout << "------------" << endl;
    }
}

//checkWin
bool TicTacToe::checkWin () {
    //righe
    for (int i=0; i<3; i++) {
        if (checkRow(i)==true)
        return true; 
    }

    //colonne
    for (int j=0; j<3; j++) {
        if (checkColumn(j)==true)
        return true; 
    }   

    //diagonali
    if (checkDiag1()==true || checkDiag2()==true)
    return true;
    else return false;
}

//controlla righe
bool TicTacToe::checkRow (int i) {
    int x= board [i][0];
    if (x!=0){
    for (int j=1; j<3; j++) {
        if (board [i][j]!=x)
        return false;
    }
    return true;
    }
    else return false;
}

//controlla colonne
bool TicTacToe::checkColumn (int j) {
    int x= board [0][j];
    if (x!=0) {
    for (int i=1; i<3; i++) {
        if (board [i][j]!=x)
        return false;
    }
    return true;
    }
    else return false;
}

//controlla diagonali
bool TicTacToe::checkDiag1 () {
    int x = board[0][0];
    if (x!=0) {
    for (int i = 1; i<3; i++) {
        if (board[i][i]!=x)
        return false;
    }
    return true;
    }
    else return false;
}
bool TicTacToe::checkDiag2 () {
    int x = board [0][2];
    if (x!=0) {
        int i{1}, j{1};
        while (i<3&&j>=0){
            if (x!= board[i][j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    else return false;
}

bool TicTacToe::checkMove (int x, int y) {
    //true = corretto
    if (x<0 || x>2) {
        cout << "\nL'indice di riga non e\' valido\n";
        return false;
    }
    if (y<0 || y>2) {
        cout << "\nL'indice di colonna non e\' valido\n";
        return false;
    }
    if (board[x][y]!=0) {
        cout << "\nQuesto spazio e\' gia\' occupato";
        return false;
    }
    return true;
}