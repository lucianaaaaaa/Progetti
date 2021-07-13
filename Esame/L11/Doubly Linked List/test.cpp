#include "DLinkedList.h"
#include "iostream"

using std::cout; using std::endl;

int main () {
    DLinkedList<int> myList;
    myList.addFront(3);
    myList.addFront(2);
    myList.addFront(1);
    myList.addBack(4);
    myList.addFront(0);
    cout << myList.toString() << endl;
    myList.removeFront(); myList.removeBack();
    cout << "Removed first and back elements: " << myList.toString();

}