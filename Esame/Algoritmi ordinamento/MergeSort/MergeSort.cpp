#include <vector>
#include <iostream>
using std::vector;

template <typename T>
void Merge (vector <T>& A, int p, int q, int r);

template <typename T>
void MergeSort (vector <T>&A, int p, int dim);

int main() {
    vector <int> A {7,12,11,17,6,6,3,8};
    int p = 0;
    MergeSort(A,p,A.size());
    for (int i=0; i<A.size(); i++){
        std::cout << A[i] <<", ";
    }
}


template <typename T>
void MergeSort (vector <T>&A, int p, int dim){
    if (dim>1) {
        int q=dim/2; //la dimensione dei vettori da ordinare si dimezza
        int r=q+p; //indice di partenza del secondo MergeSort

        //dividi + ricorsione
        MergeSort(A,p,q);
        MergeSort(A,r,q);

        //ricomponi
        Merge(A,p,r,r+q);
    }
}

template <typename T>
void Merge (vector <T>& A, int p, int q, int r) {
    int i{p}; //indice prima parte
    int j{q}; //indice seconda parte
    int k{p}; //indice vettore c (formato dalla somma delle due sequenze di partenza)
    static vector <T> c(A.size()); //importante indicare la dimensione del vettore

    while (i<q && j<r) //sorting fino a quando i o j arrivano alla fine della propria sequenza
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

    while (i<q) { //se è arrivato j a fine sequenza
        c[k]=A[i];
        k++;
        i++;
    }

    while (j<r) { //se è arrivato i a fine sequenza
        c[k]=A[j];
        j++;
        k++;
    }

    for (i=p; i<k; i++){ //copia il vettore c in A
        A[i]=c[i];
    }
}