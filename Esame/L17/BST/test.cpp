#include "BST.h"
#include <iostream>

using std::cout; using std::endl;

int main () {
    BST<double> myBst;
    myBst.insert(3);
    myBst.insert(2);
    myBst.insert(1.5);
    myBst.insert(4);
    myBst.insert(2.5);
    myBst.insert(7);
    myBst.insert(3.5);
    cout << myBst.minimum() << endl;
    cout << myBst.maximum() << endl;

    cout << endl << "Cerca elemento 4" << endl;
    cout << ((myBst.search(4))==nullptr)? "non c'è" : "c'è";
}