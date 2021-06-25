//subscript.cpp
//using subscripting and pointer notations with built in arrays
#include <iostream>
using std::cout;

int main () {
    int b[] {10,20,30,40};
    int* bPtr{b}; //don't need &

    cout << "Array b displayed with:\n\n"

    << "Array subscript notation\n";
    for (size_t i{0}; i<4; i++)
        cout << "b[" << i << "] = " << b[i] << "\n";
    
    cout << "\nPointer/offset notation where the pointer is the array name\n";
    for (size_t offset{0}; offset<4; offset++)
        cout << "*(b + " << offset << ") = " << *(b+offset) << "\n";
    
    cout << "\nPointer subscript notation\n";
    for (size_t i{0}; i<4; i++)
        cout << "bPtr[" << i << "] = " << bPtr[i] << "\n";
    
    cout << "\nPointer offset notation\n";
    for (size_t offset{0}; offset<4; offset++)
        cout << "*(bPtr + " << offset << ") = " << *(bPtr+offset) << "\n";
    
    
    
}