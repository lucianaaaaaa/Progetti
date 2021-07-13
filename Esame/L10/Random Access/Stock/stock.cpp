//stock.cpp
#include "Item.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using std::cout; using std::cin; using std::endl;
using std::cerr;
using std::fstream;
using std::ios;
using std::setw;

enum class Choice {PRINT=1, UPDATE, NEW, DELETE, END};

Choice getChoice();
void printFile(fstream&);
void outputLine (std::ostream& out, const Item& item);
void updateItem(fstream&);
void update(Item& i);
void addItem(fstream&);
void deleteItem(fstream&);

int main () {
    //open file
    fstream stockFile ("hardware.dat",ios::out|ios::in|ios::binary);
    if (!stockFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    Choice request;
    request=getChoice();

    while (request!=Choice::END) {
        switch (request)
        {
        case Choice::PRINT:
            printFile(stockFile);
            break;
        case Choice::UPDATE:
            updateItem(stockFile);
            break;
        case Choice::NEW:
            addItem(stockFile);
            break;
        case Choice::DELETE:
            deleteItem(stockFile);
            break;
        
        default:
            cout << "\nInvalid choice" << endl;
            break;
        }

        request=getChoice();
        stockFile.clear();
    }
    cout << "\nGOODBYE!" << endl;
    stockFile.close();
}

Choice getChoice () {
    //print menu
    cout << "STOCK MANAGEMENT OPTIONS:\n"
        << "1 - PRINT LIST OF ITEMS IN PRINT.TXT\n"
        << "2 - UPDATE EXISTING ITEM\n"
        << "3 - ADD NEW ITEM\n"
        << "4 - DELETE EXISTING ITEM\n"
        << "5 - END PROGRAM\n\n? ";
    
    int choice;
    cin >> choice;
    return static_cast<Choice>(choice);
}

void printFile (fstream& f) {
    //prints list of all items
    std::ofstream outFile ("print.txt",ios::out);
    if (!outFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    //print header
    outFile << std::left << setw(6) << "Code" << setw(16) << "Name" 
            << setw(10) << "Quantity" << std::right << setw(8) << "Price" << endl;

    f.seekg(0); //puntatore read all'inizio
    Item i;
    while (!f.eof()) {
        f.read (
            reinterpret_cast<char*>(&i), sizeof(Item)
        );
        outputLine(outFile,i);
    }

    outFile.close();
}

void outputLine (std::ostream& out, const Item& item) {
    out << std::left << setw(6) << item.getCode() << setw(16) << item.getName()
            << std::right << setw(10) << item.getQuantity()  << std::showpoint 
            << std::setprecision(3) << setw(8) << item.getPrice() << endl;
}

void updateItem(fstream& f) {
    //richiedi codice del prodotto
    int c;
    cout << "\nEnter item code: ";
    cin >> c;

    //leggi elemento che ha quel codice
    Item i;
    f.seekg(c*sizeof(Item));
    f.read (
        reinterpret_cast<char*>(&i),sizeof(Item)
    );

    //verifica che non sia vuoto
    if(i.getCode()!=-1) {
        update(i);
        cout << "\n\n";
        outputLine(cout,i);
    } else cout << "Item #" << c << " contains no information" << endl;
}

void update(Item& i) {
    cout << "\nEnter 1 to update quantity or 2 to update price: ";
    int choice;
    cin>>choice;


    switch (choice) {
        case 1:
            cout << "\nEnter new quantity: ";
            int x;
            cin >> x;
            i.setQuantity(x);
            break;
        case 2:
            cout << "\nEnter new price: ";
            double y;
            cin >> y;
            i.setPrice(y);
            break;
        default:
            cout << "\nInvalid choice" << endl;
    }
}

void addItem(fstream& f) {
    //richiedi codice del prodotto
    int c;
    cout << "\nEnter item code: ";
    cin >> c;

    //leggi elemento che ha quel codice
    Item i;
    f.seekg(c*sizeof(Item));
    f.read (
        reinterpret_cast<char*>(&i),sizeof(Item)
    );

    //verifica che sia vuoto
    if(i.getCode()==-1) {
        cout << "\nEnter item's name, quantity and price\n? ";
        std::string name; int quantity; double price;
        cin >> name >> quantity >> price;
        i.setCode(c); i.setName(name); i.setQuantity(quantity); i.setPrice(price);

        f.seekp(c*sizeof(Item));
        f.write (
            reinterpret_cast <const char*> (&i), sizeof(Item)
        );

        outputLine(cout,i);
    } else cout << "Item #" << c << " already contains information" << endl;
}

void deleteItem(fstream& f) {
    //richiedi codice del prodotto
    int c;
    cout << "\nEnter item code: ";
    cin >> c;

    //leggi elemento che ha quel codice
    Item i;
    f.seekg(c*sizeof(Item));
    f.read (
        reinterpret_cast<char*>(&i),sizeof(Item)
    );

    //verifica che sia vuoto
    if(i.getCode()!=-1) {
        Item blank;

        f.seekp(c*sizeof(Item));
        f.write (
            reinterpret_cast <const char*> (&blank), sizeof(Item)
        );

    } else cout << "Item #" << c << " already contains no information" << endl;
}