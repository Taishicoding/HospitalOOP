#include "Patient.h"
#include <iostream>

Patient::Patient() : Person(), patientID(0) {}

Patient::Patient(const std::string& name, int age, const std::string& contactNo, int patientID)
    : Person(name, age, contactNo), patientID(patientID) {}

int Patient::getPatientID() const {
    return patientID;
}

std::vector<std::string> Patient::getSymptoms() const {
    return symptoms;
}

std::string Patient::getDiagnosis() const {
    return diagnosis;
}

std::vector<std::string> Patient::getTreatments() const {
    return treatments;
}

void Patient::setPatientID(int patientID) {
    this->patientID = patientID;
}

void Patient::setSymptoms(const std::string& symptom) {
    symptoms.push_back(symptom);
}

void Patient::setDiagnosis(const std::string& diagnosis) {
    this->diagnosis = diagnosis;
}

void Patient::setTreatments(const std::string& treatment) {
    treatments.push_back(treatment);
}

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
