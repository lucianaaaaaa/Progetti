//Account.h
//Account class that contains a name data member
//and membre functions to set and get its value
#include <string>
#include <iostream>

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    public: 

    //constructor
    explicit Account (std::string accountName, int initialBalance): name{accountName} {
        //check if balance is valid
        if (initialBalance>0)
        balance = initialBalance;
    }
    
    //deposit money (only add)
    void deposit (int depositAmount) {
        if (depositAmount>0)
        balance += depositAmount;
    }
    
    //withdraw money
    void withdraw (int withdrawAmount) {
        if (withdrawAmount<balance)
        balance = balance - withdrawAmount;
        else 
        std::cout << "Withdrawal amount exceeded account balance.\n";
    }
    
    //set and get
    int getBalance () const {
        return balance;
    }

    void setName(std::string accountName) {
        name = accountName;
    }

    std::string getName () const {
        return name;
    }

    private:
    std::string name;
    int balance{0};
};

#endif