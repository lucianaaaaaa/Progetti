//LCS.cpp
//Iterative solution of LCS using 2D array
#include <iostream>
#include <string>
#include <array>
using std::cout;
using std::endl;
using std::array;
using std::string;

//function prototypes
int lcs (const string& a,const string& b);
template <typename T>
const T& max (const T& x, const T& y);

int main() {
    //initialize strings
    string a = "-ATACCAGA";
    string b = "-CTCCTAG";

    //find LCS
    cout << "LCS of " << a << " and " << b << " is " << lcs(a,b) << endl;
}

int lcs (const string& a,const string& b) { 
    
    //define table and initialize members to 0
    array<array<int,8>,9> table{};

    //a[i], b[j]    
    //define elements of table
    //column/row 0 excluded
    for (int i=1; i<9; i++) { //for each row
        for (int j=1; j<8; j++) { //for each column

            if (a[i]==b[j])
                table [i][j] = table [i-1][j-1] +1; //if letters are the same
            else table [i][j] = max(table[i-1][j],table[i][j-1]); //if letters differ
        }
    }

    return table[8][7];
}

//max function
template <typename T>
const T& max (const T& x, const T& y) {
    return (x>y)? x : y;
}