//StringNode.h
//node in list of strings
#ifndef STRINGNODE_H
#define STRINGNODE_H

#include <string>

class StringNode {
    private:
    std::string elem; //element value
    StringNode* next; //ptr to next item in the list

    friend class StringLinkedList; //linked list class
};

#endif