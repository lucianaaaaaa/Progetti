//reading.cpp
//reading from a sequential file

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using std::cout; using std::endl;
using std::ifstream;
using std::ios;
void outputLine(int, const std::string&, double);

int main () {
    ifstream inClientFile ("clients.txt",ios::in);

    if (!inClientFile) {
        std::cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    cout << std::left << std::setw(10) << "Account"
        << std::setw(13) << "Name" << "Balance\n" << std::fixed << std::showpoint;
    
    int account;
    std::string name;
    double balance;

    while (inClientFile >> account >> name >> balance) {
        outputLine(account,name,balance);
    }

}

void outputLine (int account, const std::string& name, double balance) {
    cout << std::left << std::setw(10) << account << std::setw(13)
        << name << std::setw(7) << std::setprecision(2) << std::right << balance << endl;
}