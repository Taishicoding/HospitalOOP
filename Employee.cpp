#include "Employee.h"
#include <iostream>

// default constructor
// sets up employee with default values
Employee::Employee() : Person(), employeeID("5y4334y"), department("West"), position("Admin") {}

// parameterised constructor
// sets up employee with given details and calls parent class constructor
Employee::Employee(const std::string& name, int age, const std::string& contactInfo, 
                   const std::string& employeeID, const std::string& department, const std::string& position)
    : Person(name, age, contactInfo), employeeID(employeeID), department(department), position(position) {}

// destructor
// just destructor for employee class
Employee::~Employee() {}

// gets the employee's ID
std::string Employee::getEmployeeID() const {
    return employeeID;
}

// gets the employee's department
std::string Employee::getDepartment() const {
    return department;
}

// gets the employee's position
std::string Employee::getPosition() const {
    return position;
}

// sets the employee's ID
void Employee::setEmployeeID(const std::string& employeeID) {
    this->employeeID = employeeID;
}

// sets the employee's department
void Employee::setDepartment(const std::string& department) {
    this->department = department;
}

// sets the employee's position
void Employee::setPosition(const std::string& position) {
    this->position = position;
}

// prints out the employee's info
// calls parent class printInfo and then adds employee details
void Employee::printInfo() const {
    Person::printInfo();
    std::cout<< "Employee ID: "<<employeeID <<std::endl;
    std::cout<< "Department: "<<department <<std::endl;
    std::cout<< "Position: "<<position <<std::endl;
}
