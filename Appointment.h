#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Patient.h"
// appointment class definition
// encapsulates details of a medical appointment
class Appointment {
// private member variables
private:
// pointer to the associated patient
    Patient* patientPtr;
// reason for the appointment
    std::string needs;
// date and time of the appointment
    std::string dateAndTime;
// unique identifier for the appointment
    std::string appointmentID;
// price of the appointment
    double appointmentPrice;
// public constructor
// initializes appointment with provided details
// public member functions
public:
    Appointment(Patient* patient, std::string needs, std::string dateAndTime, std::string appointmentID);
// returns pointer to the associated patient
    Patient* getPatientPtr() const;
// returns the appointment ID
    std::string getAppointmentID() const;
// returns the appointment price
    double getAppointmentPrice() const;
// sets the price for the appointment
    void setAppointmentPrice(double price);
// prints appointment details
    void printInfo() const;
};

#endif
