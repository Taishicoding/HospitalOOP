#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include "Patient.h"
#include "Employee.h"
#include "MedStaff.h"
#include "Nurse.h"
#include "Doctor.h"
#include "Appointment.h"

using namespace std; 

class Hospital : protected Patient, protected Appointment, protected Employee {

private:

    //Array of pointers to corresponding types. 
    Patient** patients; 
    Appointment** appointments; 
    Employee** employees; 

    int currentPatients; 
    int currentAppointments; 
    int currentEmployees;  
    int patientCapacity; 
    int staffCapacity; 

public:

    //Constructors.  
    Hospital(); 
    Hospital(int numPatients, int numStaff); 

    Patient** getPatientArray(); 
    Appointment** getAppointmentArray(); 
    Employee** getEmployeesArray(); 

    void addNewPatient(std::string name, int age, std::string contact, std::string ID); 
    void addNewEmployee(std::string name, int age, std::string contactNo, std::string ID, std::string department, 
            std::string position); 
    void addNewMedStaff(std::string name, int age, std::string contactNo, std::string ID, std::string department, 
            std::string position, std::string qualifications, int experienceYears); 
    void addNewNurse(std::string name, int age, std::string contactNo, std::string employeeID, std::string department,
            std::string position, std::string qualifications, int experienceYears, int shiftLength, std::string areaOfField, 
            std::string ID); 
    void addNewDoctor(std::string name, int age, std::string contactNo, std::string employeeID, std::string department,
            std::string position, std::string qualifications, int experienceYears, std::string specialisation); 

    int getCurrentNumAppointments(); 
    void addAppointmentRequest(Appointment* newAppointment); 
    void approveAppointment(Appointment* requestedAppointment, double price); 

    int getCurrentPatients(); 
    int getCurrentEmployees(); 

};
#endif