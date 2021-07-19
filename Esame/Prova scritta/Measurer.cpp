//Measurer.cpp
//member functions definitions for class Measurer

#include "Measurer.h"
#include <stdexcept>
using std::vector;

Measurer::Measurer(int id, int x, int y, const std::vector<Measurement>& v) {
    setId(id);
    setCoordX(x);
    setCoordY(y);
    for (int i=0; i<v.size(); i++) measurement_list.insertOrder(v[i]);
}

Measurer::~Measurer() {
    measurement_list.~DLinkedList<Measurement>();
} //explicitly destroys doubly linked list

Measurer::Measurer (const Measurer& m) {
    setId(m.id_station);
    setCoordX(m.coord_x);
    setCoordY(m.coord_y);
    measurement_list = m.measurement_list;
}

Measurer& Measurer::operator= (const Measurer& m) {

    setId(m.id_station);
    setCoordX(m.coord_x);
    setCoordY(m.coord_y);
    measurement_list = m.measurement_list;

    return *this;
}

void Measurer::setId(int id) {
    if (id<0) throw std::invalid_argument ("Station id cannot be negative");
    id_station=id;
}

void Measurer::setCoordX (int x) {
    if (x<-1||x>=20) throw std::invalid_argument ("Coord x must be between 0 and 19. Default value: -1");
    coord_x=x;
}

void Measurer::setCoordY (int y) {
    if (y<-1||y>=20) throw std::invalid_argument ("Coord y must be between 0 and 19. Default value: -1");
    coord_y=y;
}

void Measurer::setMeasurements (const std::vector<Measurement>& v) {
    for (int i=0; i<v.size(); i++) measurement_list.insertOrder(v[i]);
}

int Measurer::getId () const {return id_station;}
int Measurer::getCoordX () const {return coord_x;}
int Measurer::getCoordY () const {return coord_y;}
const DLinkedList<Measurement>& Measurer::getMeasurements () const {return measurement_list;}