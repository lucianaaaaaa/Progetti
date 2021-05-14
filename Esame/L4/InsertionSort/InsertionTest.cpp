#include <iostream>
#include <array>
#include "Insertion.h"
using std::cout;
using std::cin;
using std::array;

int main () {
    const int dim{7};
    array  <int,dim> numeri {0};
    int inserimento;
    int i{dim};
    cin >> inserimento;
    while (i>0) {
        i--;
        numeri[i] = inserimento%10;
        inserimento/=10;
    }

    InsertionSort (numeri,dim);
    cout << '\n';
    for (int j=0; j<dim; j++){
        cout << numeri[j];
    }
}