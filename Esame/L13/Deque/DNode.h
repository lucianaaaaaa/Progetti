//DNode.h

template <typename T> 
class DLinkedList; //forward declaration to include it as a friend

template <typename T>
class DNode {
    private:
        T elem;
        DNode <T>* next;
        DNode <T>* prev; //ptr to previous node

        friend class DLinkedList<T>;
};