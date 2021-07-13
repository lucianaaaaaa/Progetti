//emptyStock.cpp
//generates file hardware.dat that can stock up to 100 items

#include <fstream>
#include "Item.h"
#include <iostream>
using std::ofstream; using std::ios;

int main () {
    ofstream out {"hardware.dat",ios::out|ios::binary};
    if (!out) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    Item item; //generates blank item
    out.seekp(0);
    for (int i=0;i<100;i++) {
        out.write (
            reinterpret_cast <const char*> (&item), sizeof(Item)
        );
    }

    out.close();
}
