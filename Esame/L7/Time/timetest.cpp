//timetest.cpp
//test class time

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

    displayTime ("Initial time:",t); //displays initial values
    t.setTime(13,27,6); //change time
    displayTime("After setTime: ",t); // display new value

    //attempt to set with invalid values
    try {
        t.setTime(99,99,99);
    }
    catch (invalid_argument& e) {
        cout << "Exception: " << e.what() << "\n\n";
    }

    //display time after trying to set invalid time
    displayTime ("After attempting to set an invalid time:",t);
}