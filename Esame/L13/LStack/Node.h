//Node.h

template <typename NODETYPE> 
class LinkedList; //forward declaration to include it as a friend

template <typename NODETYPE>
class Node {
    private:
        NODETYPE elem;
        Node <NODETYPE>* next;

        friend class LinkedList<NODETYPE>;
};