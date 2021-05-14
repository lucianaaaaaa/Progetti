#include <vector>
#include <iostream>
#include <algorithm>
#include "Book.h"
#include "Article.h"
#include "Conference.h"
#include "Publication.h"
using std::vector;

template <typename T>
void QuickSort (vector <T>& A, int p, int dim);

template <typename T>
int index (vector <T>& A, int p, int r);

template<typename T>
void swap(T **r, T **s);

int main () {
    Book b1 ("Book", "Peppino,Giovanni", 1997, "CheccoEditors", "2543512");
    Article b2 ("Development of checcos", "Alfonso,Peppino,Giovanni", 1998, "Checco Mag", 1, 2, 3);
    Conference b3 ("Sviluppo dei Checchi", "Ubaldo,Peppino,Giovanni", 1997, "Checconference", 52, "Conversano in Puglia");
    Book b4 ("La storia modiale dei Checchi", "Checconverse", 1997, "CheccoEditors", "666");
    vector <Publication*> A;
    A.push_back(&b1);
    A.push_back(&b2);
    A.push_back(&b3);
    A.push_back(&b4);
    int p{0};
    
    QuickSort (A, p, A.size());

    //initialize counters
    int bookctr{0};
    int artctr{0};
    int conctr{0};

    for (int i=0; i<A.size(); i++) {
        Book* bookptr= dynamic_cast<Book*> (A[i]);
        Article* artptr= dynamic_cast<Article*> (A[i]);
        if (bookptr!=nullptr)
            bookctr++;
        else if (artptr!=nullptr)
            artctr++;
        else conctr++;

        std::cout << A[i]->toString() <<", \n";
    }

    //display counters
    std::cout << "Books: " << bookctr << "\nMagazine Articles: " << artctr 
        << "\nConference Articles: " << conctr;


}

template <typename T>
void QuickSort (vector <T>& A, int p, int dim) {
    if (p<dim-1){
        int x=index(A,p,dim);
        QuickSort(A,p,x+1);
        QuickSort(A,x+1,dim);
    }
}

template <typename T>
int index (vector <T>& A, int p, int dim) {
    T pivot = A[p];
    int i=p-1;
    int j=dim;
    while (true){
    do {
        j=j-1;
    } while ( *pivot < *A[j]);
    do {
        i=i+1;
        } while (*A[i]<*pivot);
    if (i<j)
        swap (&A[i],&A[j]);
    else return j;
    }
}

template<typename T>
void swap(T **r, T **s)
{
    T *pSwap = *r;
    *r = *s;
    *s = pSwap;
}