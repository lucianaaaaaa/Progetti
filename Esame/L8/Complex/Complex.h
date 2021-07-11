//Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
    friend Complex operator+ (const Complex& a,const Complex& b);
    friend Complex operator- (const Complex& a,const Complex& b);
    friend Complex operator* (const Complex& a,const Complex& b);
    friend Complex operator/ (const Complex& a,const Complex& b);
    friend Complex operator* (const Complex& c, double a);
    friend Complex conjugate(const Complex& c);
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    public:
    //default constructor
    explicit Complex (double = 0.0, double = 0.0);

    bool operator==(const Complex&) const;
    

    void setReal(double);
    void setImag(double);
    double getReal() const;
    double getImag() const;

    private:
    double real; //real part
    double imag; //imaginary part
};

#endif