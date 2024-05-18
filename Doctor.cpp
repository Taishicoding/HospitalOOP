#include "Doctor.h"
#include <iostream>
Doctor::Doctor() : MedStaff(), specialisation("Surgeon") {}
Doctor::Doctor(const std::string& name, int age, const std::string& contactNo,
               const std::string& employeeID, const std::string& department,
               const std::string& position, const std::string& qualifications,
               int experienceYears, const std::string& specialization) : MedStaff(name, age, contactNo, employeeID, department, position, qualifications, experienceYears),
      specialisation(specialisation) {}
Doctor::~Doctor() {}
std::string Doctor::getSpecialisation() const {
    return specialisation;
}
std::vector<std::string> Doctor::getPatientList() const {
    return patientList;
}
void Doctor::setSpecialisation(const std::string& specialisation) {
    this->specialisation = specialisation;
}
void Doctor::addPatient(const std::string& patientID) {
    patientList.push_back(patientID);
}
void Doctor::printInfo() const {
    MedStaff::printInfo(); 
    std::cout << "Specialisation: " << specialisation << "\n";
    std::cout << "Patients List: ";
    for (const auto& patient : patientList) {
        std::cout << patient << ", ";
    }
    std::cout << std::endl;
}
