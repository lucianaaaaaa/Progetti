//Brass.h
//derived from Instrument
#include "Instrument.h"

#ifndef BRASS_H
#define BRASS_H

class Brass: public Instrument {
    public:
        void play(note) const {
            cout << "Brass::play" << endl;
        }
};

#endif