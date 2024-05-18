#ifndef MEDSTAFF_H
#define MEDSTAFF_H
#include "Employee.h"
#include <vector>
#include <string>
class MedStaff : public Employee {
    protected:
        std::string qualifications;
        int experienceYears;
        std::vector<std::string> assignedPatients;
    public:
        MedStaff();
        MedStaff(const std::string& name, int age, const std::string& contactNo,
             const std::string& employeeID, const std::string& department,
             const std::string& position, const std::string& qualifications,
             int experienceYears);
        virtual ~MedStaff();

        std::string getQualifications() const;
        int getExperienceYears() const;
        std::vector<std::string> getAssignedpatients() const;

        void setQualifications(const std::string& qualifications);
        void setExperienceyears(const int experienceYears);
        void setAssignedpatients(const std::string& patientID);
        void unsetAssignedpatients(const std::string& patientID);

        virtual void printInfo() const override;
};















#endif