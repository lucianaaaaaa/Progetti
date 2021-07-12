//management.cpp
//manage banking accounts and classify them

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using std::cout; using std::cin; using std::endl;
using std::ifstream; using std::ios;
using std::cerr;

void menu();
int getRequest();
void outputLine (int account, const std::string& name, double balance);
void displayAccounts(int request, int account, const std::string& name, double balance);

int main () {
    ifstream inClientFile ("clients.txt",ios::in);
    if (!inClientFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    int request{0};

    do {
        menu();
        request = getRequest();

        int account; std::string name; double balance;
        while (inClientFile>>account>>name>>balance)        
        displayAccounts(request,account,name,balance);
        
        //restore position pointer
        inClientFile.clear(); //clears eof flag
        inClientFile.seekg(0);
    }while (request!=4);
    cout << "\n\nGOODBYE!" << endl;
}

void menu() {
    cout << "\n\nCREDIT MANAGEMENT OPTIONS:\n" 
        << "(1) DISPLAY NEGATIVE BALANCE ACCOUNTS\n"
        << "(2) DISPLAY POSITIVE BALANCE ACCOUNTS\n"
        << "(3) DISPLAY ZERO BALANCE ACCOUNTS\n"
        << "(4) EXIT MANAGEMENT PROGRAM\n" << endl;
}

int getRequest() {
    int a;
    cout << "PLEASE ENTER YOUR REQUEST: ";
    cin >> a;
    return a; 
}

void displayAccounts(int request, int account, const std::string& name, double balance) {
    switch (request) {
        case 1:
            if (balance<0) outputLine(account,name,balance);
            break;
        case 2:
            if (balance>0) outputLine(account,name,balance);
            break;
        case 3:
            if (balance==0) outputLine(account,name,balance);
            break;
    }
}

void outputLine (int account, const std::string& name, double balance) {
    cout << std::left << std::setw(10) << account << std::setw(13)
        << name << std::setw(7) << std::right << balance << endl;
}