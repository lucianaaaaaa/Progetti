//BoxPlus.h
//nella lista giacenza, il pacco dev'essere memorizzato insieme al numero del container

#ifndef BOXP_H
#define BOXP_H

#include "Box.h"

class BoxPlus {
    public:
        BoxPlus (Box b = Box(), int id = 0): box{b}, container_id{id} {}

        void setBox(const Box& b) {box=b;}
        void setBox(int id) {container_id = id;}
        const Box& getBox () const {return box;}
        int getId() const {return container_id;}
    private:
        Box box;
        int container_id;
};

#endif