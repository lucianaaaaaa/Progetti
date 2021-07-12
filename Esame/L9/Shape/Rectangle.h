//Rectangle.h
#include "Shape.h"
#include <stdexcept>

#ifndef RECT_H
#define RECT_H

class Rectangle: public Shape {
    public:
        explicit Rectangle(double w = 1.0, double h = 1.0) {
            setWidth(w);
            setHeight(h);
        }

        void setWidth(double w) {
            if (w<0) throw std::invalid_argument("width cannot be negative");
            width=w;
        }
        void setHeight(double h) {
            if (h<0) throw std::invalid_argument("height cannot be negative");
            height = h;
        }

        double getWidth () const {return width;}
        double getHeight () const {return height;}


        double area() const {
            return width*height;
        }

    private:
        double width;
        double height;
};

#endif