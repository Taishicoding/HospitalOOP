#include "Nurse.h"
#include <iostream>

// default constructor
// sets up nurse with default values
Nurse::Nurse() : MedStaff(), shiftLength(5), areaOfField("Health") {}

// parameterised constructor
// sets up nurse with given details and calls parent class constructor
Nurse::Nurse(const std::string& name, int age, const std::string& contactNo,
             const std::string& employeeID, const std::string& department,
             const std::string& position, const std::string& qualifications,
             int experienceYears, int shiftLength, const std::string& areaOfField)
    : MedStaff(name, age, contactNo, employeeID, department, position, qualifications, experienceYears),
      shiftLength(shiftLength), areaOfField(areaOfField) {}

// destructor
// just a destructor for nurse class, doesn't do much
Nurse::~Nurse() {}

// gets the nurse's shift length
int Nurse::getShiftLength() const {
    return shiftLength;
}

// gets the nurse's roles
std::vector<std::string> Nurse::getRoles() const {
    return roles;
}

// gets the nurse's area of field
std::string Nurse::getAreaOfField() const {
    return areaOfField;
}

// sets the nurse's shift length
void Nurse::setShiftLength(int shiftLength) {
    this->shiftLength = shiftLength;
}

// adds a role to the nurse's list
void Nurse::addRole(const std::string& role) {
    roles.push_back(role);
}

// sets the nurse's area of field
void Nurse::setAreaOfField(const std::string& field) {
    this->areaOfField = field;
}

// prints out the nurse's info
// calls parent class printInfo and then adds nurse details
void Nurse::printInfo() const {
    MedStaff::printInfo(); 
    std::cout << "Shift Length: " << shiftLength << " hours\n";
    std::cout << "Area of Field: " << areaOfField << "\n";
    std::cout << "Roles: ";
    for (const auto& role : roles) {
        std::cout << role << ", ";
    }
    std::cout << std::endl;
}
