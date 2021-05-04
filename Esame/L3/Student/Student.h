//Student.h
//Student class that stores a student's name and average

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
    public:
    //constructor
    Student (std::string studentName, int studentAverage)
    : name (studentName) {
        //check if average valid
        setAverage (studentAverage);
    }

    //set e get
    void setName (std::string studentName) {
        name = studentName;
    }
    std::string getName () const {
        return name;
    }

    void setAverage (int studentAverage) {
        //average must be between 0 and 100
        if (studentAverage>0 && studentAverage <=100)
        average = studentAverage;
    }
    int getAverage () const {return average;}

    //calculates the student's letter grade
    std::string getLetterGrade() const {
        std::string letterGrade;

        if (average>=90) {
            letterGrade="A";
        }
        else if (average>=80) {
            letterGrade="B";
        }
        else if (average>=70) {
            letterGrade="C";
        }
        else if (average>=60) {
            letterGrade="D";
        }
        else letterGrade="F";

        return letterGrade;
    }

    private:
    std::string name;
    int average{0};
};

#endif