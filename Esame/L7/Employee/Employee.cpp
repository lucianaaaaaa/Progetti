//Employee.cpp
//Employee class member-function definitions

#include <iostream>
#include <sstream>
#include "Employee.h"
#include <C:\Users\lucia\OneDrive\Documents\GitHub\Progetti\Esame\L7\Date\Date.h>
using std::string;
using std::cout;
using std::endl;
using std::ostringstream;

//constructor
Employee::Employee(const string& f, const string& l, const Date& birth, const Date& hire)
    : firstName{f}, lastName{l}, birthDate{birth}, hireDate {hire} {
        cout << "Employee object constructor: " << toString() << endl;
    }


//print object
string Employee::toString() const {
    ostringstream output;
    output << lastName << " " << firstName << "\nHired: " 
        << hireDate.toString() << "\nBirthday: " << birthDate.toString();
    return output.str();
}

//destructor
Employee::~Employee() {
    cout << "Employee object destructor: " << toString() << endl;
}