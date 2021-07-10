//Poly.cpp
//Polynomials class member-functions definitions
#include "Poly.h"
#include <iostream>
 
//constructors
Polynomial::Polynomial(): size{1}, coefs{new double[1]} {
    coefs[0] = 0.0;
}

Polynomial::Polynomial(int s, double coefficients[])
    : size{s}, coefs{new double[s]} {
    for (int i=0; i<s; i++)
        coefs[i]=coefficients[i];
}

Polynomial::Polynomial(double constant): size{1}, coefs{new double[1]} {
    coefs[0] = constant;
}

//copy constructor
Polynomial::Polynomial(const Polynomial& rhs): size{rhs.size}, coefs{new double[rhs.size]} {
    for (int i=0; i<rhs.size; i++) 
        coefs[i] = rhs.coefs[i];
}

//destructor
Polynomial::~Polynomial() {
    delete[] coefs;
}

//member functions
int Polynomial::degree() const {return size-1;} //returns degree of polynomial
void Polynomial::print(std::ostream& out) const {
    for (int i=size-1; i>0; i--) {
        out << coefs[i] << "x^" << i << " + ";
    }
    out << coefs[0];
}

//operators
Polynomial& Polynomial::operator=(const Polynomial& p) {
    if (this == &p) return *this;
    delete[] coefs;
    size = p.size;
    coefs = new double [size];
    for (int i=0; i<size; i++) coefs[i] = p.coefs[i];

    return *this;
} 

Polynomial& Polynomial::operator+=(const Polynomial& p) {
    
    Polynomial newPoly(*this); //backup 
    if (p.size>this->size) {
        delete[] coefs;
        coefs = new double [p.size];
    }
    for (int i=0; i<min(newPoly.size, p.size); i++) 
        coefs[i] = p.coefs[i] + newPoly.coefs[i];

    return *this;
}

Polynomial& Polynomial::operator*= (double a) {
    for (int i=0; i<size; i++)
        coefs[i] *= a;
    return *this;
}

//utility function
int min (int a, int b) {
    if (a<b) return a;
    return b;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    p.print(out);
    return out;
}

Polynomial operator+(const Polynomial& a, const Polynomial& b) {
    Polynomial newPoly(a);
    newPoly+=b;
    return newPoly;
}

Polynomial operator*(double a, const Polynomial& p) {
    Polynomial newPoly(p);
    newPoly*=a;
    return newPoly;
}

Polynomial operator*(const Polynomial& p, double a) {
    Polynomial newPoly(p);
    newPoly*=a;
    return newPoly;
}
