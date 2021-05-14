//DollarTest.cpp
// Calculations with class DollarAmount
#include <iostream>
#include <iomanip>
#include <string>
#include "DollarAmount.h"
using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main () {
    DollarAmount d1{12345}; //123.45
    DollarAmount d2{1576}; //15.76

    cout << "After adding d2 (" << d2.toString() << ") into d1 ("
        << d1.toString() << "), d1 = ";
    d1.add(d2);
    cout << d1.toString() << "\n";

    cout << "After subtracting d2 (" << d2.toString() << ") from d1 ("
        << d1.toString() << "), d1 = ";
    d1.subtract(d2);
    cout << d1.toString() << "\n";

    cout << "After subtracting d1 (" << d1.toString() << ") from d2 ("
        << d2.toString() << "), d2 = ";
    d2.subtract(d1);
    cout << d2.toString() << "\n";

    cout << "Enter integer interest rate and divisor. For example:\n"
        << "for    2%, enter:    2 100\n"
        << "for  2.3%, enter:   23 1000\n"
        << "for 2.37%, enter:  237 10000\n";
    int rate;
    int divisor;
    cin >> rate >> divisor;

    DollarAmount balance {100000}; //$1000.00
    cout << "\nInitial balance: " << balance.toString() << endl;

    //display headers
    cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

    //calculate amount for each of ten years
    for (unsigned int year{1}; year<=10; year++) {
        //increase balance by rate %
        balance.addInterest(rate,divisor);

        //display the year and amount
        cout << setw(4) << year << setw(20) << balance.toString() << endl;
    }
}