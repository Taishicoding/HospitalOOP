#include "Patient.h"
#include <iostream>

// default constructor
// sets up patient with default values
Patient::Patient() : Person(), patientID("0") {}

// parameterised constructor
// sets up patient with given details and calls parent class constructor
Patient::Patient(const std::string& name, int age, const std::string& contactNo, std::string patientID)
    : Person(name, age, contactNo), patientID(patientID), outstandingBalance(0) {}

// gets the patient's id
std::string Patient::getPatientID() const {
    return patientID;
}

// gets the patient's symptoms
std::vector<std::string> Patient::getSymptoms() const {
    return symptoms;
}

// gets the patient's diagnosis
std::string Patient::getDiagnosis() const {
    return diagnosis;
}

// gets the patient's treatments
std::vector<std::string> Patient::getTreatments() const {
    return treatments;
}

// sets the patient's id
void Patient::setPatientID(std::string patientID) {
    this->patientID = patientID;
}

// adds a symptom to the patient's list
void Patient::setSymptoms(const std::string& symptom) {
    symptoms.push_back(symptom);
}

// sets the patient's diagnosis
void Patient::setDiagnosis(const std::string& diagnosis) {
    this->diagnosis = diagnosis;
}

// adds a treatment to the patient's list
void Patient::setTreatments(const std::string& treatment) {
    treatments.push_back(treatment);
}

// prints out the patient's info
// calls parent class printInfo and then adds patient details
void Patient::printInfo() const {
    Person::printInfo();
    std::cout << "Patient ID: " << patientID << std::endl;
    std::cout << "Diagnosis: " << diagnosis << std::endl;
    std::cout << "Symptoms:" << std::endl;
    for (const auto& symptom : symptoms) {
        std::cout << symptom << ", ";
    }
    std::cout << std::endl;
    std::cout << "Treatments:" << std::endl;
    for (const auto& treatment : treatments) {
        std::cout << treatment << ", ";
    }
    std::cout << std::endl;
}

// gets the patient's outstanding balance
double Patient::getOutstandingBalance() { 
    return outstandingBalance;
}

// sets the patient's outstanding balance
void Patient::setOutstandingBalance(double newPrice) { 
    outstandingBalance = newPrice;
}
