//Node.h
//Node in list

template <typename T>
class List;

template <typename T>
class Node {
    public:
        friend class List<T>;
    private:
        T elem; //element in node
        Node* prev; //previous node
        Node* next; //next node
};