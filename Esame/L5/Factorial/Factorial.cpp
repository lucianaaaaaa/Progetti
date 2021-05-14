//Factorial.cpp
//calculate factorial with recursion

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

unsigned long factorial (unsigned long);

int main () {
    //calculate factorials of 0 through 10
    for (unsigned int counter{0}; counter <= 10; ++counter) {
        cout << setw(2) << counter 
            << "!= " << factorial(counter) << endl;
    }
}

unsigned long factorial (unsigned long number) {
    if (number <= 1) {
        return 1;
    }
    else {
        return number * factorial (number-1);
    }
}