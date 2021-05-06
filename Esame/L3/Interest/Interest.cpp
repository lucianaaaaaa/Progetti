//Interest.cpp
//compound interest calculation
#include <iostream>
#include <iomanip>
#include <cmath> //pow
using std::cout;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;

int main () {
    //floating point number format
    cout << fixed << setprecision(2);

    double principal {1000.00};
    double rate {0.05};

    //display initial values
    cout << "Initial principal: " << principal << endl;
    cout << "    Interest rate: " << rate << endl;

    //headers
    cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

    //calculate amount for 10 years
    for (unsigned int year{1}; year<=10; year++) {
        double amount = principal * pow(1.0+rate,year);

        //display result
        cout << setw(4) << year << setw(20) << amount << endl;
    }
}