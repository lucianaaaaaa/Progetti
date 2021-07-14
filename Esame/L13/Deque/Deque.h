//Deque.h
//double ended queue via doubly linked list

#include "DLinkedList.h"
#include <stdexcept>

template <typename T>
class Deque {
    public:
        Deque();
        int size() const;
        bool empty() const;
        const T& front();
        const T& back();
        void insertFront(const T& e);
        void insertBack(const T& e);
        void removeFront();
        void removeBack();         
    private:
        DLinkedList<T> dlist;
        int n;
};

template <typename T>
Deque<T>::Deque(): dlist(), n{0} {}

template <typename T>
int Deque<T>::size() const {return n;}

template <typename T>
bool Deque<T>::empty() const {return n==0;}
    
template <typename T>
const T& Deque<T>::front() {dlist.front();}

template <typename T>
const T& Deque<T>::back() {dlist.back();}

template <typename T>
void Deque<T>::insertFront(const T& e) {
    dlist.addFront(e);
    n++;
    }

template <typename T>
void Deque<T>::insertBack(const T& e) {
    dlist.addBack(e);
    n++;
    }

template <typename T>
void Deque<T>::removeFront() {
    if (empty()) throw std::runtime_error ("Deque is empty");
    dlist.removeFront();
    n--;
    }

template <typename T>
void Deque<T>::removeBack() {
    if (empty()) throw std::runtime_error ("Deque is empty");
    dlist.removeBack();
    n--;
    }