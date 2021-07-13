//Item.cpp
//definitions of member functions in Item class

#include "Item.h"
#include <stdexcept>
#include <string>

Item::Item (int c, const std::string& n, int q, double p) {
    setCode(c);
    setName(n);
    setQuantity(q);
    setPrice(p);
}

void Item::setCode (int c) { 
    //number between 0 and 99
    //-1 indicates empty slot
    if (c<-1||c>99) throw std::invalid_argument("Code must be an integer between 0 and 99, or -1 for empty slot");
    code = c;
}
        
void Item::setName (const std::string& s) {
    //string must be limited to 14 chars max (+ end of string char)
    size_t length {s.size()};
    if (length>=15) length = 14;
    s.copy(name,length);
    name[length]='\0';
}
        
void Item::setQuantity (int q) {
    if (q<0) throw std::invalid_argument("Quantity must be a positive integer");
    quantity=q;
}
        
void Item::setPrice (double p) {
    if (p<0) throw std::invalid_argument("Price must be a positive integer");
    price=p;
}

int Item::getCode() const {return code;}
std::string Item::getName () const {return name;}
int Item::getQuantity() const {return quantity;}
double Item::getPrice() const {return price;}