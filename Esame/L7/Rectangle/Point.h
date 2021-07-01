//Point.h
//class Point interface
//define a point using 2D coordinates

#ifndef POINT_H
#define POINT_H

class Point { 
    public:
        explicit Point (double =0.0, double =0.0); //constructor

        void setX (double x);
        void setY (double y);
        double getX () const;
        double getY () const;
    
    private:
        double x;
        double y;
};

#endif