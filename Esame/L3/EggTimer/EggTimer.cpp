//EggTimer.cpp
//display egg timer

#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::endl;

int main () {

    //print first row
    for (int i=1; i<10; i++)
    cout << "#";
    cout << endl;

    //print middle part - first
    for (int i=0; i<=3; i++) {
        cout << "#";
        
        //repeated spaces
        for (int j=0; j<i; j++)
        cout << " ";

        //repeated asterisks 1->7, 2->5, 3->3
        for (int j=7-2*i; j>0; j--)
        cout << "*";

        //repeated spaces
        for (int j=0; j<i; j++)
        cout << " ";
        

        cout << "#" << endl;
    }

    //middle part - second
    for (int i=0; i<=2; i++) {
        cout << "#";
        
        //repeated spaces
        for (int j=2; j>i; j--)
        cout << " ";

        //repeated asterisks 1->7, 2->5, 3->3
        for (int j=0; j<3+2*i; j++)
        cout << "*";

        //repeated spaces
        for (int j=2; j>i; j--)
        cout << " ";
        

        cout << "#" << endl;
    }


    //print last row
    for (int i=1; i<10; i++)
    cout << "#";
}
