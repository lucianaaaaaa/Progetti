//reverse.cpp
//reverse linked list

#include <iostream>
#include "LinkedList.h"
using std::cout; using std::endl;

int main () {
    LinkedList <double> first;
    first.addFront(0.1);
    first.addFront(0.2);
    first.addFront(0.3);
    first.addFront(0.4);
    first.addFront(0.5);
    LinkedList <double> second;
    for (int i=0; i<first.size(); i++) cout << first[i] << " , " ;
    cout << endl;
    while (!first.empty()) {//leggi, salva e rimuovi
    second.addFront(first.front());
    first.removeFront();
    }
    for (int i=0; i<second.size(); i++) cout << second[i] << " , " ;
}