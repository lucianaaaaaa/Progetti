//Saxophonist.h
//Saxophonist class
#include <iostream>

#ifndef SAXOPHONE_H
#define SAXOPHONE_H

enum saxtype {SOPRANO, ALTO, TENOR, BARITONE};

class Saxophonist {
    public:
    static int saxCount;
    Saxophonist (std::string n, saxtype p)
        : name{n}, type{p} {
        std::cout << "Constructor called" << std::endl;
        saxCount++;
        }
    ~Saxophonist() {
        std::cout << "Destructor called" << std::endl;
        --saxCount;
    }
    int getCount() {return saxCount;}

    private:
    std::string name; //Saxophonist name
    saxtype type;  //type of sax played
};

#endif