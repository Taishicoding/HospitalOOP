#include "Hospital.h"
#include <iostream>

// Constructors
Hospital::Hospital() {}

Hospital::Hospital(int numPatients, int numStaff) {
    // Initialize counters
    currentPatients = 0;
    currentAppointments = 0;
    currentEmployees = 0;

    // Set capacities
    patientCapacity = numPatients;
    staffCapacity = numStaff;

    // Allocate memory for arrays
    patients = new Patient*[patientCapacity];
    appointments = new Appointment*[5000]; // up to 5000 appointments
    employees = new Employee*[staffCapacity];
}

// Destructor
Hospital::~Hospital() {
    // Deallocate memory for patients
    for (int i = 0; i < currentPatients; ++i) {
        delete patients[i];
    }
    delete[] patients;

    // Deallocate memory for appointments
    for (int i = 0; i < currentAppointments; ++i) {
        delete appointments[i];
    }
    delete[] appointments;

    // Deallocate memory for employees
    for (int i = 0; i < currentEmployees; ++i) {
        delete employees[i];
    }
    delete[] employees;
}

// Getters
Patient** Hospital::getPatientArray() {
    return patients;
}

Appointment** Hospital::getAppointmentArray() {
    return appointments;
}

Employee** Hospital::getEmployeesArray() {
    return employees;
}

int Hospital::getCurrentPatients() const {
    return currentPatients;
}

int Hospital::getCurrentEmployees() const {
    return currentEmployees;
}

int Hospital::getCurrentNumAppointments() const {
    return currentAppointments;
}

// Add a new patient
void Hospital::addNewPatient(std::string name, int age, std::string contact, std::string ID) {
    if (currentPatients < patientCapacity) {
        patients[currentPatients] = new Patient(name, age, contact, ID);
        currentPatients++;
        std::cout << "New patient added." << std::endl;
    } else {
        std::cout << "Patient capacity reached, cannot add more patients." << std::endl;
    }
}

// Add a new general employee
void Hospital::addNewEmployee(std::string name, int age, std::string contactNo, std::string ID, std::string department, std::string position) {
    if (currentEmployees < staffCapacity) {
        employees[currentEmployees] = new Employee(name, age, contactNo, ID, department, position);
        currentEmployees++;
        std::cout << "New employee added." << std::endl;
    } else {
        std::cout << "Employee capacity reached, cannot add more employees." << std::endl;
    }
}

// Add a new medical staff member
void Hospital::addNewMedStaff(std::string name, int age, std::string contactNo, std::string ID, std::string department, std::string position, std::string qualifications, int experienceYears) {
    if (currentEmployees < staffCapacity) {
        employees[currentEmployees] = new MedStaff(name, age, contactNo, ID, department, position, qualifications, experienceYears);
        currentEmployees++;
        std::cout << "New medical staff added." << std::endl;
    } else {
        std::cout << "Employee capacity reached, cannot add more medical staff." << std::endl;
    }
}

// Add a new nurse
void Hospital::addNewNurse(std::string name, int age, std::string contactNo, std::string employeeID, std::string department, std::string position, std::string qualifications, int experienceYears, int shiftLength, std::string areaOfField, std::string ID) {
    if (currentEmployees < staffCapacity) {
        employees[currentEmployees] = new Nurse(name, age, contactNo, employeeID, department, position, qualifications, experienceYears, shiftLength, areaOfField);
        currentEmployees++;
        std::cout << "New nurse added." << std::endl;
    } else {
        std::cout << "Employee capacity reached, cannot add more nurses." << std::endl;
    }
}

// Add a new doctor
void Hospital::addNewDoctor(std::string name, int age, std::string contactNo, std::string employeeID, std::string department, std::string position, std::string qualifications, int experienceYears, std::string specialisation) {
    if (currentEmployees < staffCapacity) {
        employees[currentEmployees] = new Doctor(name, age, contactNo, employeeID, department, position, qualifications, experienceYears, specialisation);
        currentEmployees++;
        std::cout << "New doctor added." << std::endl;
    } else {
        std::cout << "Employee capacity reached, cannot add more doctors." << std::endl;
    }
}

// Add a new appointment request
void Hospital::addAppointmentRequest(Appointment* appointment) {
    if (currentAppointments < 5000) {
        appointments[currentAppointments] = appointment;
        currentAppointments++;
    } else {
        std::cout << "Appointment capacity reached, cannot add more appointments." << std::endl;
    }
}

// Approve an appointment
void Hospital::approveAppointment(Appointment* appointment, double price) {
    appointment->setAppointmentPrice(price);
    std::cout << "Appointment approved." << std::endl;
}
