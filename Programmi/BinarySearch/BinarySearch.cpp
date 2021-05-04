#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::string;
using std::cin;

bool BinarySearch (vector <int>& A, int token);

int main () {
    vector <int> A {3,6,6,9,11,13,14,17};
    int token{0};
    cout << "Inserire l'elemento da cercare: ";
    cin >> token;
    string message = (BinarySearch(A,token)==true) ? "l'hai trovato" : "non c'e' \n";
    cout << message;
    if (message=="non c'e' \n") {
        for (int i=0; i<A.size(); i++){
        std::cout << A[i] <<std::endl;
    }
    }
}

bool BinarySearch (vector <int>& A, int token) {
    int p{0};
    int r = A.size(); //potrebbe dare problemi, semmai sostituisci con =
    int q = (p+r)/2;
    do {
        if (A[q]<token) {
        //ripetere con p=q, r uguale
        p=q;
        }
        else if (A[q]>token) {
        //ripetere con p uguale, r=q
        r=q;
        }
        else return true;
        q=(p+r)/2;
    } while (r-p>1);
    vector<int>::iterator it;
    it = A.begin();
    A.insert(it+q+1,token);
    return false;
}