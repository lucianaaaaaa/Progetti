//Box.h
//interface for class Box

#ifndef BOX_H
#define BOX_H

#include "Date.h"

class Box {
    public:
        //constructor
        Box(int = 0, double = 0.0, double = 0.0, bool = false,const Date& d = Date(31,12,2121));

        //set & get
        void setId (int);
        void setWeight (double);
        void setValue (double);
        void setPerishable (bool);
        void setDate (const Date&);

        int getId() const;
        double getWeight() const;
        double getValue() const;
        bool isPerishable() const;
        const Date& getDate() const;
    private:
        int box_id;
        double value;
        double weight;
        bool perishable;
        Date expiry;
};

#endif