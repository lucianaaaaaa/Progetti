//Vexcept.cpp
//demonstrate usage of vector class and exceptions

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;
using std::out_of_range;

void outputVector(const vector <int>&);
void inputVector(vector<int>&);

int main () {
    vector <int> integers1(7);
    vector <int> integers2(10);

    //print sizes
    cout << "Size of vector integers1 is " << integers1.size()
        << "\nvector after initialization: ";
    outputVector(integers1);

    cout << "Size of vector integers2 is " << integers2.size()
        << "\nvector after initialization: ";
    outputVector(integers2);

    //input and print integers1 and integers2
    cout << "\nEnter 17 integers: " << endl;
    inputVector(integers1);
    inputVector(integers2);

    cout << "\nAfter input, the vectors contain:\n"
        << "integers1: ";
        outputVector(integers1);
    cout << "integers2: ";
        outputVector(integers2);
    
    //use inequality operator with vector objects
    cout << "\nEvaluating: integers1 != integers2" << endl;
    if (integers1!=integers2)
        cout << "integers1 and integers2 are not equal\n";
    
    //create integers3 using integers1 as initializer
    vector <int> integers3{integers1};

    cout << "Size of vector integers3 is " << integers3.size()
        << "\nvector after initialization: ";
    outputVector(integers3);

    //use overloaded assignment operator =
    cout << "\nAssigning integers2 to integers1:\n";
    integers1=integers2;

    cout << "integers1: ";
    outputVector(integers1);
    cout << "integers2: ";
    outputVector(integers2);

    //using equality operator
    cout << "\nEvaluating: integers1 == integers2" << endl;
    if (integers1==integers2)
        cout << "integers1 and integers2 are equal\n";
    
    //square brackets operator
    cout << "\nintegers1[5] is " << integers1[5];

    //assign value using square brackets
    cout << "\n\nAssigning 1000 to integer[5]" << endl;
    integers1[5]=1000;
    cout << "integers1: ";
    outputVector(integers1);

    //attempt to use out of range subscript
    try {
        cout << "\nAttempt to display integers1.at(15)" << endl;
        cout << integers1.at(15) << endl;
    }
    catch (out_of_range& ex)
        {cerr << "An exception occurred: " << ex.what() << endl;}
    
    //changing size of a vector
    cout << "\nCurrent integers3 size is: " << integers3.size() << endl;
    integers3.push_back(1000);
    cout << "New integers3 size is: " << integers3.size();
    cout << "\nintegers3: ";
    outputVector(integers3);
}

void outputVector(const vector<int>& items) {
    for (int item: items) cout << item << " ";
    cout << endl;
}

void inputVector(vector<int>& items) {
    for (int& item: items) cin >> item;
}