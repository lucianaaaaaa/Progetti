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
    std::vector<int> v {12,3,7,5,63,9,2};
    heapSort(v);
    for (int i=0; i<v.size(); i++) std::cout << v[i] << "\t";
}

template <typename T>
void BuildHeap(std::vector<T>& A,int n) {
    for (int i = n/2; i>=1; i--) 
    Heapify(A,i,n);
}

template <typename T>
void Heapify(std::vector<T>& A, int index, int n) {
    int left{2*index};
    int right{2*index +1};
    int largest{index};
    if (left<n && A[left]>A[largest]) largest = left;
    if (right<n && A[right]>A[largest]) largest = right;
    if (largest!=index)
    {   std::swap(A[index],A[largest]);
        Heapify(A,largest,n);}
}

template <typename T>
void heapSort (std::vector<T>& A) {
    A.insert(A.begin(),0);
    int n = A.size()-1;
    BuildHeap(A,n);
    
    for (int i=n; i>=2; i--) {
        std::swap (A[i],A[1]);
        n--;
        Heapify(A,1,n);
    }
    A.erase(A.begin());
}