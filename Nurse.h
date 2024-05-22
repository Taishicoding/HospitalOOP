#ifndef NURSE_H
#define NURSE_H

#include "MedStaff.h"
#include <vector>
#include <string>

// nurse class inherits from medstaff
class Nurse : public MedStaff {
private:
    int shiftLength; // length of nurse's shift
    std::vector<std::string> roles; // list of nurse's roles
    std::string areaOfField; // nurse's area of specialization

public:
    Nurse(); // default constructor
    Nurse(const std::string& name, int age, const std::string& contactNo,
          const std::string& employeeID, const std::string& department,
          const std::string& position, const std::string& qualifications,
          int experienceYears, int shiftLength, const std::string& areaOfField); // constructor with parameters
    virtual ~Nurse(); // destructor

    int getShiftLength() const; // gets shift length
    std::vector<std::string> getRoles() const; // gets roles
    std::string getAreaOfField() const; // gets area of field

    void setShiftLength(int shiftLength); // sets shift length
    void addRole(const std::string& role); // adds a role
    void setAreaOfField(const std::string& field); // sets area of field

    virtual void printInfo() const override; // prints info about nurse
};

#endif
