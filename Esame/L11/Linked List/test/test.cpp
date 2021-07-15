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
    cout << "myList.size() is " << myList.size() << endl;
    for (int i=0; i<myList.size(); i++) cout << myList[i] << "\t";
    cout << "\n";
    LinkedList<int> list2(myList);
    for (int i=0; i<list2.size(); i++) cout << list2[i] << "\t";
    LinkedList<int> list3;
    list3.addFront(4);
    cout << "List3: " << list3[0] << endl;
    list3=list2;
    cout << "List3 = List2:\n";
    for (int i=0; i<list3.size(); i++) cout << list3[i] << "\t";
}