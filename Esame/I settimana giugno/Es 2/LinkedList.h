//LinkedList.h
//generic linked list


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

template <typename NODETYPE>
class LinkedList {
    public:
        LinkedList();                       //constructor
        ~LinkedList();                      //destructor
        bool empty() const;                 //is list empty?
        const NODETYPE& front() const;      //get front element
        void addFront(const NODETYPE& e);   //add to front of list
        void removeFront();                 //remove from front of list
        int size() const;                   //number of elements in list
        NODETYPE& operator[](int i) const;   //returns i-th element (i=0:front)

        LinkedList(const LinkedList<NODETYPE>& list); //copy constructor
        LinkedList& operator=(const LinkedList<NODETYPE>& list); //assignment operator
    private:
        Node<NODETYPE>* head;
};

//Implementation

//constructor
template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList()
    : head (nullptr) {}

//destructor
template <typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList() {
    while (!empty()) removeFront();
    delete[] head;
}

//is list empty?
template <typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const {
    return (head==nullptr);
}

//get front element
template <typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const {
    return head->elem;
}

//add element to front of list
template <typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& e) {
    Node<NODETYPE>*v = new Node<NODETYPE>;
    v->elem = e;
    v->next = head;
    head = v; 
}

//remove element from front
template <typename NODETYPE>
void LinkedList<NODETYPE>::removeFront() {
    if (head==nullptr) {
        throw std::invalid_argument {"List is empty"};
    }

    Node <NODETYPE>* old = head;
    head = old->next;
    delete [] old;
}

template <typename NODETYPE>
int LinkedList<NODETYPE>::size() const {
    if (empty()) return 0;
    //else
    Node<NODETYPE>* v=head;
    int i=0;
    while (v) {
        v=v->next;
        i++;
    }
    delete[] v;
    return i;
}

template <typename NODETYPE>
NODETYPE& LinkedList<NODETYPE>::operator[] (int i) const{
    if (i>=size()) throw std::invalid_argument("Index argument out of boundaries");
    Node<NODETYPE>* v = head;
    for (int j=0; j<i; j++) {
        v=v->next;
    }
    
    return v->elem;
}


template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList(const LinkedList<NODETYPE>& list) 
    : head{nullptr} {
    NODETYPE elem;
    for (int i=(list.size()-1); i>=0; i--) {
        elem = list[i];
        addFront(elem);
    }
}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::operator=(const LinkedList<NODETYPE>& list) {
    //delete previous nodes
    while (!empty()) removeFront();

    //build new list
    NODETYPE elem;
    for (int i=(list.size()-1); i>=0; i--) {
        elem = list[i];
        addFront(elem);
    }
    return *this;
}

#endif