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
        int size() const;                   //number of elements in list
        NODETYPE operator[](int i);   //returns i-th element (i=0:front)

    private:
        Node<NODETYPE>* head;
        int n; //number of elements
};

//Implementation

//constructor
template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList()
    : head (nullptr), n{0} {}

//destructor
template <typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList() {
    while (!empty()) removeFront();
    n=0;
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

    n++;
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

    n--;
}

template <typename NODETYPE>
int LinkedList<NODETYPE>::size() const {return n;}

template <typename NODETYPE>
NODETYPE LinkedList<NODETYPE>::operator[] (int i) {
    LinkedList <NODETYPE> second;
    for (int j=0; j<i; j++) {//leggi, salva e rimuovi
    second.addFront(front());
    removeFront();
    }

    NODETYPE node = front(); //i-th element

    for (int j=0; j<i; j++) {
        addFront(second.front());
        second.removeFront();
    }

    second.~LinkedList();
    return node;
}