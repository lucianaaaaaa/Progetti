/*(Invoice class) Create a class called Invoice that a hardware store 
might use to represent an invoice for an item sold at the store. 
An Invoice should include six data members-a part number (type string),
a part description (type string), a quantity of the item being purchased (type int), 
a price per item (type int) a value-added tax (VAT) rate as a decimal (type double) 
and a discount rate as a decimal(type double). 
•Your class should have a constructor that initializes the six data members. 
•The constructor should initialize the first four data members with values from parameters 
and the last two data members to default values of 0.20 per cent and zero respectively. 
•Provide a set and a get functions for each data member. 
•In addition, provide a member function named getInvoiceAmount that calculates the invoice amount
(i.e., multiplies the quantity by the price per item and applies the tax and discount amounts), then returns the amount. 
•Have the set data members perform validity checks on their parameters—if a parameter value 
is not positive, it should be left unchanged. Write a driver program to demonstrate Invoice’s capabilities.*/

#include <iostream>
#include <string>

class Invoice {
    private:
        std::string partNumber;
        std::string partDescription;
        int quantity;
        int price;
        double vat;
        double discount;

    public:
        explicit Invoice (std::string num, std::string desc, int quant, int money);

        std::string getPartNumber();
        void setPartNumber (std::string num);

        std::string getPartDescription();
        void setPartDescription (std::string desc);

        int getQuantity ();
        void setQuantity (int quant);

        int getPrice ();
        void setPrice (int money);

        double getVat ();
        void setVat (double tax);
            
        double getDiscount ();
        void setDiscount (double disc);

        float getInvoiceAmount ();
};