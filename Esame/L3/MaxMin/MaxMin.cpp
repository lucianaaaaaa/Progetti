//MaxMin.cpp
//calculates maximum and minimum in a set of numbers
//sentinel value is 0

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main () {
    int number, max, min;

    //ask input
    cout << "Enter a number or 0 to quit: ";
    cin >> number;
    max = number;
    min = number;

    while (number!=0) {
        if (number>max)
        max = number;

        if (number<min)
        min = number;

        //ask for input again
        cout << "Enter a number or 0 to quit: ";
        cin >> number;
    }

    cout << "You quitted." << endl; 

    //display result
    cout << "\nThe maximum is: " << max;
    cout << "\nThe minimum is: " << min << endl;
}