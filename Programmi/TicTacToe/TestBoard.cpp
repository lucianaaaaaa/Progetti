
#include <array>
#include <iostream>
using std::array;
using std::cout;
using std::endl;

void getBoard (array <array<int,3>,3> myArray);

int main () {
    array <array<int,3>,3> myArray{0};
    myArray [0][2] = 1;
    myArray [1][1] = 2;
    getBoard (myArray);
}

void getBoard (array <array<int,3>,3> myArray) {
    for (int i=0; i<3; i++) {
        cout << "   |   |   " << endl;
        for (int j=0; j<3; j++) {
            switch (myArray [i][j]) {
                case 1: 
                cout << " x ";
                break;
                case 2:
                cout << " o ";
                break;
                case 0:
                cout << "   ";
                break;
                default:
                cout << "Non dovresti essere qui" << endl;
            }
            if (j!=2)
            cout << "|";
        }
        cout << endl;
        if (i!=2)
        cout << "------------" << endl;
    }
}