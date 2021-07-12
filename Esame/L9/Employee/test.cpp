#include "Employee.h"
#include "Commission.h"
#include "CommissionPlus.h"
#include "Salaried.h"
#include <iostream>
#include <iomanip>
#include <vector>
using std::endl; using std::cout; 
using std::vector;

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main () {
    cout << std::fixed << std::setprecision(2);

    SalariedEmployee salaried {"Paul","Chambers","1324",800};
    CommissionEmployee commission {"Bill","Evans","7264",1000,0.06};
    CommissionPlusSalary plus {"Gino","Fornaio","2243",5000,0.04,300};

    cout << "EMPLOYEES PROCESSED INDIVIDUALLY USNIG STATIC BINDING\n"
        << salaried.toString()
        << "\n\n" << commission.toString()
        << "\n\n" << plus.toString() << "\n\n";
    
    vector <Employee*> employees 
        {&salaried, &commission, &plus};
    
    cout << "EMPLOYEES PROCESSED PPLYMORPHICALLY VIA DYNAMIC BINDING\n\n"
        << "VIRTUAL FUNCTION CALL MADE OFF BASE-CLASS POINTERS" << endl;
    
    for (const Employee* employeePtr: employees) {
        virtualViaPointer(employeePtr);
    }

    cout << "VIRTUAL FUNCTION CALL MADE OFF BASE-CLASS REFERENCES" << endl;
    for (const Employee* employeePtr: employees) {
        virtualViaReference(*employeePtr);
    }

}

void virtualViaPointer(const Employee* const ptr) {
    cout << ptr->toString()
        << "\nearned $" << ptr->earnings() << "\n\n";
}

void virtualViaReference(const Employee& ref) {
    cout << ref.toString()
        << "\nearned $" << ref.earnings() << "\n\n";
}