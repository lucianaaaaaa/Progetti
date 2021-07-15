//CLinkedList.h
//circular linked list

#ifndef CLIST_H
#define CLIST_H

#include "CNode.h"
#include "Iterator.h"
#include <stdexcept>
#include <sstream>

template <typename T>
class CLinkedList {
    public:
        CLinkedList();
        ~CLinkedList();
        bool empty() const;
        const T& front() const; //after cursor
        const T& back() const; //at cursor
        void advance(); //move cursor
        void add(const T& e); //add after cursor 
        void remove(); //remove after cursor
        std::string toString();

        //iterators
        Iterator<T> begin(); //after cursor
        Iterator<T> end(); //at cursor
    private:
        CNode<T>* cursor;
};

template <typename T>
CLinkedList<T>::CLinkedList() {
    cursor = nullptr;
}

template <typename T>
CLinkedList<T>::~CLinkedList() {
    //remove all elements
    while (!empty()) remove();
}

template <typename T>
bool CLinkedList<T>::empty() const {
    return cursor==nullptr;
}

template <typename T>
const T& CLinkedList<T>::front() const{
    return cursor->next->elem;
}

template <typename T>
const T& CLinkedList<T>::back() const{
    return cursor->elem;
}

template <typename T>
void CLinkedList<T>::advance() {
    cursor=cursor->next;
}

template <typename T>
void CLinkedList<T>::add(const T& e) {
    CNode<T>*v = new CNode<T>;
    v->elem=e;
    if (empty()) {
        v->next=v;
        cursor=v;
    }
    else {
    v->next = cursor->next;
    cursor->next=v; }
}

template <typename T>
void CLinkedList<T>::remove() {
    if (empty()) throw std::runtime_error("List is empty");
    CNode<T>* v = cursor->next;
    if (cursor==v) cursor==nullptr;
    else cursor->next=v->next;
    delete v;
}

template <typename T>
std::string CLinkedList<T>::toString() {
    std::ostringstream out;

    if (empty()) out << "List is empty";
    else {
    CNode<T>* v = cursor;
    
    out << "Cursor --> ";
    out << v->elem << " --> ";
    v=v->next;
    while (v!=cursor) {
        out << v->elem << " --> ";
        v=v->next;
    }
    out << "Cursor";

    }
    return out.str();
}

template <typename T>
Iterator<T> CLinkedList<T>::begin() {
    return Iterator<T>(cursor->next);
}

template <typename T>
Iterator<T> CLinkedList<T>::end() {
    return Iterator<T>(cursor);
}

#endif
