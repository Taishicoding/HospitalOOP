#include "Hospital.h"

//Constructors. 
Hospital::Hospital(){}; 

Hospital::Hospital(int numPatients, int numStaff){
    
    patientCapacity = numPatients; 
    staffCapacity = numStaff; 

    patients = new Patient*[patientCapacity]; 
    appointments = new Appointment*[5000]; 
    staff = new MedStaff*[staffCapacity]; 
} 

//Member functions
Patient** Hospital::getPatientArray(){ return patients;}; 
Appointment** Hospital::getAppointmentArray(){ return appointments;}; 
MedStaff** Hospital::getStaffArray(){ return staff;}; 