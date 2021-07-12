//accountTest.cpp
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <vector>
#include <typeinfo>
using std::vector;
using std::cout; using std::endl; using std::cin;

void management(Account* a);
void manageSavings(SavingsAccount* a);

int main () {
    Account acct(1000.0);
    acct.credit(1000.0);
    acct.debit(100);
    cout << "Account balance is: $" <<acct.getBalance() << endl;

    CheckingAccount checking(1000,2);
    checking.credit(1000);
    checking.cashWithdrawal(100);
    cout << "Checking balance is: $" << checking.getBalance() << endl;
    cout << "Checking total fees is: $" << checking.getTotalFees() << endl;

    SavingsAccount saving(1000,0.05);
    saving.credit(1000);
    cout << "Savings balance is: $" << saving.getBalance() << endl;
    for (int i=1; i<4; i++)
    cout << "Savings after " << i << " years: $" << saving.totalAfterYears(i) << endl;

    cout << "\nBANKING ACCOUNT MANAGEMENT VIA VECTOR OF BASE-CLASS POINTERS AND DYNAMIC CASTING\n\n";

    vector <Account*> accounts {&checking,&saving,&acct};
    for (Account* a: accounts) management(a);

}

void management(Account* a) {
    int amount;
    unsigned int choice;
    
    do {
    cout << "ACCOUNT MANAGEMENT MENU:\n" 
        << "(1) DEPOSIT \n(2) WITHDRAW \n(3) QUIT\n\n";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "ENTER DEPOSITED AMOUNT: ";
            cin >> amount;
            a->credit(amount); //should check if valid
            break;
        case 2:
            cout << "ENTER AMOUNT TO WITHDRAW: ";
            cin >> amount;
            a->debit(amount); //should check if valid
            break;
        case 3: 
            cout << "QUITTING" ;
            break;
        }
    } while (choice!=3);
    
    //check if account is a savingsAccount
    SavingsAccount* save = dynamic_cast <SavingsAccount*> (a);
    if (save!=nullptr) manageSavings(save);

    //print balance after operations
    cout << "\n\nFINAL BALANCE: " << a->getBalance() << endl;
}

void manageSavings(SavingsAccount* a) {
    char choice;
    cout << "\n\nYOUR ACCOUNT IS A SAVINGS ACCOUNT. DO YOU WANT TO CALCULATE INTEREST? (Y/N)" << endl;
    cin >> choice;
    if (choice=='Y') {
        cout << "\nINTEREST IS: " << a->calculateInterest() << endl;
        a->totalAfterYears(1);
        cout << "ADDED INTEREST TO TOTAL BALANCE\n";

    }
    else cout << "\nQUITTING\n";
}