//DollarAmount.h
//stores dollar amounts as whole numbers of cents

#ifndef DOLLAR_H
#define DOLLAR_H

#include <string>
#include <cmath>

class DollarAmount {
    public:
    //int64_t value constructor
    explicit DollarAmount (int64_t value): amount{value} {}

    //add right's amount
    void add(DollarAmount right) {
        amount += right.amount;
    }

    //subtract right's amount
    void subtract(DollarAmount right) {
        amount -= right.amount;
    }

    //calculate and add interest
    void addInterest (int rate, int divisor) {
        //create DollarAmount of interest (calculate)
        DollarAmount interest {(amount*rate+ divisor/2)/divisor};
        //add
        add(interest);
    }

    std::string toString() const {
        std::string dollars{std::to_string(amount/100)}; //to_string converts a number to string
        std::string cents{std::to_string(std::abs(amount%100))}; //abs = absolut value

        return dollars + "." + (cents.size()==1 ? "0" : "") + cents;
    }

    private:
    int64_t amount{0}; //amount in cents
};

#endif