#include <iostream>
#define n 20
using std::cin;
using std::cout;
using std::endl;

//funzione prende in ingresso un array, restituisce bool
bool IsPalindrome (int number[], int length) {
    int j{0};
    for (int i =0; i <= (length)/2 ; i++) {
        j=length-i;
        if (number[i]!=number[j]) {
            return false;

         }
    }
    return true;
}


int main () {
    int number [n];
    int i{0};
    int L{0};
    int digits;

    cout << "inserisci numero" << endl;
    cin >> digits;

    //input numero, viene disposto nell'array number
    while (digits !=0) { 
        number[i++] = digits % 10;
        digits/=10;
    }

    L=--i;

    if (IsPalindrome(number,L)==true)
        cout << "il numero e\' palindromo " << endl;
    else
        cout << "il numero non e\' palindromo " << endl;

}






































