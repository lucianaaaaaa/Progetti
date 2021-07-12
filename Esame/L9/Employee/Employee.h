//Employee.h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee{
    public:
        Employee(const std::string&,const std::string&,const std::string&);
        virtual ~Employee() = default;

        void setFirstName(const std::string&);
        void setLastName(const std::string&);
        void setSSN(const std::string&);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getSSN() const;

        virtual double earnings() const=0; //pure virtual
        virtual std::string toString() const; //virtual

    private:
        std::string firstName;
        std::string lastName;
        std::string SSN;
};

#endif