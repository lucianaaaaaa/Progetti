#ifndef HEARTRATE_H
#define HEARTRATE_H

#include <string>
#include <iostream>
#include "Date.h"

class HeartRates {
    public:

    //costruttore
    explicit HeartRates (std::string myName, std::string mySurname, Date& birth): 
    name{myName}, surname{mySurname}, birthDate{birth} {}

    //set e get
    std::string getName() const {
        return name;
    }
    std::string getSurname() const {
        return surname;
    }
    void getDate() const{
        std::cout << birthDate.getDay() << "/" << birthDate.getMonth() << "/" << birthDate.getYear();
    }
    void setName (std::string myName) {
        name = myName;
    }
    void setSurname (std::string mySurname) {
        surname = mySurname;
    }
    void setDate (Date& birth) {
        birthDate.setDay(birth.getDay());
        birthDate.setMonth(birth.getMonth());
        birthDate.setYear(birth.getYear());
    }

    //calculate age
    int getAge () {
        Date currentDate (2,5,2021);
        //se non hai ancora compiuto gli anni quest'anno
        if (currentDate.getMonth()<birthDate.getMonth()) {
        return currentDate.getYear()-birthDate.getYear()-1;
        }

        else if (currentDate.getMonth()==birthDate.getMonth()&&currentDate.getDay()<birthDate.getDay()) {
        return currentDate.getYear()-birthDate.getYear()-1;
        }

        return currentDate.getYear()-birthDate.getYear();
    }

    int maximumHeartRate () {
        return 220 - getAge();
    }

    void targetHeartRate () {
        std::cout << "Heart Rate range between " << maximumHeartRate()/2 << "bpm and " 
        << maximumHeartRate()*0.85 << "bpm\n";
    }
    
    private:
    std::string name;
    std::string surname;
    Date birthDate;
};

#endif