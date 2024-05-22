#ifndef MEDSTAFF_H
#define MEDSTAFF_H

#include "Employee.h"
#include <vector>
#include <string>

// medstaff class inherits from employee
class MedStaff : public Employee {
protected:
    std::string qualifications; // medical staff's qualifications
    int experienceYears; // years of experience
    std::vector<std::string> assignedPatients; // list of assigned patients

public:
    MedStaff(); // default constructor
    MedStaff(const std::string& name, int age, const std::string& contactNo,
             const std::string& employeeID, const std::string& department,
             const std::string& position, const std::string& qualifications,
             int experienceYears); // constructor with parameters
    virtual ~MedStaff(); // destructor

    std::string getQualifications() const; // gets qualifications
    int getExperienceYears() const; // gets years of experience
    std::vector<std::string> getAssignedpatients() const; // gets assigned patients

    void setQualifications(const std::string& qualifications); // sets qualifications
    void setExperienceyears(const int experienceYears); // sets years of experience
    void setAssignedpatients(const std::string& patientID); // adds a patient to assigned list
    void unsetAssignedpatients(const std::string& patientID); // removes a patient from assigned list

    virtual void printInfo() const override; // prints info about medical staff
};

#endif
