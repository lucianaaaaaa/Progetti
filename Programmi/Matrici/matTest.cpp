#include <iostream>
#include <cstdlib>

#include "matrix.h"
using std::cout;

int main () {
    Matrix n(4,5);
    Matrix m(5,4);
    srand(3);
    for (int i=0; i<4; i++)
        for (int j=0; j<5; j++) {
        double z {static_cast<double> (rand() % 300)/100};
        n.setValue(i,j,z);
        double v {static_cast<double> (rand() % 300)/100};
        m.setValue (j,i,v);
        }
    n.printMat();
    cout << std::endl;
    m.printMat();
    cout <<std::endl;
    try {(n*m).printMat();}
        catch (const std::invalid_argument& i ) {}

}