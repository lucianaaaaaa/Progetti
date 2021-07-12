#include "Employee.h"
#include "Commission.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

class CommissionPlusSalary: public CommissionEmployee {
    public:
        CommissionPlusSalary(const std::string& f,const std::string& l,const std::string& s, 
            double g = 0.0, double rate=0.0, double sal=0): CommissionEmployee(f,l,s,g,rate) {
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
            out << "Commission plus salary employee: " << CommissionEmployee::toString()
                << "\nWeekly salary: " << getSalary();
            return out.str();
        }

        double earnings() const {
            return salary + CommissionEmployee::earnings();
        }

    private:
        double salary;
};