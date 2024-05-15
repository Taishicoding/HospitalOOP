#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
#include <string>

class Employee: public Person{
    protected:
        std::string employeeID;
        std::string department;
        std::string position;
    public:
        Employee();
        Employee(const std::string& name, int age,const std::string& contactNo, const std::string& employeeID, const std::string& department, const std::string& position);
        virtual ~Employee();
        std::string getEmployeeID() const;
        std::string getDepartment() const;
        std::string getPosition() const;
        void setEmployeeID(const std::string& employeeID);
        void setDepartment(const std::string& department);
        void setPosition(const std::string& position);
        virtual void printInfo() const override;
};



#endif