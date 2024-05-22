#ifndef DOCTOR_H
#define DOCTOR_H

#include "MedStaff.h"
#include <vector>
#include <string>

// doctor class inherits from medstaff
class Doctor : public MedStaff {
private:
    std::string specialisation; 
// what kind of doctor
    std::vector<std::string> patientList; 
// list of patients
public:
    Doctor();
// default constructor
    Doctor(const std::string& name, int age, const std::string& contactNo,
           const std::string& employeeID, const std::string& department,
           const std::string& position, const std::string& qualifications,
           int experienceYears, const std::string& specialisation); // constructor with parameters
    virtual ~Doctor(); // destructor
    std::string getSpecialisation() const; // gets the specialisation
    std::vector<std::string> getPatientList() const; // gets the patient list
    void setSpecialisation(const std::string& specialisation); // sets the specialisation
    void addPatient(const std::string& patientID); // adds a patient to the list
    virtual void printInfo() const override; // prints info about the doctor
};

#endif
