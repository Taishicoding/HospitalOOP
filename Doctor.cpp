#include "Doctor.h"
#include <iostream>

// default constructor
// initializes doctor with default values
Doctor::Doctor() : MedStaff(), specialisation("Surgeon") {}

// parameterised constructor
// initializes doctor with provided values and calls base class constructor
Doctor::Doctor(const std::string& name, int age, const std::string& contactNo,
               const std::string& employeeID, const std::string& department,
               const std::string& position, const std::string& qualifications,
               int experienceYears, const std::string& specialisation) : MedStaff(name, age, contactNo, employeeID, department, position, qualifications, experienceYears),
      specialisation(specialisation) {}

// destructor
// default destructor for doctor class
Doctor::~Doctor() {}

// returns doctor's specialisation
std::string Doctor::getSpecialisation() const {
    return specialisation;
}

// returns list of patients assigned to the doctor
std::vector<std::string> Doctor::getPatientList() const {
    return patientList;
}

// sets doctor's specialisation
void Doctor::setSpecialisation(const std::string& specialisation) {
    this->specialisation = specialisation;
}

// adds a patient to the doctor's patient list
void Doctor::addPatient(const std::string& patientID) {
    patientList.push_back(patientID);
}

// prints doctor's information
// calls base class printInfo method and adds specialisation and patient list
void Doctor::printInfo() const {
    MedStaff::printInfo(); 
    std::cout << "Specialisation: " << specialisation << "\n";
    std::cout << "Patients List: ";
    for (const auto& patient : patientList) {
        std::cout << patient << ", ";
    }
    std::cout << std::endl;
}
