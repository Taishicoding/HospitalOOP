#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>
#include "Patient.h"
#include "Appointment.h"
#include "Employee.h"
#include "MedStaff.h"
#include "Nurse.h"
#include "Doctor.h"

class Hospital {
private:
    Patient** patients;
    Appointment** appointments;
    Employee** employees;
    int currentPatients;
    int currentAppointments;
    int currentEmployees;
    int patientCapacity;
    int staffCapacity;

public:
    Hospital();
    Hospital(int numPatients, int numStaff);
    ~Hospital();

    Patient** getPatientArray();
    Appointment** getAppointmentArray();
    Employee** getEmployeesArray();
    int getCurrentPatients() const;
    int getCurrentEmployees() const;
    int getCurrentNumAppointments() const; 

    void addNewPatient(std::string name, int age, std::string contact, std::string ID);
    void addNewEmployee(std::string name, int age, std::string contactNo, std::string ID, std::string department, std::string position);
    void addNewMedStaff(std::string name, int age, std::string contactNo, std::string ID, std::string department, std::string position, std::string qualifications, int experienceYears);
    void addNewNurse(std::string name, int age, std::string contactNo, std::string employeeID, std::string department, std::string position, std::string qualifications, int experienceYears, int shiftLength, std::string areaOfField, std::string ID);
    void addNewDoctor(std::string name, int age, std::string contactNo, std::string employeeID, std::string department, std::string position, std::string qualifications, int experienceYears, std::string specialisation);

    void addAppointmentRequest(Appointment* appointment);
    void approveAppointment(Appointment* appointment, double price);
};

#endif
