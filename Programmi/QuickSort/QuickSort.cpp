#include <vector>
#include <iostream>
using std::vector;

void QuickSort (vector <int>& A, int p, int dim);
int index (vector <int>& A, int p, int r);
void swap (vector <int>&A, int i, int j);

int main () {
    vector <int> A {7,12,11,17,6,6,3,8};
    int p{0};
    QuickSort(A, p, A.size());
    for (int i=0; i<A.size(); i++){
        std::cout << A[i] <<", ";
    }
}

void QuickSort (vector <int>& A, int p, int dim) {
    if (p<dim-1){
        int x=index(A,p,dim);
        QuickSort(A,p,x+1);
        QuickSort(A,x+1,dim);
    }
}

int index (vector <int>& A, int p, int dim) {
    int pivot = A[p];
    int i=p-1;
    int j=dim;
    while (true){
    do {
        j=j-1;
    } while (A[j]>pivot);
    do {
        i=i+1;
        } while (A[i]<pivot);
    if (i<j)
        swap (A,i,j);
        else return j;
    }
}

void swap (vector <int>&A, int i, int j){
    int x = A[i];
    A[i]=A[j];
    A[j]=x;
}