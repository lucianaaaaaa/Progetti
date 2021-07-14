//Node.h
//BST node

template <typename K> class BST;

template <typename K> 
class Node {
    public:
    friend class BST<K>;
        Node(K k, Node<K> *p = nullptr, Node<K>*l = nullptr, Node<K>*r = nullptr)
            : key(k), left(l), right(r), parent(p) {}
    private:
        K key;
        Node<K>* left; 
        Node<K>* right; 
        Node<K>* parent; 
};