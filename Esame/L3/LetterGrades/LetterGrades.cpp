//LetterGrades.cpp
//using a switch statement to count letter grades
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;
using std::endl;

int main () {
    int total{0}; //sum of grades
    unsigned int gradeCounter{0}; //total number of grades
    unsigned int aCount{0}; //number of A grades
    unsigned int bCount{0}; //number of B grades
    unsigned int cCount{0}; //number of C grades
    unsigned int dCount{0}; //number of D grades
    unsigned int fCount{0}; //number of F grades

    cout << "Enter the integer grades in the range 0-100.\n"
        << "Type the end-of-file indicator to terminate input:\n"
        << "   On Windows type <Cntrl> z then press Enter\n";
    
    int grade;

    //loop until eof
    while (cin>>grade) {
        total+=grade; //add to total
        ++gradeCounter; //increment number of grades

        //increment appropriate letter
        switch (grade/10) {
            case 9:
            case 10: //100 included
                ++aCount;
                break;

            case 8: 
                ++bCount;
                break;
            
            case 7:
                ++cCount;
                break;

            case 6:
                ++dCount;
                break;
            
            default:
                ++fCount;
                break;
        }
    }

    //set floating point number format
    cout << fixed << setprecision(2);

    //display grade report if at least 1 grade entered
    cout << "\nGrade report:\n";

    if (gradeCounter !=0) {
        //calculate average
        double average = static_cast<double> (total)/gradeCounter;

        //output results
        cout << "Total of the " << gradeCounter << " grades entered is "
            << total << "\nClass average is " << average
            << "\nNumber of students who received each grade:"
            << "\nA " << aCount << "\nB " << bCount << "\nC " << cCount
            << "\nD " << dCount << "\nF " << fCount << endl;
    }
    else cout << "No grades were entered" << endl;

}
