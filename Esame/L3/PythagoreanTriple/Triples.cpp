//Triples.cpp
//finds all pythagorean triples with sides <500

#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;

int main () {
    cout << "***PYTHAGOREAN TRIPLES***\n\n";

    //display headers
    cout << setw(13) << "First side"
        << setw(14) << "Second side"
        << setw(13) << "Hypotenuse" << endl; 
    
    for (int side1=1; side1<500; side1++) { //check each integer
        for (int side2=side1; side2<500; side2++) { //only check integers >side1
            double hyp = sqrt (pow(side1,2)+pow(side2,2));
            if (trunc(hyp)==hyp && hyp<500) { //if hypotenuse is an integer
                cout << setw(13) << side1
                    << setw(14) <<side2
                    << setw(13) <<hyp << endl; 
            }
        }
    }
}