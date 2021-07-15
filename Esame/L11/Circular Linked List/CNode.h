//CNode.h

#ifndef CNODE_H
#define CNODE_H

template <typename T>
class CLinkedList;

template <typename T>
class Iterator;

template <typename T>
class CNode {
    public:
        friend class CLinkedList<T>;
        friend class Iterator<T>;
    private:
        T elem;
        CNode* next;
};

#endif