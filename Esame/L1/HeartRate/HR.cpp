#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main () {
    int age,f1,f2,f3,f4,min,max {0};
    //inserisci input età
    cout << "inserisci la tua età:\n";
    cin >> age;
    
    //prima formula common
    f1= 220-age;
    cout << "Common formula:" << f1 << endl;
    min = f1;
    max = f1;

    //formula tanaka
    f2 = 208 - 0.7*age;
    cout << "Tanaka formula:" << f2 << endl;
    if (f2<min) {
        min = f2;
    }
    if (f2>max) {
        max = f2;
    }
        //formula Gellish
    f3 = 207 - 0.7*age;
    cout << "Gellish formula:" << f3 << endl;
    if (f3<min) {
        min = f3;
    }
    if (f3>max) {
        max = f3;
    }
        //formula Nes
    f4 = 211 - 0.64*age;
    cout << "Nes formula:" << f4 << endl;
    if (f4<min) {
        min = f4;
    }
    if (f4>max) {
        max = f4;
    }

    //dice minimo e massimo
    cout << "il minimo e\'" << min << endl;
    cout << "il massimo e\'" << max << endl;
}