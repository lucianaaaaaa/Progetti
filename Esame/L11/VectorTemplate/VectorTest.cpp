//VectorTest.cpp
//basic test of template class BasicVector
#include <iostream>
#include "BasicVector.h"

int main () {
    BasicVector <double> V;
    for (int i=0; i<10; i++) {
        V[i] = i*i/2.0;
        std::cout << V[i] << " ";
    }

    std::cout << std::endl;
}