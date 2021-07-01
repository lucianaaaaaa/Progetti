#include <iostream>
#include "Saxophonist.h"
using std::cout; using std::endl;

int Saxophonist::saxCount{0};
int main (void) { //specifies that main can only be called without any parameters

    cout << "Number of available saxophonists before deffinition: " <<
        Saxophonist::saxCount << endl;
    
    //inner scope
    {
        Saxophonist s1 ("Pippo", TENOR);
        Saxophonist s2 ("Pluto", ALTO);
        Saxophonist s3 ("Paperino", SOPRANO);

        //print total number of saxophonists
        cout << "Total number of saxophonists (using saxCount): " 
            << Saxophonist::saxCount << endl;
        cout << "Total number of saxophonists (using getCount): " << 
            s3.getCount() << endl;
    }

    cout << "Total number of saxophonists outside the scope: " 
            << Saxophonist::saxCount << endl;
}