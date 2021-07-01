//dateTest.cpp
//program to test object Date

#include "Date.h"
#include <iostream>
#include <stdexcept>

int main () {
    Date date1 (1,3,2021);
    try {Date date2 (1,13,2021);}
        catch (std::invalid_argument &e) {
        std::cout << "Exception: " << e.what() << "\n\n";}
    try {Date date3 (32,1,2021);}
        catch (std::invalid_argument &e) {
        std::cout << "Exception: " << e.what() << "\n\n";}
}