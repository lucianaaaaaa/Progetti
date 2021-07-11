//Complex.cpp

#include <iostream>
#include "Complex.h"
#include <cmath>

Complex::Complex (double a, double b): real{a}, imag{b} {} //constructor
bool Complex::operator== (const Complex& c) const {
    if (real==c.real && imag==c.imag) return true;
    return false;
}

Complex conjugate(const Complex& c) {
    Complex a(c.real, -c.imag);
    return a;
}

void Complex::setReal(double a) {real=a;}
void Complex::setImag(double a) {imag=a;}
double Complex::getReal() const {return real;}
double Complex::getImag() const {return imag;}
//in realtà tramite le funzioni set e get non avrei bisogno che gli operatori fossero friend

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.real << " + " << c.imag << "j";
    return out;
}

Complex operator+ (const Complex& a,const Complex& b) {
    Complex c(a);
    c.real += b.real;
    c.imag += b.imag;
    return c;
}

Complex operator- (const Complex& a,const Complex& b) {
    Complex c(-b.real, -b.imag);
    c.real += a.real;
    c.imag += a.imag;
    return c;
}

Complex operator*(const Complex& c, double a) {
    Complex b(c);
    b.real*=a;
    b.imag*=a;
    return b;
}

Complex operator* (const Complex& a,const Complex& b) {
    Complex c;
    c.real = a.real*b.real - a.imag*b.imag;
    c.imag = a.real*b.imag + a.imag*b.real;
    return c;
}

Complex operator/ (const Complex& a,const Complex& b) {
    double mod {0};
    mod = pow(b.real,2) + pow(b.imag,2);
    Complex c(a*conjugate(b));
    c = c*(1/mod);
    return c;
}