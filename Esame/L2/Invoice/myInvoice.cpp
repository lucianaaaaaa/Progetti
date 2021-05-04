#include <string>
#include "invoice.h"
using std::string;
using std::cout;
using std::endl;

Invoice::Invoice (std::string num, std::string desc, int quant, int money)
            : partNumber{num}, partDescription{desc}, vat{0.2}, discount{0} {

                //verifica che la quantità sia positiva
                if (quant>0)
                quantity = quant;
                else 
                cout << "la quantità che hai inserito e\' negativa" << endl;

                //verifica che il prezzo sia positivo
                if (money>0)
                price = money;
                else 
                cout << "il prezzo che hai inserito e\'  negativo" << endl;

            }

string Invoice::getPartNumber() {
    return partNumber;
}

void Invoice::setPartNumber (string num) {
    partNumber=num;
}

string Invoice::getPartDescription() {
    return partDescription;
}

void Invoice::setPartDescription (string desc) {
    partDescription=desc;
}

int Invoice::getPrice() {
    return price;
}

void Invoice::setPrice (int money) {
    if (money>0)
    price=money;
    else 
    cout << "il prezzo e\' negativo" << endl;
}

int Invoice::getQuantity() {
    return quantity;
}

void Invoice::setQuantity (int quant) {
    if (quant>0)
    quantity=quant;
    else 
    cout << "la quantita\' e\' negativa" << endl;

}

double Invoice::getVat() {
    return vat;
}

void Invoice::setVat (double tax) {
    if (tax>=0 && tax<1)
    vat=tax;
    else 
    cout << "la tassa non e\' valida" << endl;
}

double Invoice::getDiscount() {
    return discount;
}

void Invoice::setDiscount (double disc) {
    if (disc>=0 && disc<1)
    discount=disc;
    else 
    cout << "lo sconto non e\' valido" << endl;
}

float Invoice::getInvoiceAmount () {
    float invoiceAmount;
    invoiceAmount = price*quantity - price*quantity*discount + price*quantity*vat;
    return invoiceAmount;
}