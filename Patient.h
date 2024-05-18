#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include "Person.h"
#include <vector>
class Patient : public Person{
    protected:
        int patientID; 
        std::vector<std::string> symptons;
        std::string diagnosis;
        std::vector<std::string> treatments;
    public:
        // Constructors, Only patient info is added now, as other info is appended later
        Patient();
        Patient(const std::string& name, int age, const std::string& contactNo,const int& patientID);
        //Callers
        int getPatientID()const;
        std::vector<std::string> getSymptons()const;
        std::string getDiagnosis()const;
        std::vector<std::string> getTreatment()const;
        //Setters
        void setpatientID(const int& patientID);
        void setSymptons(const std::string& sympton);
        void setDiagnosis(const std::string& diagnosis);
        void setTreatments(const std::string& treatment);
        //print
        void printInfo() const override;
};













#endif