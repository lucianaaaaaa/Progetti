//Container.h
//interface for class Container

#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include "Box.h"
#include "LinkedList.h"

class Container {
    public:
        //constructor
        Container (int = 0, const std::string& = "", 
            const std::string& = "", const LinkedList<Box>& = LinkedList<Box>());
        
        //set e get
        void setId(int);
        void setState(const std::string&);
        void setCarrier(const std::string&);
        void setBoxes(const LinkedList<Box>&);
        
    private:
        int id_container;
        std::string state_orig;
        std::string id_carrier;
        LinkedList<Box> boxes;
        int n_box; //# of boxes in container
};

#endif