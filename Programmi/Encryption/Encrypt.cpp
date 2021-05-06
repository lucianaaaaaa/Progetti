//Encrypt.cpp
//encrypt data into 4 digit integers
#include <iostream>
#include <array>
using std::array;
using std::cout;
using std::cin;
using std::endl;

void swap (array <int,4>& a, int i, int j);

int main () {
    cout << "***ENCRYPT DATA***" << endl;

    //ask input
    int input;
    cout << "Enter 4 digit integer to encrypt: ";
    cin >> input;

    //arrange digits in an array
    array <int,4> number;
    for (int i=3; i>=0; i--) {
    number [i] = input % 10; //write last digit
    input/=10;
    }

    //encrypt
    //1. compute digits
    for (int i=0; i<4; i++)
    number[i] = (number[i]+7)%10;
    
    //2. swap digits
    swap (number, 0, 2);
    swap (number, 1, 3);

    //display results
    cout << "Your encryption was successful.\nThe encrypted data is: ";
    for (int i=0; i<4; i++)
    cout << number[i];

    cout << endl;
}

void swap (array<int,4>& a, int i, int j) {
    int z{a[i]};
    a[i]=a[j];
    a[j]=z;
}