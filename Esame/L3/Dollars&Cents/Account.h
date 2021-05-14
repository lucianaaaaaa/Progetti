//Account.h
//Implementation of class Account with class DollarAmount
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include "DollarAmount.h"

class Account {
    public: 

    //constructor
    explicit Account (std::string accountName, int initialBalance): name{accountName}, balance{initialBalance} {}
    
    //deposit money (only add)
    void deposit (int depositAmount) {
        DollarAmount deposit(depositAmount);
        balance.add(deposit);
    }
    
    //withdraw money
    void withdraw (int withdrawAmount) {
        DollarAmount withdraw(withdrawAmount);
        balance.subtract(withdraw);
    }
    
    //set and get
    std::string BalanceString () { //returns balance as a string dollars.cents
        return balance.toString();
    }

    int getBalance () { //returns balance as a whole number of cents
        return balance.getTotal ();
    }

    void setName(std::string accountName) {
        name = accountName;
    }

    std::string getName () const {
        return name;
    }

    private:
    std::string name;
    DollarAmount balance;
};

#endif