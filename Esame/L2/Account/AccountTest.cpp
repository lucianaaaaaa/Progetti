//AccountTest.cpp
//Creating and manipulating an Account object
#include <iostream>
#include <string>
#include "Account.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main () {
    Account myAccount("",0); //create Account object
    //initial value
    cout << "Initial account name is: " << myAccount.getName();

    //prompt for and read name
    cout << "\nPlease enter the account name: ";
    string theName;
    getline (cin, theName); //read a line of txt
    myAccount.setName(theName);

    //display the new name
    cout << "Name in object myAccount is: " <<
        myAccount.getName() <<endl;
}