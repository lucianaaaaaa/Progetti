//double list.cpp
//write a function that generates 2 lists from myList
//one contains elements of myList in even positions
//the other contains elements in odd positions

#include "LinkedList.h"
#include <string>
using std::string; using std::endl;
using std::cout;

int main () {
    LinkedList<string> myList;
    myList.addFront("A");
    myList.addFront("B");
    myList.addFront("C");
    myList.addFront("D");
    myList.addFront("E");
    myList.addFront("F");
    for (int i=0; i<myList.size(); i++) cout << myList[i] << "\t";
    cout << endl;

    LinkedList<string> pari;
    LinkedList<string> dispari;
    for (int i=myList.size()-1; i>=0; i=i-2) {
        dispari.addFront(myList[i]);
    }
    for (int i=myList.size()-2; i>=0; i=i-2) {
        pari.addFront(myList[i]);
    }
    cout << "pari:    ";
    for (int i=0; i<pari.size(); i++) cout << pari[i] << "\t";
    cout << endl;
    cout << "dispari: ";
    for (int i=0; i<dispari.size(); i++) cout << dispari[i] << "\t";
}