//writing.cpp
//how to write in a sequential file
#include <iostream>
#include <string>
#include <fstream> //file stream
#include <cstdlib> //functions cerr and exit

using std::ofstream; //output to file stream (write)
using std::ios; //input-output stream

using std::cout; using std::endl; using std::cin;

int main () {
    ofstream outClientFile {"clients.txt", ios::out};

    //exit program if unable to create file
    if (!outClientFile) {
        std::cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter the account, name and balance.\n"
        <<"Enter end-of-file to end input.\n? ";
    
    int account;
    std::string name;
    double balance;

    while (cin>>account>>name>>balance) {
        outClientFile << account << " " << name << " " << balance << endl;
        cout << "? ";
    }
}

