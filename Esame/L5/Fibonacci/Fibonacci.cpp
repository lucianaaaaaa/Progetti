//Fibonacci.cpp
//recursive implementation of fibonacci sequence

#include <iostream>
using std::cout;
using std::endl;

unsigned long fibonacci (unsigned long);

int main () {
    //calculate fibonacci of 0 through 10
    for (unsigned int counter{0}; counter <= 10; ++counter) {
        cout << "fibonacci (" <<  counter << ") = "
            << fibonacci(counter) << endl;
    }
}

unsigned long fibonacci (unsigned long number) {
    if (number <= 1) {
        return 1;
    }
    else {
        return fibonacci(number-2) + fibonacci (number-1);
    }
}