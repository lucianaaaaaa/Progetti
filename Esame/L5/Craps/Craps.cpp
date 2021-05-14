//Craps.cpp
//Craps simulation

#include <iostream>
#include <cstdlib> //srand
#include <ctime>

using std::cout;
using std::endl;
unsigned int rollDice(); //rolls dice and displays sum

int main () {
    //scoped enumeration with constants that represent the game status
    enum class Status {CONTINUE, WON, LOST};

    //randomize seed
    srand (static_cast<unsigned int> (time(0)));

    unsigned int myPoint {0};
    Status gameStatus;
    unsigned int sumOfDice {rollDice()}; //roll 2 dice and sum

    //determine game Status on first roll
    switch (sumOfDice) {
        case 7: //win
        case 11: //win
            gameStatus = Status::WON;
            break;
        case 2: //loss
        case 3: //loss
        case 12: //loss
            gameStatus = Status::LOST;
            break;
        default: //every other number
            gameStatus = Status::CONTINUE;
            myPoint = sumOfDice;
            cout << "Point is " << myPoint << endl;
            break; //optional at the end of switch
    }

    //while game is not finished
    while (gameStatus == Status::CONTINUE) {
        sumOfDice = rollDice(); //roll dice again

        //determine game status
        if (sumOfDice==myPoint)
            gameStatus = Status::WON;
        else if (sumOfDice==7)
            gameStatus = Status::LOST;
    }

    //display results
    if (gameStatus == Status::WON)
        cout << "Player wins" << endl;
    else cout << "Player loses" << endl;
}

unsigned int rollDice() {
    int dice1{1+ rand()%6}; //from 1 to 6
    int dice2{1+ rand()%6};

    cout << "Player rolled " << dice1 << "+" << dice2 
        << "=" << dice1+dice2 << endl;
    return dice1+dice2;
}