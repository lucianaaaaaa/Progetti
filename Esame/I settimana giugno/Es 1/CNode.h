//CNode.h

#ifndef CNODE_H
#define CNODE_H

template <typename T>
class CLinkedList;

template <typename T>
class CNode {
    private:
        T elem;
        CNode* next;

        friend class CLinkedList<T>;
};

#endif