#include <iostream>
#include <iomanip>
using std::cout;
    
int main () {
    for (int i=1; i<=70; i++) {
        cout << std::setw(2) << i << "--";
    }
}    
