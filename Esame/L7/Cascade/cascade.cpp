//cascade.cpp

#include <iostream>
#include <stdexcept>
#include "Time.h"
using std::cout;
using std::string;
using std::invalid_argument;

//display time in both formats
void displayTime (const string& message, const Time& time) {
    cout << message << "\nUniversal time: " << time.toUniversalString()
        << "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main () {
    Time t;

    t.setHour(18).setMinute(30).setSecond(22);

    //output time
    cout << "Universal time: " << t.toUniversalString()
        << "\nStandard time: " << t.toStandardString() << std::endl;

    cout << "New standard time: " << t.setTime(20,20,20).toStandardString() << std::endl;
}