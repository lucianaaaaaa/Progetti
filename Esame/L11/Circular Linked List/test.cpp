#include <iostream>
#include "CLinkedList.h"
using std::string; using std::cout; using std::endl;

int main () {
    CLinkedList<string> playList;
    playList.add("Autumn leaves");
    playList.add("Mo' Better Blues");
    playList.add("Waltz for Debbie");
    playList.add("So What");
    playList.advance();
    playList.advance(); //print should start from Waltz
    cout << playList.toString() << endl;
    playList.remove();
    playList.add("Caravan");
    cout << playList.toString() << endl;
    return 0;
}