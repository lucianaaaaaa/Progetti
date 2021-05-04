//Increment.cpp
//Prefix vs postfix increment

#include <iostream>
using std::cout;
using std::endl;

int main () {
    //postfix
    unsigned int c{5};
    cout << "c before postincrement: " << c << endl; //5
    cout << "postincrementing c: " << c++ << endl; //5
    cout << " c after posincrement: " << c << endl; //6

    cout << endl;
    c=5;

    cout << "c before preincrement: " << c << endl; //5
    cout << "preincrementing c: " << c++ << endl; //6
    cout << " c after preincrement: " << c << endl; //6

}