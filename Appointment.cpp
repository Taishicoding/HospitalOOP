#include "Appointment.h"

Appointment::Appointment(){
    appointmentID = "0"; 
} 

Appointment::Appointment(Patient* patient, std::string needs, std::string date_time, std::string appID){
    ptrPatient = patient; 
    patientNeeds = needs; 
    dateAndTime = date_time;
    appointmentID = appID; 
    appointmentPrice = 0;  
} 

Patient* Appointment::getPatientPtr(){
    return ptrPatient; 
}

std::string Appointment::getAppointmentID(){
    return appointmentID; 
}

int Appointment::getAppointmentPrice(){
    return appointmentPrice; 
}

void Appointment::setAppointmentPrice (double price){
    appointmentPrice = price; 

    cout << "Price set." << endl; 
}

void Appointment::printInfo(){

    Patient patient = *ptrPatient; 

    //Patient information 
    cout << "Patient Information: " << endl << patient.getInfo() << endl; 

    //Appointment information. 
    cout << "Appointment Information: " << appointmentID << endl << patientNeeds << endl << dateAndTime << appointmentPrice << endl; 

} 

Appointment::~Appointment(){}