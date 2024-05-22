#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include "Hospital.h"
#include <string>

class HospitalSystem {
public:
    HospitalSystem();
    void run();

private:
    Hospital hospital;
    void patientMode();
    void doctorMode();
    void staffMode();
    void setAppointment(Patient& patientObject);
    void accessPatientInfo(Patient& patientObject);
    void settlePayment(Patient& patientObject);
    void addNewEmployee();
    void addNewPatient();
    Patient findPatientByID(const std::string& userID);
    Appointment* findAppointmentByID(const std::string& appID);  // Return a pointer
    Employee findEmployeeByID(const std::string& userID);
};

#endif
