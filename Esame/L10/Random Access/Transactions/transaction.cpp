//transaction.cpp
//management of accounts (reads data from file credit.dat)

//(2) can update an account
//(3) can add a new account
//(4) can delete an account
//(5) can print a list of all accounts in a text file print.txt

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "ClientData.h"

using std::cout; using std::endl; using std::cin;
using std::fstream; using std::ios;
using std::cerr;
using std::ofstream;
using std::setw;

enum class Choice {PRINT = 1, UPDATE, NEW, DELETE, END};

Choice enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void addRecord(fstream&);
void deleteRecord(fstream&);

void outputLine(std::ostream&, const ClientData&);

int main () {
    fstream inOutCredit ("credit.dat", ios::in | ios::out | ios::binary);

    if (!inOutCredit) {
        cerr << "File could not be opened" << endl;
        exit (EXIT_FAILURE);
    }

    Choice choice;

    while ((choice=enterChoice())!=Choice::END) {
        switch (choice) {
            case Choice::PRINT:
                createTextFile(inOutCredit);
                break;
            case Choice::UPDATE:
                updateRecord(inOutCredit);
                break;
            case Choice::NEW:
                addRecord(inOutCredit);
                break;
            case Choice::DELETE:
                deleteRecord(inOutCredit);
                break;
            default:
                cerr << "Incorrect choice" << endl;
                break;
        }

        inOutCredit.clear(); //reset eof indicator after every choice
    }
}

Choice enterChoice() {
    cout << "\nEnter your choice:\n"
        << "1 - store a formatted text file of accounts\n"
        << "    called print.txt for printing\n"
        << "2 - update an account\n"
        << "3 - add a new account\n"
        << "4 - delete an account\n"
        << "5 - exit\n? ";
    int menuChoice;
    cin >> menuChoice;
    return static_cast<Choice> (menuChoice);
}

void createTextFile (fstream& in) {
    ofstream out ("print.txt", ios::out); //basta che sia sequenziale
    if (!out) {
        cerr << "File could not be opened" << endl;
        exit (EXIT_FAILURE);
    }

    //header
    out << std::left << setw(10) << "Account" << setw(16) << "Last Name" 
        << setw(16) << "First Name" << std::right << setw(10) << "Balance" << endl; 

    ClientData client;
    in.seekg(0); //metto il puntatore all'inizio
    in.read (
        reinterpret_cast <char*> (&client), sizeof(ClientData)
    );

    while (!in.eof()) {
        outputLine(out,client);

        in.read (
        reinterpret_cast <char*> (&client), sizeof(ClientData)
        );
    }
}

void outputLine(std::ostream& out, const ClientData& client) {
    out << std::left << setw(10) << client.getAccountNumber() << setw(16) << client.getLastName()
        << setw(16) << client.getFirstName() << std::right << setw(10) << client.getBalance() << endl;
}

void updateRecord (fstream& f) {
    //chiedere numero account
    int acct;
    cout << "\n\nEnter position: ";
    cin >> acct;

    //leggere cliente e salvarlo in ClientData
    f.seekg((acct-1)*sizeof(ClientData));
    ClientData client;
    f.read (
        reinterpret_cast <char*> (&client), sizeof(ClientData)
    );

    if (client.getAccountNumber()!=0) {
    //depositare oppure ritirare
    char c; int amt;
    cout << "Enter amount to be deposited (+) or withdrawn(-): ";
    cin >> amt;
    client.setBalance(client.getBalance()+amt);

    //riscrivere nella posizione giusta
    f.seekp((acct-1)*sizeof(ClientData));
    f.write(
        reinterpret_cast <const char*> (&client), sizeof(ClientData)
    );

    //display record
    outputLine(cout, client);
    }
    else cout << "\nAccount #" << acct << " has no information\n";
}

void addRecord(fstream& f) {
    //chiedere numero account
    int acct;
    cout << "\n\nEnter position: ";
    cin >> acct;

    //leggere cliente per verificare che sia vuoto
    f.seekg((acct-1)*sizeof(ClientData));
    ClientData blank;
    f.read (
        reinterpret_cast <char*> (&blank), sizeof(ClientData)
    );    
    
    if (blank.getAccountNumber()==0)  {
        int accountNumber; double balance; std::string first; std::string last;

        cout << "Enter account number, first name, last name and balance: ";
        cin >> accountNumber >> first >> last >> balance;
        ClientData client (accountNumber,first,last,balance);

        outputLine(cout,client);

        f.seekp((acct-1)*sizeof(ClientData));
        f.write(
        reinterpret_cast <const char*> (&client), sizeof(ClientData)
        );

    }
    else cout << "Account #" << acct << " already contains information\n";
}

void deleteRecord(fstream& f) {
    //chiedere numero account
    int acct;
    cout << "\n\nEnter position: ";
    cin >> acct;

    //leggere cliente per verificare che non sia vuoto
    f.seekg((acct-1)*sizeof(ClientData));
    ClientData client;
    f.read (
        reinterpret_cast <char*> (&client), sizeof(ClientData)
    ); 
    
    if (client.getAccountNumber()!=0) {

        ClientData blank;
        f.seekp((acct-1)*sizeof(ClientData));
        f.write(
            reinterpret_cast <const char*> (&blank), sizeof(ClientData)
        );

    } else cout << "Account #" << acct << " is already empty\n";
}