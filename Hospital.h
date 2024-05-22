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

// hospital class definition
class Hospital {
private:
    Patient** patients; // array of patients
    Appointment** appointments; // array of appointments
    Employee** employees; // array of employees
    int currentPatients; // current number of patients
    int currentAppointments; // current number of appointments
    int currentEmployees; // current number of employees
    int patientCapacity; // maximum number of patients
    int staffCapacity; // maximum number of staff

public:
    Hospital(); // default constructor
    Hospital(int numPatients, int numStaff); // constructor with parameters
    ~Hospital(); // destructor

    Patient** getPatientArray(); // gets array of patients
    Appointment** getAppointmentArray(); // gets array of appointments
    Employee** getEmployeesArray(); // gets array of employees
    int getCurrentPatients() const; // gets current number of patients
    int getCurrentEmployees() const; // gets current number of employees
    int getCurrentNumAppointments() const; // gets current number of appointments

    void addNewPatient(std::string name, int age, std::string contact, std::string ID); // adds a new patient
    void addNewEmployee(std::string name, int age, std::string contactNo, std::string ID, std::string department, std::string position); // adds a new employee
    void addNewMedStaff(std::string name, int age, std::string contactNo, std::string ID, std::string department, std::string position, std::string qualifications, int experienceYears); // adds a new medical staff member
    void addNewNurse(std::string name, int age, std::string contactNo, std::string employeeID, std::string department, std::string position, std::string qualifications, int experienceYears, int shiftLength, std::string areaOfField, std::string ID); // adds a new nurse
    void addNewDoctor(std::string name, int age, std::string contactNo, std::string employeeID, std::string department, std::string position, std::string qualifications, int experienceYears, std::string specialisation); // adds a new doctor

    void addAppointmentRequest(Appointment* appointment); // adds a new appointment request
    void approveAppointment(Appointment* appointment, double price); // approves an appointment
};

#endif
