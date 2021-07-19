//Measurement.cpp
//member functions definitions for class Measurement

#include "Measurement.h"
#include <stdexcept> //for exceptions

Measurement::Measurement (double p, const Date& d): date{d} {
    setPpm(p);
}

void Measurement::setPpm (double p) {
    if (p<0) throw std::invalid_argument ("ppm measurement cannot be negative");
    ppm=p;
}

void Measurement::setDate (const Date& d) {
    date = d;
}

double Measurement::getPpm () const {return ppm;}
const Date& Measurement::getDate () const {return date;}

bool Measurement::operator< (const Measurement& second) const {
    if (this->date==second.date) return ppm<second.ppm;
    return this->date<second.date;
    //else return ppm<second.ppm; 
    //se la data è uguale, ordina in base al ppm 
}