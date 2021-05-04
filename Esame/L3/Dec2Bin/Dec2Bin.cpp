//Dec2Bin.cpp
//conversion of a number from base 10 to binary
#include <iostream>
#include <array>
using std::cin;
using std::cout;
using std::endl;

int main () {
    cout << "***DECIMAL TO BINARY CONVERTER***" << endl;

    int dec;
    std::array <int,8> bin; //supposing it's from 0 to 256

    //initialize array with sentinel value -1
    for (int i=0; i<8; i++)
    bin[i]=-1;
    //ask input
    cout << "Enter decimal number: ";
    cin >> dec;

    //check if number is positive
    if (dec<0) {
        cout << "Input must be positive" << endl;
        exit (EXIT_FAILURE);
    }

    int x{dec};
    int i{0};

    while (x!=1) {
        bin[i] = x%2;
        x/=2;
        i++;
    }
    bin [i] = 1;

    cout << "You converted the decimal number " << dec << " to its binary form ";
    //display binary number
    for (int j=7; j>=0; j--) {
        if (bin[j]!=-1)
        cout << bin[j];
    }
}