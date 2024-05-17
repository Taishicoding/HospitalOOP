#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Patient.h"
#include "MedStaff.h"
#include "Appointment.h"

class Hospital : protected Patient, protected Appointment, protected MedStaff {

private:

    //Array of pointers to corresponding types. 
    Patient** patients; 
    Appointment** appointments; 
    MedStaff** staff; 

    int patientCapacity; 
    int staffCapacity; 

public:

    //Constructors. 
    Hospital(); 
    Hospital(int numPatients, int numStaff); 

    Patient** getPatientArray(); 
    Appointment** getAppointmentArray(); 
    MedStaff** getStaffArray(); 

};
#endif