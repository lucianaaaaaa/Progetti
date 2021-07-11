//accountTest.cpp
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
using std::cout; using std::endl;

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
}