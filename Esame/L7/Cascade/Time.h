//Time.h
//Time class definition
#include <string>

//prevent multiple inclusions of the same header
#ifndef TIME_H
#define TIME_H

class Time {
    public:
        explicit Time(int=0, int=0, int=0); // default constructor

        //set functions
        Time& setTime (int, int, int); //set hour, minuute and second
        Time& setHour (int);
        Time& setMinute (int);
        Time& setSecond (int);

        //get functions
        unsigned int getHour() const;
        unsigned int getMinute() const;
        unsigned int getSecond() const;

        //display time
        std::string toUniversalString () const; //24 hour format
        std::string toStandardString () const; //12 hour format
    private:
        unsigned int hour {0};
        unsigned int minute {0};
        unsigned int second {0};
};
#endif