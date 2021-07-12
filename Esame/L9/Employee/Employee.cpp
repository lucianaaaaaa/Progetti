//Employee.cpp
#include "Employee.h"

Employee::Employee(const std::string& f,const std::string& l,const std::string& s)
    : firstName{f}, lastName{l}, SSN{s} {}

void Employee::setFirstName(const std::string& f) {firstName=f;}
void Employee::setLastName(const std::string& f) {lastName=f;}
void Employee::setSSN(const std::string& f) {SSN=f;}

std::string Employee::getFirstName() const {return firstName;}
std::string Employee::getLastName() const {return lastName;}
std::string Employee::getSSN() const {return SSN;}

std::string Employee::toString() const {
    return getFirstName() + " " + getLastName() +
        "\nSSN: " + getSSN();
}

