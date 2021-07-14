//Stack.h
//stack implemented via built-in array

#ifndef ASTACK_H
#define ASTACK_H

#include <stdexcept>

template <typename T>
class Stack {
    static int const DEFAULT_CAPACITY{10};
    public:
        Stack (int = DEFAULT_CAPACITY);
        int size() const;
        bool empty() const;
        const T& top() const;
        void push(const T& e);
        void pop();
    private:
        T* array; //built in array
        int capacity; //maximum capacity
        int t; //index of top element
};

template <typename T>
Stack<T>::Stack(int cap): 
    array{new T[cap]}, capacity{cap}, t{-1} {}

template <typename T>
int Stack<T>::size() const{
    return t+1;
}

template <typename T>
bool Stack<T>::empty() const {
    return t<0;
}

template <typename T>
const T& Stack<T>::top() const {
    if (empty()) throw std::runtime_error ("Empty stack");
    return array[t];
}

template <typename T>
void Stack<T>::push(const T& e) {
    if (t+1==capacity) throw std::runtime_error("Stack is full");
    t++;
    array[t]=e;
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) throw std::runtime_error ("Empty stack");
    t--;
}

#endif