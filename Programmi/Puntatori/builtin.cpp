#include <iostream>
#include <array>
using std::cout;

int main () {
    int v[]{0,1,2,3,4,5};
    int* ptr{nullptr};
    ptr = v;
    

    cout <<"Metodo 1: *(ptr+3)=" <<  *(ptr+3) <<'\n';
    cout <<"Metodo 2: *(v+3)=" << *(v+3) << '\n';
    cout <<"Metodo 3: v[3]=" << v[3] << '\n';
    cout <<"Metodo 4: ptr[3]=" << ptr[3] << '\n';
}