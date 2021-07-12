#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>
#include <vector>
using std::cout; using std::endl;

int main () {
    Rectangle r(2);
    Circle c;
    std::vector <Shape*> shapes;
    shapes.push_back(&c);
    shapes.push_back(&r);

    for (Shape* s:shapes) cout << (*s).area() << endl;

}