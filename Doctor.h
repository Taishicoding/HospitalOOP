#ifndef DOCTOR_H
#define DOCTOR_H
#include "MedStaff.h"
#include <vector>
#include <string>
class Doctor : public MedStaff {
private:
    std::string specialisation; 
    std::vector<std::string> patientList;
public:
    Doctor();
    Doctor(const std::string& name, int age, const std::string& contactNo,
           const std::string& employeeID, const std::string& department,
           const std::string& position, const std::string& qualifications,
           int experienceYears, const std::string& specialisation);
    virtual ~Doctor();
    std::string getSpecialisation() const;
    std::vector<std::string> getPatientList() const;
    void setSpecialisation(const std::string& specialisation);
    void addPatient(const std::string& patientID); 
    virtual void printInfo() const override;
};
#endif 
