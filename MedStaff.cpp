#include "MedStaff.h"
#include "MedStaff.h"
#include <iostream>
//Apparently to use std::remove alogortihtm is needed smh
#include <algorithm>

MedStaff::MedStaff() : Employee (), qualifications("cool"),experienceYears(9000){};
MedStaff::MedStaff(const std::string& name, int age, const std::string& contactNo,
                   const std::string& employeeID, const std::string& department,
                   const std::string& position, const std::string& qualifications,
                   int experienceYears)
    : Employee(name, age, contactNo, employeeID, department, position),
      qualifications(qualifications), experienceYears(experienceYears){}
MedStaff::~MedStaff(){};

std::string MedStaff::getQualifications() const{
    return qualifications;
};
int MedStaff::getExperienceYears() const {
    return experienceYears;
};
std::vector<std::string> MedStaff::getAssignedpatients() const{
    return assignedPatients;
}
void MedStaff::setQualifications(const std::string& qualifications){
    this-> qualifications = qualifications;
}
void MedStaff::setExperienceyears(const int experienceYears){
    this-> experienceYears = experienceYears;
}
void MedStaff::setAssignedpatients(const std::string& patientID){
    assignedPatients.push_back(patientID);
}
void MedStaff::unsetAssignedpatients(const std::string& patientID){
    assignedPatients.erase(std::remove(assignedPatients.begin(),assignedPatients.end(),patientID),assignedPatients.end());
}

void MedStaff::printInfo()const{
    Employee::printInfo();
    std::cout<<"Qualifications:"<<" "<<std::endl;
    std::cout<<"Years of Experience:"<<" "<<std::endl;
    std::cout<<"Assigned Patients:";
    for (const auto&patient :assignedPatients){
        std::cout << patient << ",";
    }
    std::cout<<std::endl;

}
