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


 {  Iterator<string> p(playList.end());
    cout << *p << endl;
    }
    cout << playList.back() << endl;

    for (Iterator<string> p(playList.begin()); p!=playList.end(); ++p)
        cout << *p << "\t";
    cout << playList.back() << endl;


    CLinkedList<string> list2=playList;
    cout << "\n" << list2.toString() << "\n";
    cout << "\n" << playList.toString() << "\n";
    list2.remove();
    cout << "\n" << list2.toString() << "\n";
    cout << "\n" << playList.toString() << "\n";
    return 0;
}