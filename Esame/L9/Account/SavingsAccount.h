//SavingsAccount.h
#include "Account.h"
#include <string>

#ifndef SAVE_H
#define SAVE_H

class SavingsAccount: public Account {
    public:
        SavingsAccount(double initial, double rate)
            : Account(initial), annualRate{rate} {}

        double totalAfterYears(int years) const {
            double b{getBalance()};
            for (int i=0; i<years; i++)
            b+=b*annualRate;
            return b;
        }

        double calculateInterest () const {return annualRate*getBalance();}
        virtual std::string type() const override {return "Saving Account";}
    private:
        double annualRate;
};

#endif