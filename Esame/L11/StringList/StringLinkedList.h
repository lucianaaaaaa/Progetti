//StringLinkedList.h
#ifndef STRINGLL_H
#define STRINGLL_H

#include "StringNode.h"

class StringLinkedList {
    public:
    StringLinkedList(); //empty list constructor
    ~StringLinkedList(); // destructor
    bool empty() const; //is empty?
    const std::string& front() const; //read first element
    void addFront(const std::string& e); //add element to front
    void removeFront(); //remove front element 

    private:
    StringNode* head;
};

#endif