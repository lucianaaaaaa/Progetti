//ClassAverage.cpp
//Computing class-average using sentinel controlled iteration
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main () {
    //initialization
    int total{0};
    unsigned int gradeCounter{0};
    int grade;

    //ask input
    cout << "Enter grade or -1 to quit: ";
    cin >> grade;

    //loop until -1
    while (grade!=-1) {
        total += grade;
        gradeCounter++;

        //ask input again
        cout << "Enter grade or -1 to quit: ";
        cin >> grade;
    }

    //if user entered at least 1 grade
    if (gradeCounter!=0) {
        //calculate average
        double average {static_cast<double>(total)/gradeCounter};

        cout << "\nTotal of the " << gradeCounter
            << " grades entered is " << total;
        cout << std::setprecision(2) << std::fixed; //numero con virgola con 2 cifre decimali
        cout << "\nClass average is " << average << endl;
    }
    else cout << "\nNo grades were entered" << endl;
}