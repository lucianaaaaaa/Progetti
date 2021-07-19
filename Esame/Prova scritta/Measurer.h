//Measurer.h
//user interface for class Measurer

#ifndef MEASURER_H
#define MEASURER_H

#include "DLinkedList.h"
#include "Measurement.h"
#include <vector>

class Measurer {
    public:
        //costruttore
        //non ho operatore di assegnazione per liste: uso vettore in ingresso
        Measurer(int = 0, int= -1, int = -1,const std::vector<Measurement>& = std::vector<Measurement>());

        ~Measurer(); //distruttore
        Measurer (const Measurer&); //costruttore copia
        Measurer& operator= (const Measurer&); //operatore di assegnazione

        //set e get
        void setId(int);
        void setCoordX(int);
        void setCoordY(int);
        void setMeasurements(const std::vector<Measurement>&);

        int getId () const;
        int getCoordX () const;
        int getCoordY () const;
        const DLinkedList<Measurement>& getMeasurements () const;

    private:
        int id_station;
        int coord_x;
        int coord_y;
        DLinkedList<Measurement> measurement_list;
};

#endif