//example1.cpp
//example on usage of iterators in stl containers

#include <vector>
#include <iostream>
using std::cout; using std::endl;
using std::vector;

int main () {
    vector <int> v {23,73,4,12,53};
    vector<int>::iterator p;

    for (p=v.begin(); p!=v.end(); p++) 
    cout << *p << " , " ;
    //*p = v[i], ottimo per strutture che non hanno operatore[] 
}