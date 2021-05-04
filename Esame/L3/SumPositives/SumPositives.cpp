//SumPositives.cpp
//find the sum of positive numbers
//exits when input is negative

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main () {
    int number;
    int sum = 0;
    //take input
    cout << "Enter a number: ";
    cin >> number;
    while (number >=0) {
        //add positive numbers
        sum += number;

        //take input again
        cout << "Enter a number: ";
        cin >> number;
    }
    //display sum
    cout << "\nThe sum is " << sum <<endl;
    return 0;
}