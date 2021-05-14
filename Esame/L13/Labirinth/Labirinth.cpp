//Labirinth.cpp
//stack holds last position and direction
// 8 1 2
// 7 x 3
// 6 5 4

//Labirinth: 0=free, 1=wall
#include <iostream>
#include <iomanip>
#include <array>
#include "LStack.h"
using std::setw;
using std::cout;
using std::endl;
using std::array;

void move (array<int,3>& a, int direction);
bool legitMove(array<int,3> a, int direction, int** lab );

int main () {
    //initialize labirinth
    //ask for input or default
    //default
    int Labirinth[11][15] {
        {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1}, //prima riga
        {1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0}
    };

    //display labirinth
    for (int i=0; i<11; i++) {
        for (int j=0; j<15; j++)
        cout << Labirinth[i][j] << " ";
        cout << endl;
    }

    //ptr a labirinth
    int** lab = new int*[11];
    for (int i=0; i<11; i++) {
        lab[i] = new int [15];
    }

    //inizializza
    for (int i=0; i<11; i++)
        for (int j=0; j<15; j++)
        lab[i][j]=Labirinth[i][j]; //temporaneo

    //initialize stack
    LinkedStack <array<int,3>> mystack;
    array <int,3> elem {1,0,0}; //direction, xposition, yposition
    mystack.push (elem);
    int direction;
    bool backtracking=false;
    bool success=false;

    while (!mystack.empty() && !success) { //when stack is empty, it means labirinth is impossible  

        //inizializzazione
        elem = mystack.top(); //inizializza posizione e direzione
        direction = elem[0]; //direzione

        //aggiorna posizione
        if (direction!=8)
        direction++; //incrementa direzione
        else direction = 1;

        //tenta le mosse
        backtracking = true;
        while (direction!=elem[0]) { //finché hai direzioni a disposizione
        
            if (elem[1]==10&& elem[2]==14) {
                backtracking=false;
                success = true;
                break;
            }

            if(legitMove(elem,direction,lab)) { //se la mossa è lecita
                cout << "\nMossa\n";
                move(elem, direction); //muovi, ovvero cambia la posizione in base alla direzione
                (direction<=4) ? elem[0]=direction+4 : elem[0]=direction-4; //imposta prossima direzione
                mystack.push(elem); //registra ultima mossa nello stack

                //marca la posizione
                lab[elem[1]][elem[2]]=1;
                backtracking = false; //ho avuto successo

                //stampa labirinto
                for (int i=0; i<11; i++) {
                    for (int j=0; j<15; j++) {
                        if (i!=elem[1]||j!=elem[2])
                        cout << " " << lab[i][j] << " ";
                        else cout << " - ";
                    }
                    cout << endl;
                }
                break;

            }

            //aggiorna posizione
            if (direction!=8)
            direction++; //incrementa direzione
            else direction = 1;
        }

        if (backtracking){
            cout << "\nBacktracking\n";
            mystack.pop();
            //marca posizione
            lab[elem[1]][elem[2]]=1;
        }

    }

    if (success==true) 
    cout << "Successo" << endl;

    for (int i=0; i<11; i++) {
        delete[] lab[i];
    }
    delete [] lab;

    cout << "Stampo tutti i passaggi per la risoluzione del labirinto."
        << "\nSono stampati dall'ultima mossa alla prima"
        << "\n\"Direzione\" indica la direzione di provenienza\n"
        << "8 1 2\n7 x 3\n6 5 4\n\n";
    cout << setw(12) << "Direzione" << setw (12) << "Posizione" << endl;

    while (!mystack.empty()) {
        elem = mystack.top();
        cout << setw(12) << elem[0] 
            << setw(6) << elem[1] << " , " << setw(3) << elem[2] << endl;
        mystack.pop(); 
    }
}

//funzione effettua mossa
void move (array<int,3>& a, int direction) {
    //controllare direzione (primo elemento dell'array)
    switch(direction) {
        case 1: //mossa in alto
            a[1]--; //posizione x decrementata (riga in alto), y uguale
            break;
        case 2: //in alto a destra
            a[1]--; //riga in alto
            a[2]++; //colonna a destra
            break;
        case 3: //mossa a dx
            a[2]++; //riga uguale, colonna a dx
            break;
        case 4: //in basso a dx
            a[1]++; //riga in basso
            a[2]++; //colonna a dx
            break;
        case 5: //mossa in basso
            a[1]++; //riga in basso, colonna uguale
            break;
        case 6: //mossa in basso a sx
            a[1]++; //riga in basso
            a[2]--; //colonna a sx
            break;
        case 7: //mossa a sx
            a[2]--; //colonna a sx, riga uguale
            break;
        case 8: //mossa in alto a sx
            a[1]--; //riga in alto
            a[2]--; //colonna a sx
            break;
        default:
            cout << "Questo non doveva succedere\n"; 
    }
}

//funzione controlla che la mossa sia lecita
bool legitMove(array<int,3> a, int direction, int** lab ) {
    //a mi dà la posizione di partenza
    //direction è la direzione da controllare
    //lab è il puntatore al labirinto
    switch (direction) {
        case 1: //mossa in alto
            if (a[1]-1<0||lab[a[1]-1][a[2]]!=0)
            return false;

            break;
        case 2: //in alto a destra
            if (a[1]-1<0||a[2]+1>=15||lab[a[1]-1][a[2]+1]!=0)
            return false;

            break;
        case 3: //mossa a dx
            if (a[2]+1>=15||lab[a[1]][a[2]+1]!=0)
            return false;

            break;        
        case 4: //in basso a dx
            if (a[1]+1>=11||a[2]+1>=15||lab[a[1]+1][a[2]+1]!=0)
            return false;

            break;
        case 5: //mossa in basso
            if (a[1]+1>=11||lab[a[1]+1][a[2]]!=0)
            return false;

            break;
        case 6: //mossa in basso a sx
            if (a[1]+1>=11||a[2]-1<0||lab[a[1]+1][a[2]-1]!=0)
            return false;

            break;
        case 7: //mossa a sx
            if (a[2]-1<0||lab[a[1]][a[2]-1]!=0)
            return false;

            break;
        case 8: //mossa in alto a sx
            if (a[1]-1<0||a[2]-1<0||lab[a[1]-1][a[2]-1]!=0)
            return false;

            break;
        default:
            cout << "Questo non doveva succedere\n";
            return false;
    }
    return true;
}