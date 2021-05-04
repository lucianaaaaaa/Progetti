//test student class
#include <iostream>
#include "Student.h"

int main () {
    Student stud1 ("Jane Green",93);
    Student stud2 ("John Blue",-10);

    std::cout << stud1.getName () << "'s letter grade equivalent of " << stud1.getAverage() 
    << " is: " << stud1.getAverage () << std::endl;

    //initial average of second student
    std::cout << stud2.getName() << "'s average is: " << stud2.getAverage() << std::endl;

    //set actual average
    stud2.setAverage(72);

    std::cout << stud2.getName() << "'s average was set to " << stud2.getAverage()
        << ", which is equivalent to " << stud2.getLetterGrade() << std::endl;
        
}