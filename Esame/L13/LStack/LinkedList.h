//LinkedList.h
//generic linked list

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