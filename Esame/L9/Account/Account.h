//Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
    public:
        Account() : balance{0.0} {} //default
        explicit Account(double initial) : balance{initial} {}

        void credit (double amt) {balance+=amt;} //deposit
        void debit (double amt) {balance-=amt;} //withdraw

        double getBalance() const {return balance;}
        virtual std::string type() const {return "Account";}
    private:
        double balance;
};

#endif