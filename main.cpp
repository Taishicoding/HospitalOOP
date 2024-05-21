#include <iostream>
#include <string>
#include "Hospital.h"
#include "Person.h"
#include "Patient.h"
#include "Appointment.h"
#include "MedStaff.h"
#include "Nurse.h"
#include "Doctor.h"

using namespace std; 

//Input and output on the terminal.

int main(){

    //Initialise Hospital
    int numPatients = 500; 
    int numStaff = 60; 
    Hospital hospital = Hospital(numPatients, numStaff); 
    Patient** patientsArray = hospital.getPatientArray();  
    Employee** employeesArray = hospital.getEmployeesArray();  
    Appointment** appointmentsArray = hospital.getAppointmentArray();  
    int numAppointments = hospital.getCurrentNumAppointments(); 

    //Initialise input variable. 
    int modeSelector = 0;

    cout << "Welcome!" << endl; 

//Loop program infinitely using while loop
while (modeSelector == 0){

    //Prompt the user for mode (patient or hospital staff)
    cout << "Enter 1 for Patient, 2 for Doctor, or 3 for Staff: "; 
    cin >> modeSelector; 

    //Invalid mode untit valid input. 
    while ((modeSelector != 1) && (modeSelector != 2) && (modeSelector != 3)){

        cout << "Invalid input. Please select 1 for Patient, 2 for Appointment, or 3 for Staff: "; 
        cin >> modeSelector; 

    } 

    //Patient 
    if (modeSelector == 1){

        //Request patient's intent
        int patientMode; 
        cout << "To set an appointment, select 1; To access personal information, select 2; To settle payment, select 3: "; 
        cin >> patientMode; 

        while ((patientMode != 1) && (patientMode != 2) && (patientMode != 3)){

            cout << "Invalid input. To set an appointment, select 1; To access personal information, select 2; To settle payment, select 3: "; 
            cin >> patientMode; 

        } 

        //Request patient ID
        std::string userID; 
        cout << "Enter your patient ID: "; 
        cin >> userID; 

        //Reference ID to array of patients in hospital. 
        Patient patientObject;
        int a = 0;
        while (a == 0){ 

            for (int i = 0; i < (hospital.getCurrentPatients() - 1); i++){
                if (patientsArray[i]->getPatientID() == userID){
                    patientObject = *(patientsArray[i]); 
                    break;
                }
                else {
                    a = 0; 
                }
            }
            cout << "Invalid ID. Enter your patient ID: "; 
            cin >> userID; 
        }

        //set up appointment 
        if (patientMode == 1){

            //Request details
            std::string needs, dateAndTime, newAppID; 

            cout << "Enter reasons for appointment request: "; 
            cin >> needs; 

            cout << "Enter preferred date and time of appointment: "; 
            cin >> dateAndTime; 

            cout << "Enter unique appointment ID: "; 
            cin >> newAppID; 

            Appointment appointment(&patientObject, needs, dateAndTime, newAppID); 
            hospital.addAppointmentRequest(&appointment); 

        }

        //accessing info 
        else if (patientMode == 2){

            //Print patient info. 
            patientObject.printInfo();

            //Ask if user wants to settle any outstanding payments. 
            if (patientObject.getOutstandingBalance() > 0){

                cout << "To settle payments enter 1, otherwise, enter 2: "; 
                cin >> patientMode; 

                if (patientMode == 1){
                    patientObject.setOutstandingBalance(0); 
                    cout << "Payment settled."<< endl; 
                }
            }
        }

        //paying
        else if (patientMode == 3){
            if (patientObject.getOutstandingBalance() > 0){
                
                cout << "To settle payments enter 1, otherwise, enter 2: "; 
                cin >> patientMode; 

                if (patientMode == 1){
                    patientObject.setOutstandingBalance(0); 
                    cout << "Payment settled."<< endl; 
                }
            }
            else {
                cout << "No outstanding payments." << endl; 
            }
        } 

        //To restart program. 
        modeSelector = 0; 
    }

    //Appointment
    else if (modeSelector == 2){

        //Enter appointment ID to access patient
        std::string userID; 
        cout << "Enter appointment ID: "; 
        cin >> userID; 

        //Reference ID to array of appointments in hospital. 
        Appointment appointmentObject;
        Patient patientObject; 
        int b = 0;
        while (b == 0){ 

            for (int i = 0; i < (hospital.getCurrentNumAppointments() - 1); i++){
                if (appointmentsArray[i]->getAppointmentID() == userID){
                    appointmentObject = *(appointmentsArray[i]); 
                    patientObject = *(appointmentObject.getPatientPtr()); 
                    break;
                }
                else {
                    b = 0; 
                }
            }
            cout << "Invalid ID. Enter appointment ID: "; 
            cin >> userID; 
        }

        cout << "Appointment commenced."; 

        //call for patient information
        cout << "Patient information: " << endl; 
        patientObject.printInfo();
         
        //give doctor option to add info to patient file 
        int append; 
        cout << "Enter 1 to alter symptoms; Enter 2 to alter diagnosis; Enter 3 to alter Treatments; Otherwise, enter 3: "; 
        cin >> append; 

        while ((append != 1) && (append != 2) && (append != 3) && (append != 4)){

            cout << "Invalid input." << endl << "Enter 1 to alter symptoms; Enter 2 to alter diagnosis; Enter 3 to alter Treatments; Otherwise, enter 3: "; 
            cin >> append; 

        } 

        if (append == 1) {
            std::string newSymptoms; 

            cout << "Symptoms: "; 
            cin >> newSymptoms; 

            patientObject.setSymptoms(newSymptoms); 
        }
        else if (append == 2) {
            std::string newDiagnosis; 

            cout << "Diagnosis: "; 
            cin >> newDiagnosis; 

            patientObject.setDiagnosis(newDiagnosis); 

        }
        else if (append == 3) {
            std::string newTreatments;  

            cout << "Treatments: "; 
            cin >> newTreatments; 

            patientObject.setTreatments(newTreatments); 

        }

        //Print price of appointment & add unsettled payment to patient file
        cout << appointmentObject.getAppointmentPrice() << endl; 
        double newBalance = appointmentObject.getAppointmentPrice(); 
        double oldBalance = patientObject.getOutstandingBalance(); 
        patientObject.setOutstandingBalance(oldBalance + newBalance); 

        //To restart program. 
        modeSelector = 0; 
    }

    //Hospital staff
    else if (modeSelector == 3) {

        //Request staff's intent. 
        int staffMode; 
        cout << "To access personal information, select 1; To add new employee, select 2; To add new patient, select 3; To approve an appointment, select 4: "; 
        cin >> staffMode; 

        while ((staffMode != 1) && (staffMode != 2) && (staffMode != 3) && (staffMode != 4)){

            cout << "Invalid input. To access personal information, select 1; To add new employee, select 2; To add new patient, select 3; To approve an appointment, select 4: "; 
            cin >> staffMode; 

        }

        //for personal information
        if (staffMode == 1) {
            //Enter staff ID
            std::string userID; 
            cout << "Enter your patient ID: "; 
            cin >> userID; 

            //Reference ID to array of employees in hospital. 
            Employee employeeObject;
            int a = 0;
            while (a == 0){ 

                for (int i = 0; i < (hospital.getCurrentEmployees() - 1); i++){
                    if (employeesArray[i]->getEmployeeID() == userID){
                        employeeObject = *(employeesArray[i]); 
                        break;
                    }
                    else {
                        a = 0; 
                    }
                }
                cout << "Invalid ID. Enter your patient ID: "; 
                cin >> userID; 
            }

            employeeObject.printInfo(); 
        }
        
        //adding employee
        else if (staffMode == 2) {

            //Ask employee type
            cout << "To add general employee, select 1" << endl; 
            cout << "To add general medical staff, select 2" << endl; 
            cout << "To add nurse, select 3" << endl; 
            cout << "To add doctor, select 4" << endl; 
            cin >> staffMode; 

            while ((staffMode != 1) && (staffMode != 2) && (staffMode != 3) && (staffMode != 4)){

                cout << "Invalid input." << endl; 
                cout << "To add general employee, select 1" << endl; 
                cout << "To add general medical staff, select 2" << endl; 
                cout << "To add nurse, select 3" << endl; 
                cout << "To add doctor, select 4" << endl; 
                cin >> staffMode; 
            }

            if (staffMode == 1) {
                //Initialise general employee information 
                std::string name, contact, ID, department, position; 
                int age; 

                cout << "Enter new patient's details." << endl; 
                cout << "Name: "; 
                cin >> name; 

                cout << "Age: "; 
                cin >> age; 

                cout << "Contact No.: "; 
                cin >> contact; 

                cout << "Unique ID: "; 
                cin >> ID; 

                cout << "Department: "; 
                cin >> department; 

                cout << "Position: "; 
                cin >> position; 

                //Call addNewEmployee
                hospital.addNewEmployee(name, age, contact, ID, department, position); 

            }
            else if (staffMode == 2) {
                //Initialise general medical staff information 
                std::string name, contact, ID, department, position, qualifications; 
                int age, yearsExperience; 

                cout << "Enter new patient's details." << endl; 
                cout << "Name: "; 
                cin >> name; 

                cout << "Age: "; 
                cin >> age; 

                cout << "Contact No.: "; 
                cin >> contact; 

                cout << "Unique ID: "; 
                cin >> ID; 

                cout << "Department: "; 
                cin >> department; 

                cout << "Position: "; 
                cin >> position; 

                cout << "Qualifications: "; 
                cin >> qualifications; 

                cout << "Years of Experience: "; 
                cin >> yearsExperience; 

                //Call addNewMedStaff
                hospital.addNewMedStaff(name, age, contact, ID, department, position, qualifications, yearsExperience); 
            }
            else if (staffMode == 3) {
                //Initialise nurse information 
                std::string name, contact, ID, department, position, qualifications, field; 
                int age, yearsExperience, shiftLength; 

                cout << "Enter new patient's details." << endl; 
                cout << "Name: "; 
                cin >> name; 

                cout << "Age: "; 
                cin >> age; 

                cout << "Contact No.: "; 
                cin >> contact; 

                cout << "Unique ID: "; 
                cin >> ID; 

                cout << "Department: "; 
                cin >> department; 

                cout << "Position: "; 
                cin >> position; 

                cout << "Qualifications: "; 
                cin >> qualifications; 

                cout << "Years of Experience: "; 
                cin >> yearsExperience; 

                cout << "Default Shift Length: "; 
                cin >> shiftLength; 

                cout << "Field: "; 
                cin >> field; 

                //Call addNewNurse
                //hospital.addNewNurse(name, age, contact, ID, department, position, qualifications, yearsExperience, shiftLength, field); 
            }
            else if (staffMode == 4) {
                //Initialise doctor information 
                std::string name, contact, ID, department, position, qualifications, specialisation; 
                int age, yearsExperience; 

                cout << "Enter new patient's details." << endl; 
                cout << "Name: "; 
                cin >> name; 

                cout << "Age: "; 
                cin >> age; 

                cout << "Contact No.: "; 
                cin >> contact; 

                cout << "Unique ID: "; 
                cin >> ID; 

                cout << "Department: "; 
                cin >> department; 

                cout << "Position: "; 
                cin >> position; 

                cout << "Qualifications: "; 
                cin >> qualifications; 

                cout << "Years of Experience: "; 
                cin >> yearsExperience; 

                cout << "Specialisations: ";
                cin >> specialisation; 

                //Call addNewDoctor
                hospital.addNewDoctor(name, age, contact, ID, department, position, qualifications, yearsExperience, specialisation); 
            }
        }

        //adding patient 
        else if (staffMode == 3) {

            //Initialise patient information. 
            std::string newPatientName, newPatientContact, newPatientID; 
            int newPatientAge; 

            cout << "Enter new patient's details." << endl; 
            cout << "Name: "; 
            cin >> newPatientName; 

            cout << "Age: "; 
            cin >> newPatientAge; 

            cout << "Contact No.: "; 
            cin >> newPatientContact; 

            cout << "Unique ID: "; 
            cin >> newPatientID; 

            //Call addNewPatient function. 
            hospital.addNewPatient(newPatientName, newPatientAge, newPatientContact, newPatientID); 

        }

        //approve appointment
        else if (staffMode == 4){

            //Request ID
            std::string appID; 
            cout << "Enter appointment ID: "; 
            cin >> appID; 

            //Find ID in array of appointments. 
            Appointment appointmentObject;
            int c = 0;
            while (c == 0){ 

                for (int i = 0; i < (hospital.getCurrentNumAppointments() - 1); i++){
                    if (appointmentsArray[i]->getAppointmentID() == appID){
                        appointmentObject = *(appointmentsArray[i]); 
                        break;
                    }
                    else {
                        c = 0; 
                    }
                }
                cout << "Invalid ID. Enter appointment ID: "; 
                cin >> appID; 
            }

            //Print appointment info for booking. 
            appointmentObject.printInfo(); 

            //Set price. 
            double price; 
            cout << "Enter price of appointment: "; 
            cin >> price; 

            //Call approveAppointment function
            hospital.approveAppointment(&appointmentObject, price); 

        }

    }

    //To restart program. 
    modeSelector = 0; 

}

return 0; 

}