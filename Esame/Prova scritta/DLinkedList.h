//DLinkedList.h
//Doubly Linked List

#ifndef DLIST_H
#define DLIST_H

#include "DNode.h"
#include <iostream>
#include <sstream>

template <typename T>
class DLinkedList {
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const T& front() const;
        const T& back() const;
        void addFront(const T& e);
        void addBack (const T& e);
        void removeFront();
        void removeBack();
        int size() const {return n;}
        
        //const T& DLinkedList<T>::operator[] (int i); genera errore di compilazione

        void insertOrder(const T& e); //insert element e in order

    private:
        DNode<T>* header; //ptr to front of list
        DNode<T>* trailer; //ptr to end of list
        int n; //number of elements
    protected:
        void add(DNode<T>*v, const T& e);   //insert node before v
        void remove (DNode<T>*v);           //remove node v
};

//implementation
template<typename T> 
DLinkedList<T>::DLinkedList () {
    n=0;
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    header->prev = nullptr;
    trailer->prev = header;
    trailer->next = nullptr;
}

template <typename T>
DLinkedList<T>::~DLinkedList() {
    while (!empty()) removeFront();
    delete[] header;
    delete[] trailer;
}

template <typename T>
bool DLinkedList<T>::empty() const {
    return (header->next==trailer);
}

template <typename T>
const T& DLinkedList<T>::front() const {
    if (empty()) throw std::runtime_error ("The list is empty");
    return header->next->elem;
}

template <typename T>
const T& DLinkedList<T>::back() const {
    if (empty()) throw std::runtime_error ("The list is empty");
    return trailer->prev->elem;
}

template <typename T>
void DLinkedList<T>::add(DNode<T>*v, const T& e) { //add node before v
    DNode<T>*u = new DNode<T>;
    u->prev=v->prev;
    v->prev->next=u;
    v->prev=u;
    u->next=v;
    u->elem=e;
    n++;
}

template <typename T>
void DLinkedList<T>::remove(DNode<T>*v) {
    if (empty()) throw std::runtime_error ("The list is empty");
    DNode<T>* u = v->prev;
    DNode<T>* w = v->next;
    u->next= w;
    w->prev= u;
    delete v;
    n--;
}

template <typename T>
void DLinkedList<T>::addFront(const T& e) {
    add(header->next,e);
}

template <typename T>
void DLinkedList<T>::addBack(const T& e) {
    add(trailer,e);
}

template <typename T>
void DLinkedList<T>::removeFront() {
    remove(header->next);
}

template <typename T>
void DLinkedList<T>::removeBack() {
    remove(trailer->prev);
}

/*
template <typename T>
const T& DLinkedList<T>::operator[] (int i){
    if (i>=size()) throw std::invalid_argument("Index argument out of boundaries");
    DNode<T>* v = header->next;
    for (int j=0; j<i; j++) {
        v=v->next;
    }
    
    return v->elem;
} */

template<typename T>
void DLinkedList<T>::insertOrder(const T& e) {
    DNode<T>* v = header->next;
    while (v!=trailer) {
        if(e<v->elem) break;
        v=v->next;
    }
    add(v,e);
    }


#endif