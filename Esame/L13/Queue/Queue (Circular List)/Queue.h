//Queue.h
//implementation via circularly linked list

#include <stdexcept>
#include "CLinkedList.h"

template <typename T>
class Queue {
    public:
        Queue();
        int size() const;
        bool empty() const;
        const T& front();
        void enqueue(const T&);
        void dequeue();
    private:
        CLinkedList<T> list; //circular linked list
        int n;
};

template <typename T>
Queue<T>::Queue(): list(), n{0};

template <typename T>
int Queue<T>::size() const {return n;}

template <typename T>
bool Queue<T>::empty() const {return n==0;}

template <typename T>
const T& Queue<T>::front() {
    if (empty()) throw std::runtime_error ("Empty queue");
    list.front();
}

template <typename T>
void Queue<T>::enqueue(const T& e) {
    list.add(e);
    list.advance();
    n++;
}

template <typename T>
void Queue<T>::dequeue() {
    if (empty()) throw std::runtime_error ("Empty queue");
    list.remove();
    n--;
}