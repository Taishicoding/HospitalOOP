#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "Person.h"

class Patient : public Person {
protected:
    std::string patientID;
    std::vector<std::string> symptoms;
    std::string diagnosis;
    std::vector<std::string> treatments;

    double outstandingBalance; 

public:
    Patient(); 
    Patient(const std::string& name, int age, const std::string& contactNo, std::string patientID);

    std::string getPatientID() const;
    std::vector<std::string> getSymptoms() const;
    std::string getDiagnosis() const;
    std::vector<std::string> getTreatments() const;

    void setPatientID(std::string patientID);
    void setSymptoms(const std::string& symptom);
    void setDiagnosis(const std::string& diagnosis);
    void setTreatments(const std::string& treatment);

    void printInfo() const override;

    double getOutstandingBalance();
    void setOutstandingBalance(double newPrice);
};

#endif // PATIENT_Hs