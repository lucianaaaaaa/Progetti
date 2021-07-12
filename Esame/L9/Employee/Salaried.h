#include "Employee.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

class SalariedEmployee: public Employee {
    public:
        SalariedEmployee(const std::string& f,const std::string& l,const std::string& s, 
            double sal = 0.0): Employee(f,l,s) {
                setSalary(sal);
            }
    
        void setSalary(double g) {
            if (g<0) throw std::invalid_argument("salary cannot be negative");
            salary=g;
        }
        double getSalary () const {return salary;}

        std::string toString () const {
            std::ostringstream out;
            out << std::fixed << std::setprecision(2);
            out << "Salaried employee: " << Employee::toString()
                << "\nWeekly salary: " << getSalary();
            return out.str();
        }

        double earnings() const {
            return salary;
        }

    private:
        double salary;
};