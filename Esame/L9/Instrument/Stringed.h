//Stringed.h
//derived from Instrument
#include "Instrument.h"

#ifndef STRINGED_H
#define STRINGED_H

class Stringed: public Instrument {
    public:
        void play(note) const {
            cout << "Stringed::play" << endl;
        }
};

#endif