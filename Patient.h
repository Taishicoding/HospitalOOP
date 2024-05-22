#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "Person.h"

// patient class inherits from person
class Patient : public Person {
protected:
    std::string patientID; // patient's id
    std::vector<std::string> symptoms; // list of symptoms
    std::string diagnosis; // diagnosis of the patient
    std::vector<std::string> treatments; // list of treatments

    double outstandingBalance; // balance due for the patient

public:
    Patient(); // default constructor
    Patient(const std::string& name, int age, const std::string& contactNo, std::string patientID); // constructor with parameters

    std::string getPatientID() const; // gets patient id
    std::vector<std::string> getSymptoms() const; // gets symptoms
    std::string getDiagnosis() const; // gets diagnosis
    std::vector<std::string> getTreatments() const; // gets treatments

    void setPatientID(std::string patientID); // sets patient id
    void setSymptoms(const std::string& symptom); // sets symptoms
    void setDiagnosis(const std::string& diagnosis); // sets diagnosis
    void setTreatments(const std::string& treatment); // sets treatments

    void printInfo() const override; // prints info about the patient

    double getOutstandingBalance(); // gets outstanding balance
    void setOutstandingBalance(double newPrice); // sets outstanding balance
};

#endif // PATIENT_H
