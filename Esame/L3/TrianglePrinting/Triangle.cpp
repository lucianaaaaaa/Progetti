//Triangle.cpp
//program that prints different triangle patterns through iterations
#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::endl;
using std::setw;

std::string outLine (int i);

int main () {
    cout << "***TRIANGLE ASTERISK PATTERNS***\n\n"
        << "***PATTERN 1***" << endl;

    //PATTERN 1
    for (int i=1; i<=10; i++) {
        for (int j=1; j<=i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    //PATTERN 2
    cout << "\n***PATTERN 2***\n";
    for (int i=1; i<=10; i++) {
        for (int j=11-i; j>=1; j--) {
            cout << "*";
        }
        cout << endl;
    }

    //PATTERN 3
    cout << "\n***PATTERN 3***\n";
    for (int i=1; i<=10; i++) {
        cout << setw(10) << outLine(i);

        cout << endl;
    }

    cout << "\n***PATTERN 4***\n";
    for (int i=1; i<=10; i++) {
        cout << setw(10) << outLine(11-i);

        cout << endl;
    }
}

std::string outLine (int i) {
    std::string output;
    for (int j=11-i; j>=1; j--) {
            output+= "*";
    }
    return output;
}