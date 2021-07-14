//BST.h
//binary search tree

#include "Node.h"
#include <iostream>
using std::cout;

template<typename K>
class BST {
    protected:
        Node<K> *root;
    public:
        BST(Node<K>*r = NULL): root(r) {}
        ~BST() {release(root);}

        //traverse
        void inorderTreeWalk(Node<K>* x);
        void inorderTreeWalk() {inorderTreeWalk(root);}
        void preorderTreeWalk(Node<K>* x);
        void preorderTreeWalk() {preorderTreeWalk(root);}

        Node<K>* getRoot() {return root;}
        Node<K>* search(K key);
        Node<K>* search(Node<K>* x, K key);
        Node<K>* minimum() {return minimum(root);}
        Node<K>* minimum(Node<K>* subroot);
        Node<K>* maximum () {return maximum(root);}
        Node<K>* maximum(Node<K>* subroot);
        Node<K>* predecessor(Node<K>* x);
        Node<K>* successor(Node<K>* x);

        Node<K>* insert(K key);
        void release(Node<K>* x);

};

template <typename K>
void BST<K>::inorderTreeWalk(Node<K>* x) {
    if (x) {
        inorderTreeWalk(x->left);
        cout << x->key << "\n";
        inorderTreeWalk(x->right);
    }
}

template <typename K>
void BST<K>::preorderTreeWalk(Node<K>* x) {
    if (x) {
        cout << x->key << "\n";
        preorderTreeWalk(x->left);
        preorderTreeWalk(x->right);
    }
}

template <typename K>
Node<K>* BST<K>::search(Node<K>* x, K key) {
    while (x) {
        if (x->key == key) break;
        else if (x->key<key) x = x->right;
        else x = x->left;
    }
    return x;
}

template <typename K>
Node<K>* BST<K>::search(K key) {
    return search (root,key);}

template <typename K>
Node<K>* BST<K>::minimum(Node<K>* subroot) {
    Node<K>* x = subroot;
    if(x) {
        while (x->left) x=x->left;
    }
    return x;
}

template <typename K>
Node<K>* BST<K>::maximum(Node<K>* subroot) {
    Node<K>* x = subroot;
    if(x) {
        while (x->right) x=x->right;
    }
    return x;
}

template <typename K>
Node<K>* BST<K>::predecessor(Node<K>* x) {
    Node<K>* prev = NULL;
    if (x->left) prev=maximum(x->left);
    else {
        prev = x->parent;
        while (prev && prev->left == x) {
            x=prev;
            prev = x->parent;
        }
    }
    return prev;
}

template <typename K>
Node<K>* BST<K>::successor(Node<K>* x) {
    Node<K>* succ = NULL;
    if (x->right) succ=minimum(x->right);
    else {
        succ = x->parent;
        while (succ && succ->right == x) {
            x=succ;
            succ = x->parent;
        }
    }
    return succ;
}

template <typename K>
Node<K>* BST<K>::insert(K key) {
    if (search(key)) return nullptr; //elemento già presente
    Node<K>* x = root; //figlio
    Node<K>* y = nullptr; //padre
    Node<K>* z = new Node<K>(key);

    while(x) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent= y;
    if (y==nullptr) return root;
    else {
        if(z->key < y->key) y->left=z;
        else y->right = z;
    }
    return z;
}

