//Container.h
//interface for class Container

#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include "Box.h"
#include "LinkedList.h"
#include "Date.h"

class Container {
    public:
        //constructor
        Container (int = 0, const std::string& = "", 
            const std::string& = "", const LinkedList<Box>& = LinkedList<Box>());
        
        //set e get
        void setId(int);
        void setState(const std::string&);
        void setCarrier(const std::string&);
        void setBoxes(const LinkedList<Box>&); //set list of boxes and n_box
        
        int getId() const;
        const std::string& getState() const;
        const std::string& getCarrier() const;
        const LinkedList<Box>& getBoxes() const;
        int getNumberBoxes() const;
        const Date& calculateExpiry() const;
    private:
        int id_container;
        std::string state_orig;
        std::string id_carrier;
        LinkedList<Box> boxes;
        int n_box; //# of boxes in container
        Date expiry;
};

#endif