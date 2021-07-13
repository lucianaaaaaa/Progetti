//createFile.cpp
//creates file credit.dat that can store up to 100 bank accounts

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"

using std::ofstream;
using std::ios;

int main () {
    ofstream outCredit {"credit.dat", ios::out | ios::binary};

    if (!outCredit) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    ClientData blankClient; //default, blank client

    for (int i=0; i<100; i++) {
        outCredit.write (
            reinterpret_cast <const char*> (&blankClient), sizeof(ClientData));
    
    }
}