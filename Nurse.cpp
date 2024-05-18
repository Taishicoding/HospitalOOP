#include "Nurse.h"
#include <iostream>

Nurse::Nurse() : MedStaff(), shiftLength(5), areaOfField("Health") {}

Nurse::Nurse(const std::string& name, int age, const std::string& contactNo,
             const std::string& employeeID, const std::string& department,
             const std::string& position, const std::string& qualifications,
             int experienceYears, int shiftLength, const std::string& areaOfField)
    : MedStaff(name, age, contactNo, employeeID, department, position, qualifications, experienceYears),
      shiftLength(shiftLength), areaOfField(areaOfField) {}

Nurse::~Nurse() {}

int Nurse::getShiftLength() const {
    return shiftLength;
}

std::vector<std::string> Nurse::getRoles() const {
    return roles;
}

std::string Nurse::getAreaOfField() const {
    return areaOfField;
}

void Nurse::setShiftLength(int shiftLength) {
    this->shiftLength = shiftLength;
}

void Nurse::addRole(const std::string& role) {
    roles.push_back(role);
}

void Nurse::setAreaOfField(const std::string& field) {
    this->areaOfField = field;
}
