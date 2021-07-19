//Date.cpp
//Date class member-functions and friend-functions definitions
#include <iostream>
#include <string>
#include "Date.h"

//initialize days per month
const std::array <unsigned int, 13> Date::days {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};


//Date constructor
Date::Date(unsigned int dd, unsigned int mm, unsigned int yy) {
    setDate(dd,mm,yy);
}

void Date::setDate(int dd, int mm, int yy) {
    if (mm>0 && mm<=12) month=mm;
    else throw std::invalid_argument("Invalid month");

    if (yy>=1900 && yy<=2100) year = yy;
    else throw std::invalid_argument("Invalid year");

    if ((dd>0 && dd<=days[month]) || (month==2 && leapYear(year) && dd==29)) day=dd;
    else throw std::invalid_argument("Invalid day");
}

bool Date::leapYear(int y) {
    return (y%400==0 || (y%100!=0 && y%4==0));
}

bool Date::endOfMonth (int d) const {
    if (month==2 && leapYear(year)) return day==29;
    return d==days[month];
}


//increment date
void Date::helpIncrement() {
    if (!endOfMonth(day)) day++;
    else if (month!=12) {
        day=1;
        month++;
    }
    else {
        day=1;
        month=1;
        year++;
    }
}

//decrement date
void Date::helpDecrement() {
    if (day!=1) day--;
    else if (month!=1) {
        --month;
        if (endOfMonth(days[month])) day=days[month]; //checks if it's a leap year
        else day=29;
    }
    else {
        year--;
        month=12;
        day=31;
    }
}

//relational operators
bool Date::operator< (const Date& second) const {
    if (year<second.year) return true;
    if (year==second.year && month<second.month) return true;
    if (year==second.year && month==second.month && day<second.day) return true;
    return false;
}

bool Date::operator<= (const Date& second) const {
    if (*this<second) return true;
    if (year==second.year && month==second.month && day==second.day) return true;
    return false;
}

bool Date::operator> (const Date& second) const {
    if (*this<=second) return false;
    return true;
}

bool Date::operator>= (const Date& second) const {
    if (*this<second) return false;
    return true;
}


//plus operator set
Date& Date::operator++() { //prefix
    helpIncrement();
    return *this;
}

Date Date::operator++(int) { //postfix
    Date temp{*this}; //saves temporary date before incrementing
    helpIncrement(); //increments date

    return temp; //returns previous date
}

Date& Date::operator+=(unsigned int i) {
    for (int j=0; j<i; j++)
    helpIncrement();
    return *this;
}

Date operator+(int i, const Date& d) {
    Date newdate{d};
    return newdate+=i;
}

Date operator+(const Date& d, int i) {
    Date newdate{d};
    return newdate+=i;
}


//minus operator set
Date& Date::operator--() { //prefix
    helpDecrement();
    return *this;
}

Date Date::operator--(int) { //postfix 
    Date temp{*this};
    helpDecrement();
    return temp;
}

Date& Date::operator-=(unsigned int a) {
    for (int i=0; i<a; i++) helpDecrement();
    return *this;
}

Date operator- (const Date& d, int a) {
    Date newdate{d};
    newdate-=a;
    return newdate;
}


//toString
std::ostream& operator<<(std::ostream& out, const Date& d) {
    out << d.day << "/" << d.month << "/" << d.year;
    return out;
}

bool Date::operator==(const Date& d) const {
    return !(*this<d || *this>d);
}