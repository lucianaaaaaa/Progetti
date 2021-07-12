//Circle.h
#include "Shape.h"
#include <stdexcept>
#include <cmath>

#ifndef CIRCLE_H
#define CIRCLE_H

double pi = 3.141;

class Circle: public Shape {
    public:
        explicit Circle(double r = 1.0) {
            setRadius(r);
        }

        void setRadius(double r) {
            if (r<0) throw std::invalid_argument("radius cannot be negative");
            radius=r;
        }
        double getRadius () const {return radius;}


        double area() const {
            return pow(radius,2)*pi;
        }

    private:
        double radius;
};

#endif