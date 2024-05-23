#include <iostream>
#include "Hospital.h"
#include "Patient.h"
#include "Person.h"
#include "Doctor.h"
#include "Nurse.h"
#include "MedStaff.h"
#include "Appointment.h"
class UnitTest {
private:

    void testAddNewPatient() {
        Hospital hospital(10, 10);
        hospital.addNewPatient("Alice", 30, "1234567890", "P1");
        if (hospital.getCurrentPatients() != 1) {
            std::cout << "Test AddNewPatient failed!" << std::endl;
        }
        else {
            std::cout <<"Unit Test 1 Passed" << std::endl;
        }
    }
    void testAddNewDoctor() {
        Hospital hospital(10, 10);
        hospital.addNewDoctor("Dr. Bob", 45, "9876543210", "D1", "Cardiology", "Head Doctor", "MD", 20, "Cardiology");

        if (hospital.getCurrentEmployees() != 1) {
            std::cout << "Test AddNewDoctor failed!" << std::endl;
        }
        else {
            std::cout <<"Unit Test 2 Passed" << std::endl;
        }
    }
    void testFindEmployeeByID() {
        Hospital hospital(10, 10);
        hospital.addNewDoctor("Dr. Bob", 45, "9876543210", "D1", "Cardiology", "Head Doctor", "MD", 20, "Cardiology");
        Employee* doctor = hospital.getEmployeesArray()[0];

        if (doctor->getEmployeeID() != "D1") {
            std::cout << "Test FindEmployeeByID failed!" << std::endl;
        }
        else {
            std::cout <<"Unit Test 3 Passed" << std::endl;
        }
    }
    void testSetGetSymptoms() {
        Patient patient("Alice", 30, "1234567890", "P1");
        patient.setSymptoms("Cough");

        if (patient.getSymptoms()[0] != "Cough") {
            std::cout << "Test SetGetSymptoms failed!" << std::endl;
        }
        else {
            std::cout <<"Unit Test 4 Passed" << std::endl;
        }
    }
    void testSetGetDiagnosis() {
        Patient patient("Alice", 30, "1234567890", "P1");
        patient.setDiagnosis("Flu");

        if (patient.getDiagnosis() != "Flu") {
            std::cout << "Test SetGetDiagnosis failed!" << std::endl;
        }
        else {
            std::cout <<"Unit Test 5 Passed" << std::endl;
        }
    }
    void testSetGetTreatments() {
        Patient patient("Alice", 30, "1234567890", "P1");
        patient.setTreatments("Rest");

        if (patient.getTreatments()[0] != "Rest") {
            std::cout << "Test SetGetTreatments failed!" << std::endl;
        }
        else {
            std::cout <<"Unit Test 6 Passed" << std::endl;
        }
    }

public:
    void runTests() {
        testAddNewPatient();
        testAddNewDoctor();
        testFindEmployeeByID();
        testSetGetSymptoms();
        testSetGetDiagnosis();
        testSetGetTreatments();
    }
};
