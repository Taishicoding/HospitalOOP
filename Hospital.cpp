#include "Hospital.h"

//Constructors. 
Hospital::Hospital(){}; 

Hospital::Hospital(int numPatients, int numStaff){
    
    currentPatients = 0;
    currentAppointments = 0; 
    currentEmployees = 0; 

    patientCapacity = numPatients; 
    staffCapacity = numStaff; 

    patients = new Patient*[patientCapacity];  
    appointments = new Appointment*[5000]; 
    employees = new Employee*[staffCapacity]; 
} 

//Member functions
Patient** Hospital::getPatientArray(){ return patients;}; 
Appointment** Hospital::getAppointmentArray(){ return appointments;}; 
Employee** Hospital::getEmployeesArray(){ return employees;}; 
int Hospital::getCurrentNumAppointments(){ return currentAppointments;}

void Hospital::addNewPatient(std::string name, int age, std::string contact, std::string ID){

    //Initialise Patient object. 
    Patient newPatient(name, age, contact, ID); 

    //Add new patient to patients array. 
    patients[currentPatients] = &newPatient; 

    //Increment current number of patients. 
    currentPatients++; 

   cout << "New patient added." << endl; 
}

void Hospital::addNewEmployee(std::string name, int age, std::string contactNo, std::string ID, std::string department, std::string position){
    
    Employee newEmployee(name, age, contactNo, employeeID, department, position);  
    employees[currentEmployees] = &newEmployee; 
    currentEmployees++;
    cout << "New employee added."; 

}
void Hospital::addNewMedStaff(std::string name, int age, std::string contactNo, std::string ID, std::string department, std::string position, std::string qualifications, int experienceYears){
    MedStaff newMedStaff(name, age, contactNo, employeeID, department, position, qualifications, experienceYears);  
    employees[currentEmployees] = &newMedStaff; 
    currentEmployees++; 
    cout << "New medical staff added."; 
}
void Hospital::addNewNurse(std::string name, int age, std::string contactNo, std::string employeeID, std::string department, std::string position, std::string qualifications, int experienceYears, int shiftLength, std::string areaOfField, std::string ID){
    Nurse newNurse(name, age, contactNo, employeeID, department, position, qualifications, experienceYears, shiftLength, areaOfField);  
    employees[currentEmployees] = &newNurse; 
    currentEmployees++; 
    cout << "New nurse added."; 
} 
void Hospital::addNewDoctor(std::string name, int age, std::string contactNo, std::string employeeID, std::string department, std::string position, std::string qualifications, int experienceYears, std::string specialisation){
    Doctor newDoctor(name, age, contactNo, employeeID, department, position, qualifications, experienceYears, specialisation);  
    employees[currentEmployees] = &newDoctor; 
    currentEmployees++; 
    cout << "New doctor added."; 
}

void Hospital::addAppointmentRequest(Appointment* newAppointment){

    appointments[currentAppointments] = newAppointment; 
    currentAppointments++; 
    cout << "Appointment requested. You will receive a call to book your appointment in less than 3 hours. Thank you." << endl; 

}

void Hospital::approveAppointment(Appointment* requestedAppointment, double price){ 

    requestedAppointment->setAppointmentPrice(price); 

}

int Hospital::getCurrentPatients(){ return currentPatients;}
int Hospital::getCurrentEmployees(){ return currentEmployees;} 