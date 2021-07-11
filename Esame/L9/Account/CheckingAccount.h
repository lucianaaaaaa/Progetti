//CheckingAccount.h
#include "Account.h"
#include <string>

#ifndef CHECK_H
#define CHECK_H

class CheckingAccount: public Account {
    public:
        CheckingAccount(double initial, double atm)
            : Account(initial), totalFees{0.0}, atmFee{atm} {}

        void cashWithdrawal (double amt) {
            totalFees+=atmFee;
            debit(amt+atmFee);
        }
        
        double getTotalFees() const {return totalFees;}
        std::string type() {return "Checking Account";}
    private:
        double totalFees;
        double atmFee;
};

#endif