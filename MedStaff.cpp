#include "MedStaff.h"
#include <iostream>
// apparently to use std::remove algorithm is needed smh
#include <algorithm>

// default constructor
// sets up medstaff with default values
MedStaff::MedStaff() : Employee(), qualifications("cool"), experienceYears(9000) {}

// parameterised constructor
// sets up medstaff with given details and calls parent class constructor
MedStaff::MedStaff(const std::string& name, int age, const std::string& contactNo,
                   const std::string& employeeID, const std::string& department,
                   const std::string& position, const std::string& qualifications,
                   int experienceYears)
    : Employee(name, age, contactNo, employeeID, department, position),
      qualifications(qualifications), experienceYears(experienceYears) {}

// destructor
// just a destructor for medstaff class, doesn't do much
MedStaff::~MedStaff() {}

// gets the medstaff's qualifications
std::string MedStaff::getQualifications() const {
    return qualifications;
}

// gets the medstaff's years of experience
int MedStaff::getExperienceYears() const {
    return experienceYears;
}

// gets the list of patients assigned to the medstaff
std::vector<std::string> MedStaff::getAssignedpatients() const {
    return assignedPatients;
}

// sets the medstaff's qualifications
void MedStaff::setQualifications(const std::string& qualifications) {
    this->qualifications = qualifications;
}

// sets the medstaff's years of experience
void MedStaff::setExperienceyears(const int experienceYears) {
    this->experienceYears = experienceYears;
}

// adds a patient to the medstaff's assigned list
void MedStaff::setAssignedpatients(const std::string& patientID) {
    assignedPatients.push_back(patientID);
}

// removes a patient from the medstaff's assigned list
void MedStaff::unsetAssignedpatients(const std::string& patientID) {
    assignedPatients.erase(std::remove(assignedPatients.begin(), assignedPatients.end(), patientID), assignedPatients.end());
}

// prints out the medstaff's info
// calls parent class printInfo and then adds medstaff details
void MedStaff::printInfo() const {
    Employee::printInfo();
    std::cout << "Qualifications: " << qualifications << std::endl;
    std::cout << "Years of Experience: " << experienceYears << std::endl;
    std::cout << "Assigned Patients: ";
    for (const auto& patient : assignedPatients) {
        std::cout << patient << ", ";
    }
    std::cout << std::endl;
}
