//Box.h
//interface for class Box

#ifndef BOX_H
#define BOX_H

class Box {
    public:
        //constructor
        Box(int = 0, double = 0.0, double = 0.0, bool = false);

        //set & get
        void setId (int);
        void setWeight (double);
        void setValue (double);
        void setPerishable (bool);

        int getId() const;
        double getWeight() const;
        double getValue() const;
        bool isPerishable() const;
    private:
        int box_id;
        double value;
        double weight;
        bool perishable;
};

#endif