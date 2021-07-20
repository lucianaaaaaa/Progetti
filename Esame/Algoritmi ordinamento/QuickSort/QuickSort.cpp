#include <vector>
#include <iostream>
using std::vector;

template <typename T>
void QuickSort (vector <T>& A, int p, int dim);

template <typename T>
int index (vector <T>& A, int p, int r);

template <typename T>
void swap (vector <T>&A, int i, int j);

int main () {
    vector <int> A {7,12,11,17,6,6,3,8};
    int p{0};
    QuickSort(A, p, A.size());
    for (int i=0; i<A.size(); i++){
        std::cout << A[i] <<", ";
    }
}

template <typename T>
void QuickSort (vector <T>& A, int p, int dim) {
    // p = indice di partenza
    // dim = indice finale
    if (p<dim-1){ 
        int x=index(A,p,dim);
        QuickSort(A,p,x+1);
        QuickSort(A,x+1,dim);
    }
}

template <typename T>
int index (vector <T>& A, int p, int dim) {
    T pivot = A[p];
    int i=p-1; //estrema sx
    int j=dim; //estrema dx
    while (true){
    do {
        j=j-1; //muovi j a sx
    } while (A[j]>pivot); //finché gli elementi a dx sono maggiori del pivot
    do {
        i=i+1; //muovi i a dx
        } while (A[i]<pivot); //finché gli elementi a sx sono minori del pivot
    if (i<j)
        swap (A,i,j); 
        else return j; //se j<i, ho diviso la sequenza
    }
}

template <typename T>
void swap (vector <T>&A, int i, int j){
    T x = A[i];
    A[i]=A[j];
    A[j]=x;
}