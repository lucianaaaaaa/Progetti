//DLinkedList.h
//Doubly Linked List

#include "DNode.h"
#include <iostream>
#include <sstream>

template <typename T>
class DLinkedList {
    public:
        DLinkedList();
        ~DLinkedList();

        DLinkedList (const DLinkedList<T>& list);
        DLinkedList& operator=(const DLinkedList<T>& list);

        bool empty() const;
        int size() const;
        const T& front() const;
        const T& back() const;
        void addFront(const T& e);
        void addBack (const T& e);
        void removeFront();
        void removeBack();
        std::string toString() const; //prints list

        const T& operator[] (int i) const;

        void insertOrder(const T& e); //insert element e in order
    private:
        DNode<T>* header; //ptr to front of list
        DNode<T>* trailer; //ptr to end of list
    protected:
        void add(DNode<T>*v, const T& e);   //insert node before v
        void remove (DNode<T>*v);           //remove node v
};

//implementation
template<typename T> 
DLinkedList<T>::DLinkedList () {
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
int DLinkedList<T>::size() const {
    DNode<T>* v = header->next;
    int i = 0;
    while (v!=trailer) {
        i++;
        v = v->next;
    } 
    return i;
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
}

template <typename T>
void DLinkedList<T>::remove(DNode<T>*v) {
    if (empty()) throw std::runtime_error ("The list is empty");
    DNode<T>* u = v->prev;
    DNode<T>* w = v->next;
    u->next= w;
    w->prev= u;
    delete v;
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

template <typename T>
std::string DLinkedList<T>::toString() const{
    std::ostringstream out;
    DNode<T>* v = header->next;
    
    while (v!=trailer->prev) {
        out << v->elem << " , ";
        v=v->next;
    }
    out << v->elem;
    return out.str();
}

template<typename T>
void DLinkedList<T>::insertOrder(const T& e) {
    DNode<T>* v = header->next;
    while (v!=trailer) {
        if(e<v->elem) break;
        v=v->next;
    }
    add(v,e);

    }


//copy constructor
template <typename T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& list)
    : header{new DNode<T>}, trailer {new DNode<T>} {
        header->next = trailer;
        header->prev = nullptr;
        trailer->prev = header;
        trailer->next = nullptr;

        T elem;
        for (int i=0; i<list.size(); i++) {
            elem = list[i];
            addBack(elem);
        }

}

template <typename T>
const T& DLinkedList<T>::operator[] (int i) const{
    if (i>=size()) throw std::invalid_argument("Index argument out of boundaries");
    DNode<T>* v = header->next;
    for (int j=0; j<i; j++) {
        v=v->next;
    }
    
    return v->elem;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& list) {
    while (!empty()) removeFront(); //destroy previous nodes

    //add new nodes
    T elem;
        for (int i=0; i<list.size(); i++) {
            elem = list[i];
            addBack(elem);
        }
}