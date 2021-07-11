//Instrument.h
#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <iostream>
using std::cout; using std::endl;

enum note {middleC, Csharp, Eflat};

class Instrument {
    public:
        virtual void play(note) const {
            cout << "Instrument::play" << endl;
        }
};

#endif