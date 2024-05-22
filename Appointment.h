#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Patient.h"

class Appointment {
private:
    Patient* patientPtr;
    std::string needs;
    std::string dateAndTime;
    std::string appointmentID;
    double appointmentPrice;

public:
    Appointment(Patient* patient, std::string needs, std::string dateAndTime, std::string appointmentID);
    Patient* getPatientPtr() const;
    std::string getAppointmentID() const;
    double getAppointmentPrice() const;
    void setAppointmentPrice(double price);
    void printInfo() const;
};

#endif
