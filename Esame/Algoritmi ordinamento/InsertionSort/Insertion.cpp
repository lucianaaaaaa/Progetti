// insertion sort
#include <vector>

template <typename T>
void InsertionSort (std::vector<T>& s, const int dim) {
    for (int i=1; i<dim; i++) {
        T key = s[i]; //elemento da confrontare
        int j=i;

        //parto da j=i e risalgo inserendo key nella posizione corretta
        while (j>0 && s[j-1]>key){ 
            s[j]=s[j-1];
            j--;
        }
        s[j]=key;
    }
}
    