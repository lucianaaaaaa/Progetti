// insertion sort
#include "Insertion.h"

template <typename sequence>
void InsertionSort (sequence& s, const int dim) {
    for (int i=1; i<dim; i++) {
        int key = s[i];
        int j=i;

        while (j>0 && s[j-1]>key){
            s[j]=s[j-1];
            j--;
        }
        s[j]=key;
    }
}
    