//Iterator.h
//iterator for circular linked list

#ifndef ITERATOR_H
#define ITERATOR_H

#include "CNode.h"

template <typename t>
class CLinkedList;

template <typename T>
class Iterator {
    public:
        friend class CLinkedList<T>;

        T& operator*(); //reference
        bool operator== (const Iterator& p) const;
        bool operator!= (const Iterator& p) const;
        Iterator& operator++ ();
        Iterator& operator-- ();
        Iterator& operator= (const Iterator& p);
    private:
        CNode<T>* v;
        Iterator(CNode<T>* u) {v=u;}
};

template <typename T>
T& Iterator<T>::operator*() {return v->elem;}

template <typename T>
bool Iterator<T>::operator==(const Iterator& p) const {
    return v==p.v;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& p) const {
    return v!=p.v;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    v=v->next;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--() {
    v=v->prev;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& p) {
    v=p.v;
    return *this;
}

#endif