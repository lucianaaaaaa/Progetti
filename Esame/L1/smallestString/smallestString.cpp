//find the smallest string
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main () {
    string word, smallest;
    cout << "Insert sentence: " << endl;
    while (cin>>word) {
        if (smallest.empty() || word<smallest)
        smallest = word;
    }
    cout << smallest << endl;
    return 0;
}