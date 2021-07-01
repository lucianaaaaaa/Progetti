//Rectangle.cpp
//member-functions definitions for class Rectangle

#include "Rectangle.h"
#include <stdexcept>
#include <iomanip>
#include <iostream>
using std::cout; using std::endl;

Rectangle::Rectangle (Point pnt1, Point pnt2, Point pnt3, Point pnt4, char border, char fill) 
    : perimeter{border}, filler{fill} {
        setCoords(pnt1, pnt2, pnt3, pnt4);
    }

void Rectangle::setCoords (Point pnt1, Point pnt2, Point pnt3, Point pnt4) {
    //check if points form a rectangle
    if (pnt1.getY()==pnt2.getY(), pnt1.getX()==pnt4.getX(), pnt2.getX()==pnt3.getX(), pnt3.getY()==pnt4.getY()) {
        p1 = pnt1;
        p2 = pnt2;
        p3 = pnt3;
        p4 = pnt4;
    } else throw std::invalid_argument("Provided points do not form a rectangle");
}

void Rectangle::setPerimeter(char p) {perimeter=p;}
void Rectangle::setFiller (char f) {filler=f;}

double Rectangle::getHeight () const {return p1.getY()-p4.getY();}
double Rectangle::getWidth () const {return p2.getX()-p1.getX();}
double Rectangle::getArea () const {return getHeight()*getWidth();}
double Rectangle::getPerimeter () const {return (getHeight()+getWidth())*2;}
bool Rectangle::isSquare() const {return getWidth()==getHeight();}

void Rectangle::draw() const {
    for (int i=0; i<=20; i++) {
        for (int j=0; j<=20; j++) {
            if (i<p4.getY()||i>p1.getY()) cout << ".";
            else if (i==p4.getY()||i==p1.getY()) {
                if (j<p4.getX()||j>p3.getX()) cout << ".";
                else cout << perimeter;
            }
            else {
                if (j==p4.getX()||j==p3.getX()) cout << perimeter;
                else if (j<p4.getX()||j>p3.getX()) cout << ".";
                else cout << filler;
            }
        }
        cout << endl;
    }
}
