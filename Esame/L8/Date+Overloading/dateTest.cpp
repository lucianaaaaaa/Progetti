//dateTest.cpp
//test class Date with overloaded operators

#include "Date.h"
#include <iostream>
#include <string>
using std::cout; using std::endl;

int main () {
    Date d1 {25,12,2020};
    Date d2;

    cout << "d1 is " << d1 << "\nd2 is " << d2;
    cout << "\nd1+=7 is " << (d1+=7);

    d2.setDate(28,2,2008);
    cout << "\nnew d2 is " << d2 << endl;
    cout << "d2++ is " << d2++ << endl;
    cout << "d2 after postincrement: " << d2 << endl;

    cout << "++d2 is " << ++d2 << endl;

    std::string s = (d2<d1) ? " is " : " is not " ;
    cout << "Testing relational operators: " << endl
        << d2 << s << "less than " << d1 << endl;

    Date d3 = d2+10;
    cout << "\n\nTesting summing number of days: " << endl
        << d3 << " = " << d2 << " + 10 days" << endl;

    d2=d3-10;
    cout << "\n\nTesting subtracting number of days: " << endl
        << d2 << " = " << d3 << " - 10 days" << endl;

    Date d4(1,3,2008);
    cout << "\nd4 is " << d4 << endl;
    cout << "\nTesting predecrement with leap year: " << endl 
        << d4;
    cout << "-- is " << --d4; 
}