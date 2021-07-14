//Iterator.h
//interface of iterator for class List

#include "Node.h"

template <typename T>
class List;

template <typename T>
class Iterator {
    public:
        friend class List<T>;
        
        T& operator*(); //reference to the element
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++ ();
        Iterator& operator-- ();
    private:
        Node<T>* v;
        Iterator(Node<T>* u) {v=u;}
};

template <typename T>
T& Iterator<T>::operator*() {
    return v->elem;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& p) const {
    return v==p.v;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& p) const {
    return v!=p.v;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    v = v->next;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--() {
    v = v->prev;
    return *this;
}
