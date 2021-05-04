//StringLinkedList.cpp
#include "StringLinkedList.h"
#include <stdexcept> 

StringLinkedList::StringLinkedList (): head(nullptr) {}

StringLinkedList::~StringLinkedList () {
    while (!empty()) removeFront();
}

bool StringLinkedList::empty() const{
    return (head==nullptr);
}

const std::string& StringLinkedList::front() const {
    return head->elem;
}

void StringLinkedList::addFront(const std::string& e) {
    StringNode* n = new StringNode;
    //prima definisco i dati membro del nuovo nodo
    n->elem = e;
    n->next = head;
    //poi head = puntatore al nuovo primo nodo
    head = n;
}

void StringLinkedList::removeFront() {
    if (empty())
    throw std::runtime_error {"List is empty"};
    
    StringNode* old = head;
    delete [] old; //cancella area di memoria del vecchio ptr

    head = head->next;

}