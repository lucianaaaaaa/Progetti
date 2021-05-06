//BasicVector.cpp
//Implementation of BasicVector class

template <typename T> 
BasicVector<T>::BasicVector(int capac) {
    capacity = capac;
    a = new T[capacity]; //allocate array storage
}