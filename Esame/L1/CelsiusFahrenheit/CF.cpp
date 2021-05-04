//celsius to fahrenheit conversion
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;

int main() {
    //scelta della conversione
    cout << "***CONVERTITORE DA CELSIUS A FAHRENHEIT E VICEVERSA***" << std::endl;
    cout << "Conversione da Celsius a Fahrenheit: inserire C" << std::endl 
        << "Conversione da Fahrenheit a Celsius: inserire F" << std::endl;
    char letter;
    double tempF,tempc;
    
    do {
    cin >> letter;
    cout << "Inserire la temperatura: \n";

    switch (letter) {
        case 'F': 
        cin >> tempF;
        tempc = (tempF-32)*5/9;
        break;
        case 'C':
        cin >> tempc;
        tempF = tempc*9/5 + 32; 
        break;
        default:
        cout << "Invalid entry" << std::endl;
        //finché non si digita F o C continua a chiedere input
    }
    } while (letter!='F' && letter!='C');

    //stampa risposta
    cout << "Conversione effettuata: " << std::setprecision(3) << tempc << "C = " 
        <<std::setprecision(3)<< tempF << "F" << std::endl;

}