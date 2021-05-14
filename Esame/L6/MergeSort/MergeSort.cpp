#include <vector>
#include <iostream>
using std::vector;

void Merge (vector <int>& A, int p, int q, int r);
void MergeSort (vector <int>&A, int p, int dim);

int main() {
    vector <int> A {7,12,11,17,6,6,3,8};
    int p = 0;
    MergeSort(A,p,A.size());
    for (int i=0; i<A.size(); i++){
        std::cout << A[i] <<", ";
    }
}

void MergeSort (vector <int>&A, int p, int dim){
    if (dim>1) {
        int q=dim/2; //la dimensione dei vettori da ordinare si dimezza
        int r=q+p; //indice di partenza del secondo MergeSort
        MergeSort(A,p,q);
        MergeSort(A,r,q);
        Merge(A,p,r,r+q);
    }
}

void Merge (vector <int>& A, int p, int q, int r) {
    int i{p};
    int j{q};
    int k{p};
    static vector <int> c(A.size()); //importante indicare la dimensione del vettore

    while (i<q && j<r)
    if (A[i]>A[j]) {
        c[k]=A[j];
        j++;
        k++;
    }
    else {
        c[k]=A[i];
        i++;
        k++;
    }

    while (i<q) {
        c[k]=A[i];
        k++;
        i++;
    }

    while (j<r) {
        c[k]=A[j];
        j++;
        k++;
    }

    for (i=p; i<k; i++){
        A[i]=c[i];
    }
}