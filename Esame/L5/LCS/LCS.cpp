//LCS.cpp
//Longest Common Subsequence with recursion

#include <iostream>
using std::cout;
using std::endl;

//max function
template <typename T>
const T& max (const T& x, const T& y) {
    return (x>y)? x : y;
}

//LCS recursive function
int lcs (std::string x, std::string y,int m, int n) {
    //m is the length of x, n the length of y
    if (m==0 || n==0) //one of the strings is empty
        return 0;
    if (x[m-1]==y[n-1]) //same last letter
        return 1 + lcs (x,y,m-1,n-1);
    else 
        return max (lcs(x,y,m-1,n), lcs(x,y,m,n-1));
}

int main () {
    std::string X{"ACGTCTGATC"};
    std::string Y{"CTGTGTAGTA"};

    cout << "length of LCS is " << lcs(X,Y,X.length(),Y.length()) << endl;
}