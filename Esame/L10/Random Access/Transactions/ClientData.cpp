//ClientData.cpp
//ClientData definitions of member functions

#include "ClientData.h"
#include <string>

ClientData::ClientData (int a, const std::string& f, const std::string& l , double b ) 
    : accountNumber{a}, balance{b} {
        setLastName(l);
        setFirstName(f);
    }

void ClientData::setAccountNumber(int a) {accountNumber=a;}
void ClientData::setLastName(const std::string& l) {
    //copia tutta la stringa o fino al 15esimo carattere
    size_t length {l.size()};
    if (length>=15) length=14;
    l.copy(lastName,length);
    lastName[length]='\0'; //carattere di fine stringa
}
void ClientData::setFirstName (const std::string& f) {
    //copia tutta la stringa o fino al 15esimo carattere
    size_t length {f.size()};
    if (length>=15) length=14;
    f.copy(firstName,length);
    firstName[length]='\0'; //carattere di fine stringa
}
void ClientData::setBalance (double b) {balance=b;}

int ClientData::getAccountNumber () const {return accountNumber;}
std::string ClientData::getFirstName () const {return firstName;}
std::string ClientData::getLastName() const {return lastName;}
double ClientData::getBalance() const {return balance;}
