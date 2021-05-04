//motorvehicle class
#include <iostream>
#include <string>

#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

class MotorVehicle {
    public: 

    //constructor
    explicit MotorVehicle (std::string makeName, std::string fuelName, std::string colorName, int year, int engine): 
    make{makeName}, fuelType{fuelName}, color{colorName} {
        //check if year and engine are valid
        if (year>0)
        yearOfManufacture = year;
        if (engine>0)
        engineCapacity = engine;
    }
    
    //get
    std::string getMake () const {
        return make;
    }
    std::string getFuel () const {
        return fuelType;
    }    
    std::string getColor () const {
        return color;
    }
    int getYear () const {
        return yearOfManufacture;
    }
    int getEngine () const {
        return engineCapacity;
    }

    //set
    void setMake(std::string makeName) {
        make = makeName;
    }
    void setFuel(std::string fuelName) {
        fuelType = fuelName;
    }    
    void setColor(std::string colorName) {
        color = colorName;
    }
    void setYear(int year) {
        if (year>0)
        yearOfManufacture = year;
        else std::cout << "Invalid year.\n";
    }   
    void setEngine(int engine) {
        if (engine>0)
        engineCapacity = engine;
        else std::cout << "Invalid engine capacity.\n";
    }  

    //display details
    void displayCarDetails () {
        std::cout << "Make: " << make << "\nFuel type: " << fuelType 
            << "\nColor: " << color << "\nYear of manufacture: " << yearOfManufacture
            << "\nEngine capacity: " << engineCapacity;
    }
 
    private:
    std::string make;
    std::string fuelType;
    std::string color;
    int yearOfManufacture{1900};
    int engineCapacity{0};
};

#endif