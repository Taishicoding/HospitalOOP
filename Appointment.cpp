#include "Appointment.h"
#include <iostream>
// constructor initializing appointment details
// sets initial appointment price to 0.0
// demonstrating abstraction by hiding internal details of how appointments are created
Appointment::Appointment(Patient* patient, std::string needs, std::string dateAndTime, std::string appointmentID)
    : patientPtr(patient), needs(needs), dateAndTime(dateAndTime), appointmentID(appointmentID), appointmentPrice(0.0) {}
// returns pointer to the associated patient
// this allows access to patient details from the appointment
Patient* Appointment::getPatientPtr() const {
    return patientPtr;
}
// returns the appointment ID
// unique identifier for each appointment
std::string Appointment::getAppointmentID() const {
    return appointmentID;
}
// returns the appointment price
// getter method to access the price of the appointment
double Appointment::getAppointmentPrice() const {
    return appointmentPrice;
}
// sets the price for the appointment
// used when approving an appointment to assign its cost
void Appointment::setAppointmentPrice(double price) {
    appointmentPrice = price;
}
// prints appointment details
// demonstrates abstraction by providing a method to display appointment information without exposing internal data representation
void Appointment::printInfo() const {
    std::cout << "Appointment ID: " << appointmentID << "\n"
              << "Needs: " << needs << "\n"
              << "Date and Time: " << dateAndTime << "\n"
              << "Appointment Price: " << appointmentPrice << std::endl;
}
