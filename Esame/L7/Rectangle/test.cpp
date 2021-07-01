//test rectangle class
#include <iostream>
#include "Rectangle.h"
#include "Point.h"
#include <stdexcept>
using std::cout; using std::endl; using std::invalid_argument;

int main () {
    Point a(13,12);
    Point b(17,12);
    Point c(17,9);
    Point d(13,9);
    Rectangle r(a,b,c,d);
    r.draw();
    cout << endl;
    cout << "Rectangle height: " << r.getHeight() << endl;
    cout << "Rectangle width: " << r.getWidth() << endl;
    cout << "Rectangle perimeter: " << r.getPerimeter() << endl;
    cout << "Rectangle area: " << r.getArea() << endl;

    d.setX(1);
    try {r.setCoords(a,b,c,d);}
    catch (invalid_argument& e) {cout << "Exception: " << e.what() << endl;}
}