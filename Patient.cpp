#include "Patient.h"
#include <iostream>
//Constructors
Patient::Patient() :Person(), patientID() {}
Patient::Patient(const std::string& name, int age, const std::string& contactNo,const int& patientID)
Patient::Person(name,age,contactNo), patientID(patientID){}
//get functions
int Patient::getPatientID()const{
    return patientID;
 }
 std::vector<std::string> Patient::getSymptons()const{
    return symptons;
 }
  std::string Patient::getDiagnosis()const{
    return diagnosis;
 }
  std::vector<std::string> Patient::getTreatment()const{
    return treatments;
 }
 //setter functions
 void Patient::setpatientID(const int& patientID){
    this->patientID = patientID;
 };
  void Patient::setSymptons(const std::string& sympton){
    symptons.push_back(sympton);
 };
  void Patient::setDiagnosis(const std::string& diagnosis) {
    this->diagnosis = diagnosis;
};
  void Patient::setTreatments(const std::string& treatment){
    treatments.push_back(treatment);
 };
 //print function
 void Patient::printInfo() const{
    Person::printInfo();
    std::cout<<"Patient ID:"<<" "<<patientID<<std::endl;
    std::cout<<"Diagnosis:"<<" "<<diagnosis<<std::endl;
    //Add a for loop later that
    std::cout<<"Symptons:"<<std::endl;
     for (const auto& sympton : symptons) {
        std::cout << sympton << ", ";
    }
    std::cout<<"Treatments:"<<std::endl;
    for (const auto& treatment : treatments) {
        std::cout << treatment << ", ";
    };
    };


