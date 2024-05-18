#ifndef NURSE_H
#define NURSE_H

#include "MedStaff.h"
#include <vector>
#include <string>

class Nurse : public MedStaff {
private:
    int shiftLength;
    std::vector<std::string> roles;
    std::string areaOfField;

public:
    Nurse();
    Nurse(const std::string& name, int age, const std::string& contactNo,
          const std::string& employeeID, const std::string& department,
          const std::string& position, const std::string& qualifications,
          int experienceYears, int shiftLength, const std::string& areaOfField);
    virtual ~Nurse();

    int getShiftLength() const;
    std::vector<std::string> getRoles() const;
    std::string getAreaOfField() const;

   
    void setShiftLength(int shiftLength);
    void addRole(const std::string& role); 
    void setAreaOfField(const std::string& field);

    virtual void printInfo() const override;
};

#endif 
