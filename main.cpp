#include <iostream>
#include "Hospital.h"
#include "Patient.h"

using namespace std; 

//Input and output on the terminal.

int main(){

    //Initialise Hospital
    int numPatients = 500; 
    int numStaff = 60; 
    Hospital hospital = Hospital(numPatients, numStaff); 

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

        cout << "Invalid input. Please select 1 for Patient, 2 for Doctor, or 3 for Staff: "; 
        cin >> modeSelector; 

    } 

    //Patient 
    if (modeSelector == 1){

        //Request patient's intent
        int patientMode; 
        cout << "To set an appointment, select 1; To access information, select 2; To settle payment, select 3: "; 
        cin >> patientMode; 

        while ((patientMode != 1) && (patientMode != 2) && (patientMode != 3)){

            cout << "Invalid input. To set an appointment, select 1; To access information, select 2; To settle payment, select 3: "; 
            cin >> patientMode; 

        } 

        //Request patient ID
        int userID; 
        cout << "Enter your patient ID: "; 
        cin >> userID; 

        //Reference ID to array of patients in hospital. 
        Patient** patientsArray = hospital.getPatientArray();  
        Patient patientObject;
        int a = 0;
        while (a == 0){ 

            for (int i = 0; i < (numPatients - 1); i++){
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

        //set up appointment  ????
        if (patientMode == 1){


            //doctor of which specialty?
            //at what time?
            //initialise appointment class 

        }

        //accessing info 
        else if (patientMode == 2){

            //Print patient info. 
            patientObject.printInfo();
            
            //Ask if user wants to alter information. 
            cout << "To alter information enter 1, otherwise, enter 2: "; 
            cin >> patientMode; 

            if (patientMode == 1) {
                //Call changePatientInfo function that uses if-loop. 
            }

            //Ask if user wants to settle any outstanding payments. 
            if (patientObject.getOutstandingBalance() > 0){

                cout << "To settle payments enter 1, otherwise, enter 2: "; 
                cin >> patientMode; 

                if (patientMode == 1){
                    //call settlePayment function. 
                }
            }
        }

        //paying
        else if (patientMode == 3){
            if (patientObject.getOutstandingBalance() > 0){
                
                cout << "To settle payments enter 1, otherwise, enter 2: "; 
                cin >> patientMode; 

                if (patientMode == 1){
                    //call settlePayment function. 
                }
            }
            else {
                cout << "No outstanding payments." << endl; 
            }
        } 

        //To restart program. 
        modeSelector = 0; 
    }

    //Doctor
    else if (modeSelector == 2){

        //Request appointment ID 
        int appointmentID; 
        cout << "Enter appointment ID: "; 
        cin >> appointmentID; 


        //call for patient information


        //give doctor option to add info to patient file (changePatientInfo)


        //Print price of appointment & add unsettled payment to patient file

        //Jump to patient mode for payment

        //To restart program. 
        modeSelector = 0; 
    }

    //Hospital staff (general)
    else if (modeSelector == 3) {

        //Enter staff ID

        //Print info (next shift, department, etc. )

        //To restart program. 
        modeSelector = 0; 
    }
    }

    return 0; 
}