//HeapSort.cpp
#include <vector>
#include <utility>
#include <iostream>

template <typename T>
void heapSort (std::vector<T>& A);

template <typename T>
void BuildHeap(std::vector<T>& A, int n);

template <typename T>
void Heapify(std::vector<T>& A, int index, int n);


int main () {
    std::vector<int> v {12,3,7,5,17,12,63,400,9,2,4};
    heapSort(v);
    for (int i=0; i<v.size(); i++) std::cout << v[i] << "\t";
}

template <typename T>
void BuildHeap(std::vector<T>& A,int n) {
    for (int i = n/2; i>=1; i--) 
    Heapify(A,i,n);
    //partendo dal genitore con indice più basso (n/2)
    //ripeti heapify fino al primo elemento
}

template <typename T>
void Heapify(std::vector<T>& A, int index, int n) {
    //si assume che entrambi i sottoalberi siano heap

    int left{2*index}; //figlio sx
    int right{2*index +1}; //figlio dx

    int largest{index}; //assumo che il genitore sia maggiore

    //se il figlio sx esiste, verificare se è maggiore del genitore
    if (left<n && A[left]>A[largest]) largest = left;

    //se il figlio dx esiste, verificare se è maggiore del genitore
    if (right<n && A[right]>A[largest]) largest = right;

    if (largest!=index)
    {   std::swap(A[index],A[largest]);
        Heapify(A,largest,n); //rendi heap il sottoalbero in questione
        }
}

template <typename T>
void heapSort (std::vector<T>& A) {
    //inserisco 0 all'inizio, in modo che la numerazione parta da 1
    A.insert(A.begin(),0); 

    int n = A.size()-1;
    //rendo il vettore un heap
    BuildHeap(A,n);
    
    for (int i=n; i>=2; i--) {
        std::swap (A[i],A[1]); //metto il max alla fine
        Heapify(A,1,i-1); //rendo heap il resto del vettore
    }

    //rimuovo lo 0 all'inizio
    A.erase(A.begin());
}