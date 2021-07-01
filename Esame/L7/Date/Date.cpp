//Date.cpp
//implementation of member functions of Date

#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Date.h"

using std::string;
using std::endl;
using std::ostringstream;
using std::array;
using std::cout;
using std::invalid_argument;

//constructor
Date::Date(unsigned int d, unsigned int m, unsigned int y) 
    : day{checkDay(d)}, month{m}, year{y} {
        if (m<1 || m>monthsPerYear)
        throw invalid_argument ("month must be 1-12");

        cout << "Date object constructor for date " << toString() << endl;
}

//print date object
string Date::toString() const {
    ostringstream output;
    output << day << "/" << month << "/" << year;
    return output.str();
}

//output date object when destructor is called
Date::~Date() {
    cout << "Date object destructor for date " << toString() << endl;
}

unsigned int Date::checkDay(int d) const {
    static const array <int,monthsPerYear+1> daysPerMonth {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 
    };

    if (d>0 && d<daysPerMonth[month]) return d;

    //check for leap year
    if (month == 2 && d==29 && (year%400 == 0 || (year%4==0 && year%100!=0)))
    return d;

    throw invalid_argument("Invalid day for current month and year");
}