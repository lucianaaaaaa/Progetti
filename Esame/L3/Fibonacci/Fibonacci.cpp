//Fibonacci.cpp
//stampa la successione di Fibonacci while true
#include <iostream>
using std::cout;

int main () {
    cout << "***FIBONACCI SEQUENCE***" << std::endl;
    int x{0},y{1};
    int z{0};
    int i{0};
    cout << "0, 1, ";
    while (true) {
        z=y;
        y+=x;
        x=z;
        cout << y << ", ";
    }

}