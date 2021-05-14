//Dec2Bin.cpp
//recursive implementation of dec to bin conversion

#include <iostream>
#include <string>
using std::cout;

std::string dec2bin (int dec) {
    //caso base
    if (dec==0) return "0";
    if (dec==1) return "1";

    //recursion
    return dec2bin(dec/2) + std::to_string(dec%2);
}

int main () {
    int x=27;
    cout << "Conversion of decimal " << x 
        << " to binary is " << dec2bin(x) << std::endl;
}