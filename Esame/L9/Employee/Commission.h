#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

class CommissionEmployee: public Employee {
    public:
        CommissionEmployee(const std::string& f,const std::string& l,const std::string& s, 
            double g = 0.0, double rate=0.0): Employee(f,l,s) {
                setGrossSales(g);
                setCommissionRate(rate);
            }
    
        void setGrossSales(double g) {
            if (g<0) throw std::invalid_argument("gross sales cannot be negative");
            grossSales=g;
        }
        void setCommissionRate(double g) {
            if (g<0) throw std::invalid_argument("commission rate cannot be negative");
            commissionRate=g;
        }
        double getGrossSales () const {return grossSales;}
        double getCommissionRate () const {return commissionRate;}

        virtual std::string toString () const {
            std::ostringstream out;
            out << std::fixed << std::setprecision(2);
            out << "Commission employee: " << Employee::toString()
                << "\nGross sales: " << getGrossSales()
                << "; \nCommission rate: " << getCommissionRate();
            return out.str();
        }

        virtual double earnings() const {
            return commissionRate*grossSales;
        }

    private:
        double grossSales;
        double commissionRate;
};

#endif