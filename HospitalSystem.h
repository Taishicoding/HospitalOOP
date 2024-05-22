#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include "Hospital.h"
#include <string>

// hospital system class definition
class HospitalSystem {
public:
    HospitalSystem(); // default constructor
    void run(); // runs the hospital system

private:
    Hospital hospital; // hospital instance
    void patientMode(); // mode for patient
    void doctorMode(); // mode for doctor
    void staffMode(); // mode for staff
    void setAppointment(Patient& patientObject); // sets an appointment for patient
    void accessPatientInfo(Patient& patientObject); // accesses patient info
    void settlePayment(Patient& patientObject); // settles payment for patient
    void addNewEmployee(); // adds a new employee
    void addNewPatient(); // adds a new patient
    Patient findPatientByID(const std::string& userID); // finds patient by id
    Appointment* findAppointmentByID(const std::string& appID); // finds appointment by id, returns pointer
    Employee findEmployeeByID(const std::string& userID); // finds employee by id
};

#endif
