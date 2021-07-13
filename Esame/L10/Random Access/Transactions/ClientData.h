//ClientData.h
//stores data of a client in a bank
#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <string>

class ClientData {
    public:
        ClientData (int a =0, const std::string& f = "", const std::string& s = "", double b = 0.0);

        void setAccountNumber(int a);
        void setLastName(const std::string& l);
        void setFirstName (const std::string& f);
        void setBalance (double b);

        int getAccountNumber () const;
        std::string getFirstName () const;
        std::string getLastName() const;
        double getBalance() const;

    private:
        int accountNumber;
        char lastName[15]; //max 15 chars (fixed slots)
        char firstName[15];
        double balance;
};

#endif