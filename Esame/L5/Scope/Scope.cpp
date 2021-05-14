//Scope.cpp
//demonstrate scope of a variable

#include <iostream>
using std::cout;
using std::endl;

void useLocal();
void useStaticLocal();
void useGlobal();

int x{1}; //global variable

int main () {
    cout << "global x in main is " << x << endl;

    int x{5}; //local to main
    cout << "local x in main's outer scope is " << x << endl;

    {//inner scope
        int x{7};
        cout << "local x in main's inner scope is " << x << endl;
    }

    //demonstrate that inner scope's variable doesn't get here
    cout << "local x in main's outer scope is " << x << endl;

    useLocal(); //local x
    useStaticLocal(); //static local x
    useGlobal(); //global x

    //try again to see changes
    useLocal(); //local x (function)
    useStaticLocal(); //static local x remembers its past value
    useGlobal(); //global x

    cout << "local x in main is " << x << endl;
}

void useLocal () { //reinitializes a new x that is local to this function
int x{25};

cout << "\nlocal x is " << x << " on entering useLocal" << endl;
++x;
cout << "\nlocal x is " << x << " on exiting useLocal (incremented)" << endl;
}

void useStaticLocal () { //reinitializes x as a static value
static int x{50};

cout << "\nlocal static x is " << x 
    << " on entering useStaticLocal" << endl;
++x;
cout << "\nlocal static x is " << x 
<< " on exiting useStaticLocal (incremented)" << endl;
}

void useGlobal () { //uses global x=1
cout << "\nglobal x is " << x 
    << " on entering useGlobal" << endl;
x+=10;
cout << "\nglobal x is " << x 
<< " on exiting useGlobal (+10)" << endl;
}