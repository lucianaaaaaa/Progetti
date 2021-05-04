//target heart rate - test program
#include <iostream>
#include "HeartRates.h"
#include "Date.h"
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main () {
    string name, surname;
    int day,month,year;
    cout << "***TARGET HEART RATE CALCULATOR***" << endl;

    //inserimento dati
    cout << "Insert first name: ";
    cin >> name;
    cout << "\nInsert surname: ";
    cin >> surname;
    cout << "\nInsert date of birth: ";
    cin >> day; 
    cout << "/";
    cin >> month;
    cout << "/";
    cin >> year;

    Date birth(day,month,year);
    HeartRates client(name,surname,birth);

    //display age
    cout << "Your age: " << client.getAge() <<endl;
    
    //display maximum heart rate
    cout << "Maximum heart rate: " << client.maximumHeartRate() << "bpm" << endl;

    //display target heart rate
    client.targetHeartRate();
}