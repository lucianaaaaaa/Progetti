//Time.cpp
//implementation of time functions
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Time.h"

using std::invalid_argument;
using std::ostringstream;
using std::setfill;
using std::setw;
using std::string;

void Time::setTime (int h, int m, int s) {
    //validate hour, minute and second
    setHour(h);
    setMinute(m);
    setSecond(s);
}

//return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString () const {
    ostringstream output;
    output << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":" << setw(2) << second;
    return output.str(); //convert to string
}

//return Time as a string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString () const {
    ostringstream output;
    output << setfill('0') << setw(2) << ((hour==0 || hour==12) ? 12 : hour%12) << ":"
        << setw(2) << minute << ":" << setw(2) << second
        << (hour<12 ? "AM" : "PM");
    return output.str(); //convert to string
}

//constructor
Time::Time (int hour, int minute, int second) {
    setTime (hour,minute,second);
}

//set values
void Time::setHour(int h) {
        if (h>=0 && h<24) 
        hour = h;
    else throw invalid_argument ("hour was out of range");
}

void Time::setMinute(int m) {
        if (m>=0 && m<60) 
        minute = m;
    else throw invalid_argument ("minute was out of range");
}

void Time::setSecond(int s) {
        if (s>=0 && s<60) 
        second = s;
    else throw invalid_argument ("second was out of range");
}

unsigned int Time::getHour() const {return hour;}
unsigned int Time::getMinute() const {return minute;}
unsigned int Time::getSecond() const {return second;}

