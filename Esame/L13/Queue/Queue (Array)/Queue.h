//Queue.h
//implementation via array

#include <stdexcept>

template <typename T>
class Queue {
        static int const DEFAULT_CAP {10};
    public:
        Queue (int=DEFAULT_CAP);
        int size() const;
        bool empty() const;
        bool full() const;
        void enqueue(const T& e); //accoda nuovo elemento
        void dequeue(); //rimuovi elemento dalla testa
        const T& front() const; //elemento in testa
    private:
        T* array;
        int n; //dimensione array
        int head; //indice primo elemento inserito
        int tail; //indice prossimo elemento da inserire

        void helpIncrement(int index); //utility function to increment head/tail
};

template <typename T>
Queue<T>::Queue(int cap): 
    array{new T[cap]}, n{cap}, head{0}, tail{0} {}

template <typename T>
int Queue<T>::size() const {return tail-head;}

template <typename T>
bool Queue<T>::empty() const {return head==tail;}

template <typename T>
void Queue<T>::helpIncrement (int index) {
    if (index!=(n-1)) index++;
    else index = 0;
}

template <typename T>
bool Queue<T>::full() const{
    int x=head;
    helpIncrement(x);
    return x==tail;
}

template <typename T>
void Queue<T>::enqueue(const T& e) {
    if (full()) throw std::runtime_error ("Full queue");
    array[tail]=e;
    helpIncrement(tail);
}

template <typename T>
void Queue<T>::dequeue() {
    if (empty()) throw std::runtime_error ("Empty queue");
    helpIncrement(head);
}

template <typename T>
const T& Queue<T>::front() const {
    if (empty()) throw std::runtime_error ("Empty queue");
    return array[head];
}

