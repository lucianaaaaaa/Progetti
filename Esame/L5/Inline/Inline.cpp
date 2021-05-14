//Inline.cpp
//define an inline function

#include <iostream>
using std::cout;
using std::endl;

inline double cube (const double side) {
    return side*side*side;
}

int main () {
    double sideValue;
    cout << "Enter side length of cube: ";
    std::cin >> sideValue;

    //calculate cube
    //inline function's body is copied here
    cout << "Volume of cube is " << cube (sideValue) << endl;
}