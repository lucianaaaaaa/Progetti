//Measurement.h
//user interface for class Measurement

#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include "Date.h"

class Measurement {
    public:
    Measurement(double = 0.0, const Date& = Date());

    //set e get
    void setPpm (double);
    void setDate (const Date&);
    double getPpm () const;
    const Date& getDate () const;
    
    //overloading operatore <
    bool operator< (const Measurement&) const;

    private:
        double ppm;
        Date date;
};

#endif