#include <iostream>
#include "TicTacToe.h"
using std::cout;
using std::endl;
using std::cin;

int main () {

    cout << "Benvenuti al gioco TicTacToe!\n";
    cout << "Il giocatore 1 gioca con x, il giocatore 2 con o\n";
    cout << "DIVERTITEVI!!!!!\n\n";

    TicTacToe game;
    game.getBoard();
    //posizione player
    int x{0};
    int y{0};
    //contatore di turni
    int ctr{0};
    cout << "\nOra e\' il turno del giocatore 1. \n";

    while (ctr<9) {
        if (ctr>4 && game.checkWin()==true)
        break;

        cout << "Giocatore, in quale riga vuoi piazzare? ";
        cin >> x;
        cout << "\nGiocatore, in quale colonna vuoi piazzare? ";
        cin >> y;
        cout <<endl;
        if (ctr%2==0) {
            try{
            game.setPlayer1(x,y);            
            game.getBoard();
            cout << "\n Ora e\' il turno del giocatore 2. \n";
            }
            catch (const std::invalid_argument& e) {
                cout << "\nMossa non valida\n";
                ctr--;
            }

        }
        else {
            try{
            game.setPlayer2(x,y);            
            game.getBoard();
            cout << "\n Ora e\' il turno del giocatore 1. \n";
            }
            catch (const std::invalid_argument& e) {
                cout << "\nMossa non valida\n";
                ctr--;
            }
        }
        ctr++;
    }
    if (game.checkWin()==false)
    cout << "\n E\' un pareggio!" << endl;
    else if (ctr%2==0)
    cout << "\nHa vinto il giocatore 2!" << endl;
    else 
    cout << "\nHa vinto il giocatore 1!" << endl;

}