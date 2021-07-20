#include "Deque.h"
#include <iostream>
using std::cout; using std::endl;

int main () {
    Deque<double> myDeque;
    myDeque.insertFront(3);
    myDeque.insertFront(2);
    myDeque.insertFront(1);
    myDeque.insertBack(4);
    myDeque.insertFront(0);
    cout << myDeque.toString() << endl;
    myDeque.removeFront(); myDeque.removeBack();
    cout << "Removed first and back elements: " << myDeque.toString() << endl;
    cout << "Inserimento" << endl;
    myDeque.insertFront(1.5);
    myDeque.insertFront(3.5);
    myDeque.insertFront(1.5);
    myDeque.insertFront(0.5);
    cout << myDeque.toString() << endl;
    cout << "Size: " << myDeque.size() << endl;

    return 0;
}