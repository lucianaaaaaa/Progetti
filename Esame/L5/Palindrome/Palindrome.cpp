#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

//funzione prende in ingresso un array, restituisce bool
template <typename T>
bool IsPalindrome (vector<T> v, int i, int j) {
    //caso base
    if (j-i <= 1) return true;

    //recursion
    return IsPalindrome(v,i+1,j-1) && (v[i]==v[j]);
}


int main () {
    vector<int> number;
    int i{0};
    int L{0};
    int digits;

    cout << "inserisci numero: ";
    cin >> digits;

    //input numero, viene disposto nell'array number
    while (digits !=0) { 
        number.push_back(digits % 10);
        digits/=10;
    }

    if (IsPalindrome(number, 0, number.size()-1)==true)
        cout << "il numero e\' palindromo " << endl;
    else
        cout << "il numero non e\' palindromo " << endl;

}