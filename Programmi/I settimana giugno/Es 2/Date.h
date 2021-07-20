//Date.h
//interface for class Date.h with overloaded operators
#include <array>
#include <ostream>

#ifndef DATE_H
#define DATE_H

class Date {
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend Date operator+ (int, const Date&); //7+d2
    friend Date operator+ (const Date&, int); //d2+7
    friend Date operator- (const Date&, int);

    public:
        explicit Date (unsigned int = 1, unsigned int = 1, unsigned int = 1900);
        void setDate (int, int, int);
        
        //increment operators
        Date& operator++(); //prefix, +1
        Date operator++(int); //postfix, +1
        Date& operator+=(unsigned int); //add days

        //decrement operators
        Date& operator--(); //prefix
        Date operator--(int); //postfix
        Date& operator-=(unsigned int); //subtract dates

        //relational operators
        bool operator< (const Date&) const;
        bool operator> (const Date&) const;
        bool operator<= (const Date&) const;
        bool operator>= (const Date&) const;
        bool operator!= (const Date&) const;

        static bool leapYear(int); //is year a leap year?
        bool endOfMonth(int) const; //is day ate the end of month?

    private:
        unsigned int month;
        unsigned int day;
        unsigned int year;

        static const std::array <unsigned int, 13> days; //days per month
        void helpIncrement(); //utility function to increment date
        void helpDecrement(); //decrement date
};

#endif