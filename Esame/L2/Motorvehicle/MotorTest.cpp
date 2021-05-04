#include <iostream>
#include <string>
#include "MotorVehicle.h"
using std::cout;

int main () {
    MotorVehicle moto ("Yamaha","Diesel","blue",2020,400);
    //display initial values
    moto.displayCarDetails();
    //modify year
    cout << "\nEnter new year of Manufacture: ";
    int y;
    std::cin >> y;
    moto.setYear(y);
    //display new values
    moto.displayCarDetails();
}