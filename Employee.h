#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <string>

// employee class inherits from person
class Employee: public Person {
protected:
    std::string employeeID; // employee's id
    std::string department; // employee's department
    std::string position;   // employee's position

public:
    Employee(); // default constructor
    Employee(const std::string& name, int age, const std::string& contactNo, const std::string& employeeID, const std::string& department, const std::string& position); // constructor with parameters
    virtual ~Employee(); // destructor
    std::string getEmployeeID() const; // gets employee id
    std::string getDepartment() const; // gets department
    std::string getPosition() const; // gets position
    void setEmployeeID(const std::string& employeeID); // sets employee id
    void setDepartment(const std::string& department); // sets department
    void setPosition(const std::string& position); // sets position
    virtual void printInfo() const override; // prints info about employee
};

#endif
