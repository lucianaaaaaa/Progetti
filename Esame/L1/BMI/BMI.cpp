//calcolo BMI
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main () {
    int weight {0};
    float height{0};

    //chiedi peso
    cout << "Inserire peso:\n";
    cin >> weight;

    //chiedi altezza
    cout << "Inserire altezza (in m):\n";
    cin >> height;

    //calculate bmi
    float bmi {weight/(height*height)};
    cout << "il tuo BMI e\':" << bmi << endl;

    if (bmi<18.5)
    cout << "Sei sottopeso" << endl;
    else if (18.5 <= bmi && bmi <=24.9 )
    cout << "Hai un peso regolare" << endl;
    else if (24.9 < bmi && bmi < 29.9)
    cout << "Sei sovrappeso" << endl;
    else cout << "Sei obeso" << endl;
    
}