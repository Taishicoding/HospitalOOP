#include "HospitalSystem.h"
#include <iostream>

using namespace std;

HospitalSystem::HospitalSystem() : hospital(500, 60) {
    // initialize some test cases, useful if user doesn't create new patient etc
    hospital.addNewPatient("Taishi", 19, "123456789", "1");
    hospital.addNewPatient("Tatiana", 20, "987654321", "2");

    hospital.addNewDoctor("Dr. Nadeem", 25, "5555555555", "D1", "Cardiology", "Head Doctor", "MD, PhD", 20, "Cardiology");
    hospital.addNewDoctor("Dr. OOP", 50, "4444444444", "D2", "Neurology", "Consultant", "MD", 25, "Neurology");

    Appointment* appointment1 = new Appointment(hospital.getPatientArray()[0], "Checkup", "2023-06-01 10:00", "A1");
    hospital.addAppointmentRequest(appointment1);
    hospital.approveAppointment(appointment1, 100.0);

    Appointment* appointment2 = new Appointment(hospital.getPatientArray()[1], "Consultation", "2023-06-02 14:00", "A2");
    hospital.addAppointmentRequest(appointment2);
    hospital.approveAppointment(appointment2, 200.0);
}

// runs the hospital system
void HospitalSystem::run() {
    int modeSelector = 0;
    cout << "Welcome!" << endl;
    // loop program infinitely using while loop
    while (true) {
        cout << "Enter 1 for Patient, 2 for Doctor, or 3 for Staff: "; // prompt the user for mode (patient, doctor, or hospital staff)
        cin >> modeSelector;
        // invalid mode until valid input
        while ((modeSelector != 1) && (modeSelector != 2) && (modeSelector != 3)) {
            cout << "Invalid input. Please select 1 for Patient, 2 for Doctor, or 3 for Staff: ";
            cin >> modeSelector;
        }
        // switch between modes based on user input
        try {
            switch (modeSelector) {
                case 1:
                    patientMode();
                    break;
                case 2:
                    doctorMode();
                    break;
                case 3:
                    staffMode();
                    break;
                default:
                    break;
            }
        } catch (const std::invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
}

// handles patient mode
void HospitalSystem::patientMode() {
    int patientMode; // request patient's intent
    cout << "To set an appointment, select 1; To access personal information, select 2; To settle payment, select 3: ";
    cin >> patientMode;

    while ((patientMode != 1) && (patientMode != 2) && (patientMode != 3)) {
        cout << "Invalid input. To set an appointment, select 1; To access personal information, select 2; To settle payment, select 3: ";
        cin >> patientMode;
    }

    // reference ID to array of patients in hospital
    string userID;
    cout << "Enter your patient ID: ";
    cin >> userID;

    Patient patientObject = findPatientByID(userID);

    switch (patientMode) {
        case 1:
            setAppointment(patientObject);
            break;
        case 2:
            accessPatientInfo(patientObject);
            break;
        case 3:
            settlePayment(patientObject);
            break;
        default:
            break;
    }
}

// handles doctor mode
void HospitalSystem::doctorMode() {
    string appID;
    cout << "Enter appointment ID: ";
    cin >> appID;

    Appointment* appointmentObject = findAppointmentByID(appID);  // use pointer
    if (!appointmentObject) {
        throw std::invalid_argument("Invalid appointment ID");
    }
    Patient patientObject = *(appointmentObject->getPatientPtr());

    cout << "Appointment commenced." << endl;
    cout << "Patient information: " << endl;
    patientObject.printInfo();

    int append;
    cout << "Enter 1 to alter symptoms; Enter 2 to alter diagnosis; Enter 3 to alter Treatments; Otherwise, enter 4: ";
    cin >> append;

    while ((append != 1) && (append != 2) && (append != 3) && (append != 4)) {
        cout << "Invalid input." << endl << "Enter 1 to alter symptoms; Enter 2 to alter diagnosis; Enter 3 to alter Treatments; Otherwise, enter 4: ";
        cin >> append;
    }

    string newInfo;
    switch (append) {
        case 1:
            cout << "Symptoms: ";
            cin >> newInfo;
            patientObject.setSymptoms(newInfo);
            break;
        case 2:
            cout << "Diagnosis: ";
            cin >> newInfo;
            patientObject.setDiagnosis(newInfo);
            break;
        case 3:
            cout << "Treatments: ";
            cin >> newInfo;
            patientObject.setTreatments(newInfo);
            break;
        default:
            break;
    }

    double newBalance = appointmentObject->getAppointmentPrice();
    double oldBalance = patientObject.getOutstandingBalance();
    patientObject.setOutstandingBalance(oldBalance + newBalance);

    cout << appointmentObject->getAppointmentPrice() << endl;
}

// handles staff mode
void HospitalSystem::staffMode() {
    int staffMode;
    cout << "To access personal information, select 1; To add new employee, select 2; To add new patient, select 3; To approve an appointment, select 4: ";
    cin >> staffMode;

    while ((staffMode != 1) && (staffMode != 2) && (staffMode != 3) && (staffMode != 4)) {
        cout << "Invalid input. To access personal information, select 1; To add new employee, select 2; To add new patient, select 3; To approve an appointment, select 4: ";
        cin >> staffMode;
    }

    switch (staffMode) {
        case 1:
            {
                string userID;
                cout << "Enter your staff ID: ";
                cin >> userID;

                Employee employeeObject = findEmployeeByID(userID);
                employeeObject.printInfo();
            }
            break;
        case 2:
            addNewEmployee();
            break;
        case 3:
            addNewPatient();
            break;
        case 4:
            {
                string appID;
                cout << "Enter appointment ID: ";
                cin >> appID;

                Appointment* appointmentObject = findAppointmentByID(appID);  // use pointer
                if (!appointmentObject) {
                    throw std::invalid_argument("Invalid appointment ID");
                }
                appointmentObject->printInfo();

                double price;
                cout << "Enter price of appointment: ";
                cin >> price;

                hospital.approveAppointment(appointmentObject, price);
            }
            break;
        default:
            break;
    }
}

// sets an appointment for patient
void HospitalSystem::setAppointment(Patient& patientObject) {
    string needs, dateAndTime, newAppID;

    cout << "Enter reasons for appointment request: ";
    cin >> needs;

    cout << "Enter preferred date and time of appointment: ";
    cin >> dateAndTime;

    cout << "Enter unique appointment ID: ";
    cin >> newAppID;

    Appointment* appointment = new Appointment(&patientObject, needs, dateAndTime, newAppID);  // allocate on heap
    hospital.addAppointmentRequest(appointment);
}

// accesses patient info
void HospitalSystem::accessPatientInfo(Patient& patientObject) {
    patientObject.printInfo();
    if (patientObject.getOutstandingBalance() > 0) {
        int settle;
        cout << "To settle payments enter 1, otherwise, enter 2: ";
        cin >> settle;

        if (settle == 1) {
            patientObject.setOutstandingBalance(0);
            cout << "Payment settled." << endl;
        }
    }
}

// settles payment for patient
void HospitalSystem::settlePayment(Patient& patientObject) {
    if (patientObject.getOutstandingBalance() > 0) {
        int settle;
        cout << "To settle payments enter 1, otherwise, enter 2: ";
        cin >> settle;

        if (settle == 1) {
            patientObject.setOutstandingBalance(0);
            cout << "Payment settled." << endl;
        }
    } else {
        cout << "No outstanding payments." << endl;
    }
}

// adds a new employee
void HospitalSystem::addNewEmployee() {
    int employeeType;
    cout << "To add general employee, select 1" << endl;
    cout << "To add general medical staff, select 2" << endl;
    cout << "To add nurse, select 3" << endl;
    cout << "To add doctor, select 4" << endl;
    cin >> employeeType;

    while ((employeeType != 1) && (employeeType != 2) && (employeeType != 3) && (employeeType != 4)) {
        cout << "Invalid input." << endl;
        cout << "To add general employee, select 1" << endl;
        cout << "To add general medical staff, select 2" << endl;
        cout << "To add nurse, select 3" << endl;
        cout << "To add doctor, select 4" << endl;
        cin >> employeeType;
    }

    std::string name, contact, ID, department, position, qualifications, field, specialisation;
    int age, yearsExperience, shiftLength;

    cout << "Enter employee's details." << endl;
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

    switch (employeeType) {
        case 1:
            hospital.addNewEmployee(name, age, contact, ID, department, position);
            break;
        case 2:
            cout << "Qualifications: ";
            cin >> qualifications;
            cout << "Years of Experience: ";
            cin >> yearsExperience;
            hospital.addNewMedStaff(name, age, contact, ID, department, position, qualifications, yearsExperience);
            break;
        case 3:
            cout << "Qualifications: ";
            cin >> qualifications;
            cout << "Years of Experience: ";
            cin >> yearsExperience;
            cout << "Default Shift Length: ";
            cin >> shiftLength;
            cout << "Field: ";
            cin >> field;
            hospital.addNewNurse(name, age, contact, ID, department, position, qualifications, yearsExperience, shiftLength, field, ID);
            break;
        case 4:
            cout << "Qualifications: ";
            cin >> qualifications;
            cout << "Years of Experience: ";
            cin >> yearsExperience;
            cout << "Specialisations: ";
            cin >> specialisation;
            hospital.addNewDoctor(name, age, contact, ID, department, position, qualifications, yearsExperience, specialisation);
            break;
        default:
            break;
    }
}

// adds a new patient
void HospitalSystem::addNewPatient() {
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

    hospital.addNewPatient(newPatientName, newPatientAge, newPatientContact, newPatientID);
}

// finds patient by id
Patient HospitalSystem::findPatientByID(const std::string& userID) {
    Patient** patientsArray = hospital.getPatientArray();
    for (int i = 0; i < hospital.getCurrentPatients(); ++i) {
        if (patientsArray[i]->getPatientID() == userID) {
            return *(patientsArray[i]);
        }
    }
    throw std::invalid_argument("Invalid patient ID");
}

// finds appointment by id
Appointment* HospitalSystem::findAppointmentByID(const std::string& appID) {
    Appointment** appointmentsArray = hospital.getAppointmentArray();
    for (int i = 0; i < hospital.getCurrentNumAppointments(); ++i) {
        if (appointmentsArray[i]->getAppointmentID() == appID) {
            return appointmentsArray[i];
        }
    }
    throw std::invalid_argument("Invalid appointment ID");
}

// finds employee by id
Employee HospitalSystem::findEmployeeByID(const std::string& userID) {
    Employee** employeesArray = hospital.getEmployeesArray();
    for (int i = 0; i < hospital.getCurrentEmployees(); ++i) {
        if (employeesArray[i]->getEmployeeID() == userID) {
            return *(employeesArray[i]);
        }
    }
    throw std::invalid_argument("Invalid employee ID");
}
