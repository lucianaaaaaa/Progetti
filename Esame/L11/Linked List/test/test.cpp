//test.cpp

#include "LinkedList.h"
#include <iostream>

using std::cout; using std::endl;

int main () {
    LinkedList<int> myList;
    myList.addFront(3);
    myList.addFront(2);
    myList.addFront(1);

    cout << "myList[2] is " << myList[2] << endl;
}