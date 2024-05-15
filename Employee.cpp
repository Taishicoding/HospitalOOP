#include "Employee.h"
#include <iostream>
Employee::Employee() : Person(), employeeID("5y4334y"), department("West"), position("Admin") {}
Employee::Employee(const std::string& name, int age, const std::string& contactInfo, 
                   const std::string& employeeID, const std::string& department, const std::string& position)
    : Person(name, age, contactInfo), employeeID(employeeID), department(department), position(position) {}

Employee::~Employee() {}

std::string Employee::getEmployeeID() const {
    return employeeID;
}
std::string Employee::getDepartment() const {
    return department;
}
std::string Employee::getPosition() const {
    return position;
}
void Employee::setEmployeeID(const std::string& employeeID) {
    this->employeeID = employeeID;
}
void Employee::setDepartment(const std::string& department) {
    this->department = department;
}
void Employee::setPosition(const std::string& position) {
    this->position = position;
}
void Employee::printInfo() const {
    Person::printInfo();
    std::cout<< "Employee ID: "<<employeeID <<std::endl;
    std::cout<< "Department: "<<department <<std::endl;
    std::cout<< "Position: "<<position <<std::endl;
}