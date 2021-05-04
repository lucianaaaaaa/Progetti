//Bin2Dec.cpp
//convert from binary to decimal
#include <iostream>
#include <array>
#include <tgmath.h>
using std::cin;
using std::cout;
using std::endl;

int main () {
    cout << "***BINARY TO DECIMAL CONVERTER***" << endl;

    //ask input
    int bin;
    cout << "Enter binary number: ";
    cin >> bin;
    int x{bin}, dec{0}, i{0};

    //conversion
    while(x!=1) {
    dec+=(x%2)*pow(2.0,static_cast<double>(i));
    i++;
    x/=10; //togli una cifra
    }
    dec+=pow(2.0,static_cast<double>(i));

    //display results
    cout << "You converted the binary number " << bin << " to its decimal form " << dec << endl;
}