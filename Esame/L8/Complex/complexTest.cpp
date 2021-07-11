#include "Complex.h"
#include <iostream>
using std::cout;
using std::endl;

int main () {
    Complex a(1,2);
    Complex b(3,4);
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "a+b is " << (a+b) << endl;
    cout << "a-b is " << (a-b) << endl;
    cout << "b/a is " << (b/a) << endl;
}