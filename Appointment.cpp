#include "Appointment.h"
#include <iostream>

Appointment::Appointment(Patient* patient, std::string needs, std::string dateAndTime, std::string appointmentID)
    : patientPtr(patient), needs(needs), dateAndTime(dateAndTime), appointmentID(appointmentID), appointmentPrice(0.0) {}

Patient* Appointment::getPatientPtr() const {
    return patientPtr;
}

std::string Appointment::getAppointmentID() const {
    return appointmentID;
}

double Appointment::getAppointmentPrice() const {
    return appointmentPrice;
}

void Appointment::setAppointmentPrice(double price) {
    appointmentPrice = price;
}

void Appointment::printInfo() const {
    std::cout << "Appointment ID: " << appointmentID << "\n"
              << "Needs: " << needs << "\n"
              << "Date and Time: " << dateAndTime << "\n"
              << "Appointment Price: " << appointmentPrice << std::endl;
}
