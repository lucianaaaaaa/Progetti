#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
    public:
    explicit Date(int d, int m, int y): day{d}, year{y} {
        if (m>=1 && m<=12)
        month = m;
    }

    //set e get
    int getDay () const {
        return day;
    }
    int getMonth () const {
        return month;
    }
    int getYear () const {
        return year;
    }
    void setDay (int d) {
        day = d;
    }
    void setMonth (int m) {
        if (m>=1 && m<=12)
        month = m;
        else
        std::cout << "Invalid month.\n";
    }
    void setYear (int d) {
        day = d;
    }

    //display date
    void displayDate () {
        std::cout << day << "/" << month << "/" << year;
    }
    
    private:
    int day;
    int month{1};
    int year;
};

#endif