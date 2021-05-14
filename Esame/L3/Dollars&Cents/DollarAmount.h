//DollarAmount.h
//Implementation of DollarAmount class with dollars and cents

#ifndef DOLLARNCENTS_H
#define DOLLARNCENTS_H

#include <string>
#include <cmath>
#include <stdexcept>

class DollarAmount {
    public:
    //int64_t value constructor
    explicit DollarAmount (int64_t value) {
        if (value<0)
            throw std::invalid_argument ("Cannot be negative values");
        
        dollars = value/100;
        cents = value%100;
    }

    //constructor with 2 parameters
    explicit DollarAmount (int d, int c) {
        if (d<0 || c<0)
            throw std::invalid_argument ("Cannot be negative values");
    
        dollars = d;
        cents = c;
    }

    //add right's amount
    void add(DollarAmount right) {
        int value; //metodo 1: fai i calcoli a mano
        value = cents + right.cents;
        if (value>=100) {
            dollars += right.dollars + 1;
            cents = value%100;
        }
        else {
            cents = value;
            dollars += right.dollars;
        }
    }

    //subtract right's amount
    void subtract(DollarAmount right) { 
        //metodo pigro
        int64_t amount {dollars*100+cents};
        int64_t ramount {right.dollars*100 + right.cents};

        amount -= ramount;
        dollars = amount/100;
        cents = amount%100;
    }

    //divide by an integer value
    void divide (int divisor) {
        int64_t amount {dollars*100+cents};
        amount /= divisor;

        dollars = amount/100;
        cents = amount%100;
    }

    //calculate and add interest
    void addInterest (int rate, int divisor) {
        //create DollarAmount of interest (calculate)
        int64_t amount {dollars*100+cents};
        DollarAmount interest {(amount*rate+ divisor/2)/divisor};
        //add
        add(interest);
    }

    std::string toString() const {
        std::string out;
        out = dollars + ".";
        (cents<10) ? out+="0" : out+="";
        return out;
    }

    int getTotal() {return dollars*100 + cents;}

    private:
    int dollars{0}; //dollars
    int cents{0}; //cents
};

#endif