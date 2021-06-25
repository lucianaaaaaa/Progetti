//heap.h
//template struttura dati heap

#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <typename T>
class Heap {
    public:
    Heap (): n{0}; //costruttore heap vuoto
    bool empty () {return A.size()==0;}
    int size () {return A.size();}
    T top() {return A[1];} //return max value
    void push() {
        
    }

    private:
    std::vector <T> A;
};
#endif