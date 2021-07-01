//Point.cpp
//member-functions definitions for class Point
#include "Point.h"
#include <stdexcept>

Point::Point (double xc, double yc) {
    setX(xc);
    setY(yc);
}

//valid coords are between 0 and 20.0
void Point::setX(double xc) {
    if (xc<0 || xc>20.0)
        throw std::invalid_argument("invalid x coordinate");
    
    x=xc;
}

void Point::setY(double yc) {
    if (yc<0 || yc>20.0)
        throw std::invalid_argument("invalid y coordinate");
    
    y=yc;
}

double Point::getX () const {return x;}
double Point::getY () const {return y;}