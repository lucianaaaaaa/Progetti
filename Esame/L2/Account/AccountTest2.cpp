//AccountTest2.cpp
//Displating and updating an Account object
#include <iostream>
#include <string>
#include "Account.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void displayAccount (Account account);

int main () {
    Account account1{"Jane Green", 50};
    Account account2{"John Blue",400}; //balance will be set to 0

    //display initial balance
    cout << "account1: " << account1.getName() << " balance is $"
        << account1.getBalance() <<endl;
    cout << "account2: " << account2.getName() << " balance is $"
        << account2.getBalance();

    /**
    cout << "\n\nEnter deposit amount for account1: ";
    int depositAmount;
    cin >> depositAmount;
    cout << "adding " << depositAmount << " to account1 balance\n";
    account1.deposit(depositAmount);

    cout << "account1: " << account1.getName() << " balance is $"
        << account1.getBalance();

    cout << "\n\nEnter deposit amount for account2: ";
    cin >> depositAmount;
    cout << "adding " << depositAmount << " to account2 balance\n";
    account2.deposit(depositAmount);    
    cout << "account2: " << account2.getName() << " balance is $"
        << account2.getBalance(); 
    **/

    int withdrawAmount;
    cout << "\n\nEnter withdrawal amount for account2: ";
    cin >> withdrawAmount;
    cout << "subtracting " << withdrawAmount << " from account2 balance\n";
    account2.withdraw(withdrawAmount);
    /*    
    cout << "account2: " << account2.getName() << " balance is $"
        << account2.getBalance(); 
    */
   displayAccount(account2);

}

void displayAccount (Account account) {
    cout << "account: " << account.getName() << " balance is $" << account.getBalance();
}