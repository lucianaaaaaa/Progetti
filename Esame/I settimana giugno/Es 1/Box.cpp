//Box.cpp
//implementation of Box member functions

#include "Box.h"
#include <stdexcept>

Box::Box(int id, double w, double v, bool flag)
    : perishable{flag} {
        setId(id);
        setWeight(w);
        setValue(v);
    }

void Box::setId (int id) {
    if(id<0) throw std::invalid_argument("Box id must be a positive integer");
    box_id=id;
}

void Box::setWeight (double w) {
    if(w<0) throw std::invalid_argument("Weight of box must be positive");
    weight=w;
}

void Box::setValue (double v) {
    if(v<0) throw std::invalid_argument("Value of box must be positive");
    value=v;
}

void Box::setPerishable (bool flag) {perishable=flag;}

int Box::getId() const {return box_id;}
double Box::getWeight() const {return weight;}
double Box::getValue() const {return value;}
bool Box::isPerishable() const {return perishable;}