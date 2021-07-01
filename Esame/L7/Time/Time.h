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
        void setTime (int, int, int); //set hour, minuute and second
        void setHour (int);
        void setMinute (int);
        void setSecond (int);

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