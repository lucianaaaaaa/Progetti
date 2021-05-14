//Dice.cpp
//dice rolling program using array

#include <iostream>
#include <iomanip>
#include <array>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::array;
using std::setw;
using std::endl;

int main () {
    //produce uniformly distributes pseudorandom int values from 1 to 6
    //using the default random-number generation engine

    const size_t arraySize{6};
    array <unsigned int, arraySize> frequency{}; //initialize to zeros

    //roll die 60.000.000 times
    for (unsigned int roll{1}; roll <=600000000; ++roll) 
        ++frequency [rand()%6];
    
    cout << "Face"  << setw(13) << "Frequency" << endl;

    //output each element
    for (size_t face{0}; face<frequency.size(); ++face)
        cout << setw(4) << face+1 << setw(13) << frequency[face] << endl;
}