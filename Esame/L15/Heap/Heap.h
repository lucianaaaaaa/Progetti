//heap.h
//template struttura dati heap

#ifndef HEAP_H
#define HEAP_H

#include <array>
#include <stdexcept>
#include <utility>

template <typename T>
class Heap {
    public:
    Heap (): n{0} {for (int i=0; i<10; i++) A[i]=0;} //costruttore heap vuoto
    bool empty () const {return n==0;}
    T top() const {return A[1];}
    int size () {return n;}
    void insert(const T& elem);
    void extract_max();

    private:
    std::array <T,10> A;
    int n;
    void Heapify(int index);
    void BuildHeap();
};

template <typename T>
void Heap<T>::Heapify(int index) {
    int left{2*index};
    int right{2*index +1};
    int largest{index};
    if (left<=n && A[left]>A[largest]) largest = left;
    if (right<=n && A[right]>A[largest]) largest = right;
    if (largest!=index)
    {   std::swap(A[index],A[largest]);
        Heapify(largest);}
}

template <typename T>
void Heap<T>::BuildHeap() {
    for (int i = n/2; i>=1; i++) 
    Heapify(i);
}

template <typename T>
void Heap<T>::insert(const T& elem) {
    n++;
    int i = n;
    while (i>1 && A[i/2]<elem) {
        A[i] = A [i/2];
        i /= 2;
    }
    A[i]=elem;
}

template <typename T>
void Heap<T>::extract_max() {
    if (n<1) throw std::runtime_error("Heap underflow");
    A[1] = A[n];
    n--;
    Heapify(1);
}


#endif