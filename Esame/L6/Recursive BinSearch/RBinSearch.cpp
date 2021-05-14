//RBinSearch.cpp
//recursive implementation of binary search
//binary search returns position if the element is present
//returns -1 otherwise
#include <vector>
#include <string>
#include <iostream>
using std::vector;

template <typename T>
int BinSearch (const vector <T>& v, const T& elem, int beg, int end);



int main () {
    std::string a{"coccoline"};
    vector <std::string> v{"nanna","pappa","cacca","coccoline","bacini"};
    //ATTENZIONE VETTORE NON ORDINATO
    for (int i =0; i<5; i++) std::cout << v[i] << ", ";
    std::cout << std::endl << BinSearch(v,a,0,v.size());
}

template <typename T>
int BinSearch (const vector <T>& v, const T& elem, int beg, int end) {
    //caso base: vettore con un solo elemento
    if (beg==end-1) {
        if (v[beg]==elem) return beg;
        else return -1;
    }

    //caso ricorsivo
    int x = (beg+end)/2;
    if (elem == v[x]) return x; //trovata corrispondenza
    if (elem < v[x]) return BinSearch (v,elem,beg,x);
    else return BinSearch (v,elem,x,end);
}


