//Rectangle.h
//Reectangle class interface

/*  p4***********p3
    *------------*
    *------------*
    p1***********p2
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle { 
    public:
        explicit Rectangle (Point = Point(0.0,1.0), Point = Point(1.0,1.0),
        Point = Point(1.0,0.0), Point = Point(0.0,0.0), char = '*', char = '-'); //constructor

        void setCoords (Point, Point, Point, Point); //define coords of rectangle
        void draw () const; // display rectangle

        void setPerimeter (char); //set char for perimeter
        void setFiller (char); //set char for filler

        double getPerimeter() const; //calculate perimeter
        double getArea() const; //calculate area
        double getHeight() const; //calculate height
        double getWidth() const; //calculate width
        bool isSquare () const; //true if width=length

    private:
        Point p1;
        Point p2;
        Point p3;
        Point p4;
        char perimeter;
        char filler;
};

#endif