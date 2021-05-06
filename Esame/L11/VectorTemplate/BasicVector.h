//BasicVector.h
//basic vector class using template

template <typename T> 
class BasicVector {
public:
    BasicVector(int capac = 10);
    T& operator [] (int i) {
        return a[i];
    }

    private:
    T* a; //built-in array
    int capacity; //length of array
};

#include "BasicVector.cpp"