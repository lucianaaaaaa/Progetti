#include <vector>
#include <iostream>
#include "Instrument.h"
#include "Brass.h"
#include "Stringed.h"
#include "Wind.h"
using std::cout; using std::endl;
using std::vector;

void tune(Instrument& i) {
    i.play(note::middleC);
}

int main () {
    vector <Instrument*> v;
    Wind flute;
    Stringed violin;
    Brass flugelhorn;
    Instrument piano;

    v.push_back(&flute);
    v.push_back(&violin);
    v.push_back(&flugelhorn);
    v.push_back(&piano);
    
    cout << "Let's gig together \n\n";
    for (Instrument* i:v) tune(*i);
}