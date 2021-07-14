//List.h
//list with iterator

#include "Iterator.h"
#include "Node.h"

template <typename T>
class List {
    public:
        List();
        bool empty() const;
        int size() const;
        void addFront(const T& e);
        void addBack (const T& e);
        void removeFront();
        void removeBack();
        Iterator<T> begin(); //beginning position
        Iterator<T> end(); //just beyond last position
        void insert (const Iterator<T>& p, const T& e); //insert e before p
        void erase (const Iterator<T>& p); //remove p
    private:
        int n; //number of nodes
        Node<T>* header;
        Node<T>* trailer;
};

template <typename T>
List<T>::List()
    : n{0}, header{new Node<T>}, trailer{new Node<T>} {
        header->next=trailer;
        trailer->prev=header;
    }

template <typename T>
bool List<T>::empty() const {return header->next==trailer;}

template <typename T>
int List<T>::size() const {return n;}

template <typename T>
Iterator<T> List<T>::begin() {
    return Iterator(header->next);
}

template <typename T>
Iterator<T> List<T>::end() {
    return Iterator(trailer); //end is beyond last element
}

template <typename T>
void List<T>::insert(const Iterator<T>& p, const T& e) {
    Node<T>* v = new Node<T>;
    Node<T>* w = p.v; 
    Node<T>* u = w->prev;
    v->elem=e;
    u->next = v;
    v->prev = u; v->next=w;
    w->prev = v;
    n++;
}

template <typename T>
void List<T>::addFront(const T& e) {
    insert(begin(), e);
}

template <typename T>
void List<T>::addBack(const T& e) {
    insert(end(),e);
}

template <typename T>
void List<T>::erase(const Iterator<T>& p) {
    Node<T>* w = p->next; 
    Node<T>* u = p->prev;
    u->next=w;
    w->prev=u;
    delete p.v;
    n--;
}

template <typename T>
void List<T>::removeFront() {
    erase(begin());
}

template <typename T>
void List<T>::removeBack() {
    erase(--end());
}