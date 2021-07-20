#include "Container.h"
#include <stdexcept>

using std::string;

Container::Container(int id, const string& state, const string& carrier, const LinkedList<Box>& list)
    : state_orig{state}, id_carrier{carrier}, boxes{list}, n_box{list.size()} {
        setId(id);
        expiry=calculateExpiry();
    }

void Container::setId(int id) {
    if(id<0) throw std::invalid_argument("Container id must be a positive integer");
    id_container=id;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}

void Container::setState(const string& state) {
    state_orig=state;
}

void Container::setCarrier(const string& carrier) {
    id_carrier=carrier;
}

void Container::setBoxes(const LinkedList<Box>& list) {
    boxes = list;
    n_box = list.size();
}

int Container::getId() const {return id_container;}
const std::string& Container::getState() const {return state_orig;}
const std::string& Container::getCarrier() const {return id_carrier;}
const LinkedList<Box>& Container::getBoxes() const {return boxes;}
int Container::getNumberBoxes() const {return n_box;}

const Date& Container::calculateExpiry() const {
    Date myDate; int ctr{0};
    for (int i=0; i<n_box; i++) {
        if (boxes[i].isPerishable()) {
            if (ctr==0) {myDate=boxes[i].getDate(); ctr++;}
            else if (boxes[i].getDate()<myDate) myDate=boxes[i].getDate();
        } 
    }
    if (ctr==0) myDate.setDate(31,12,2121);
    return myDate;
}
