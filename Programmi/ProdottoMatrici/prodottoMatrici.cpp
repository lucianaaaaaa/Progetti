// prodotto tra matrici
#include <iostream>
#include <array>
using std::array;
const int n{3};
const int m{2};
const int p{4};

void ProdMat (const array <array<int,m>,n> mat1,const array <array<int,p>,m> mat2, array <array<int,p>,n>& risult);
void PrintMat (const array <array<int,p>,n> mat);

int main () {

   
    array <array<int,m>,n> mat1 {1,2,3,4,5,6};
    array <array<int,p>,m> mat2 {1,2,3,4,5,6,7,8};
    array <array<int,p>,n> risult{0,0,0,0,0,0,0,0,0};
    ProdMat(mat1,mat2,risult);
    PrintMat (risult); 
}

void ProdMat (const array <array<int,m>,n> mat1,const array <array<int,p>,m> mat2, array <array<int,p>,n>& risult) {

     for (int i=0; i<n; i++) { //riga i-esima del risultato
        for (int j=0; j<p; j++) { //colonna j-esima del risultato
            int k{0};
            do { //indice comune alle 2 matrici
                risult[i][j] += mat1[i][k]*mat2[k][j];
                k++;
            } while (k<m);
        }
    }
}

void PrintMat (const array <array<int,p>,n> mat) {
    for (auto const& row:mat) {
        for (auto const& element:row){
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}