//Poly.h
//Polynomials class definition

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
    public:
        //constructors
        Polynomial(); //sets default 0.0 polynomial
        Polynomial(int s, double coefficients[]); //set coefficients
        Polynomial(const Polynomial& rhs); //copy constructor
        explicit Polynomial (double constant); //set polynomial to a constant value

        //destructor
        ~Polynomial(); 

        int degree() const; //returns degree of polynomial
        void print(std::ostream& out = std::cout) const;

        //operators
        Polynomial& operator= (const Polynomial&);
        Polynomial& operator+= (const Polynomial&);
        Polynomial& operator*= (double); //scalar multiplication

    private:
        int size; //polynomial degree +1
        double* coefs; //ptr to built-in array of coefficients

};

std::ostream& operator<<(std::ostream& out, const Polynomial& p);

Polynomial operator+(const Polynomial& a, const Polynomial& b);
Polynomial operator*(double a, const Polynomial& p);
Polynomial operator*(const Polynomial& p, double a);

int min (int a, int b);
#endif