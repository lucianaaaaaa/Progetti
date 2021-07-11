//Wind.h
//derived from Instrument
#include "Instrument.h"

#ifndef WIND_H
#define WIND_H

class Wind: public Instrument {
    public:
        void play(note) const {
            cout << "Wind::play" << endl;
        }
};

#endif