//Item.h
//class for stock items

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
    public:
        Item (int=-1,const std::string& ="", int=0, double=0); //constructor

        void setCode (int);
        void setName (const std::string&);
        void setQuantity (int);
        void setPrice (double);

        int getCode () const;
        std::string getName () const;
        int getQuantity () const;
        double getPrice () const;
    private:
        int code;
        char name[15];
        int quantity;
        double price;
};

#endif