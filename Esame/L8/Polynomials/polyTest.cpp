#include "Poly.h"
#include <iostream>
using std::cout;
using std::endl;

int main () {
    double coeffs1[] {1,2,3};
    double coeffs2[] {4,5,6};
    double coeffs3[] {7};
    Polynomial p1(3,coeffs1);
    Polynomial p2(3,coeffs2);
    Polynomial p3(1,coeffs3);

    cout << "p1 is " << p1 << endl;
    cout << "p2 is " << p2 << endl;
    cout << "p1+p2 is " << (p1+p2) << endl;
    cout << "p3 is " << p3 << endl;
    cout << "p1+p3 is " << (p1+p3) << endl;
    
    cout << "p2*=7 is " << (p2*=7) << endl;

    double coeffs4[] {0,2,4,5};
    Polynomial p4(4,coeffs4);
    cout << "p1*p4 is " << (p1*p4) << endl;
}