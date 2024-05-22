#include "Appointment2.h"
#include <iostream>
Appointment::Appointment(const std::string& id, const std::string& date, const std::string& time,
                         const std::string& patientID, const std::string& doctorID, const std::string& description)
    : appointmentID(id), date(date), time(time), patientID(patientID), doctorID(doctorID), description(description) {}
std::string Appointment::getAppointmentID() const { 
    return appointmentID; }
std::string Appointment::getDate() const { 
    return date; }
std::string Appointment::getTime() const { 
    return time; }
std::string Appointment::getPatientID() const { 
    return patientID; }
std::string Appointment::getDoctorID() const { 
    return doctorID; }
std::string Appointment::getDescription() const { 
    return description; }
void Appointment::setDate(const std::string& newDate) {
     date = newDate; }
void Appointment::setTime(const std::string& newTime) {
     time = newTime; }
void Appointment::setDescription(const std::string& newDescription) { 
    description = newDescription; }
void Appointment::printInfo() const {
    std::cout << "Appointment ID: " << appointmentID << std::endl
              << "Date: " << date << std::endl
              << "Time: " << time << std::endl
              << "Patient ID: " << patientID << std::endl
              << "Doctor ID: " << doctorID << std::endl
              << "Description: " << description << std::endl;
}
