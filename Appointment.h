#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include "Patient.h"

using namespace std; 

class Appointment {

protected: 

    Patient* ptrPatient; 
    std::string patientNeeds, dateAndTime, appointmentID; 
    double appointmentPrice; 

public: 

    Appointment(); 
    Appointment(Patient* patient, std::string needs, std::string date_time, std::string appID); 


    Patient* getPatientPtr(); 
    std::string getAppointmentID(); 
    int getAppointmentPrice(); 

    void setAppointmentPrice (double price); 
    void printInfo(); 

    ~Appointment(); 

};




#endif