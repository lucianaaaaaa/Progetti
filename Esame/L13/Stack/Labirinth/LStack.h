//LStack.h
//Stack implemented with linked list

#ifndef LSTACK_H
#define LSTACK_H

#include "LinkedList.h"
#include <stdexcept>

template <typename E>
class LinkedStack {
    public:
        LinkedStack ();           //constructor
        int size() const;         //number of elements in stack
        bool empty() const;       //is empty?
        const E& top();           //get top element
        void push (const E& e);   //add element to top
        void pop();               //remove element from top
    private:
        LinkedList<E> S;
        int n;                    //element counter
};

//constructor
template<typename E>
LinkedStack<E>::LinkedStack()
    : S(), n{0} {}

//size
template <typename E>
int LinkedStack<E>::size() const {
    return n;
}

//empty
template <typename E>
bool LinkedStack<E>::empty() const {
    return n==0;
}

//top element
template <typename E>
const E& LinkedStack<E>::top() {
    if (empty())
        throw std::runtime_error("Top of empty stack");
    
    return S.front();
}

//push
template <typename E>
void LinkedStack<E>::push(const E& e) {
    ++n;
    S.addFront(e);
}

//pop
template <typename E>
void LinkedStack<E>::pop() {
    if (empty())
        throw std::runtime_error("Pop from empty stack");

    --n;
    S.removeFront();    
}
#endif