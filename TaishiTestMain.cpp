#include <iostream>
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Medicine.h"
#include "MedStaff.h"
#include "Employee.h"

int main() {
    Person person("Michael", 35, "987654321");
    std::cout << "Person Details:\n";
    person.printInfo();
    std::cout << std::endl;
    Employee employee("Susan", 33, "098767890", "ASD11223", "West Ward", "Doctor");
    std::cout << "Employee Details:\n";
    employee.printInfo();
    std::cout << std::endl;
    MedStaff medstaff("Greg", 40, "8765434567", "5647389238476", "East End", "Nurse", "Senior Nurse", 10);
    std::cout << "MedStaff Details:\n";
    medstaff.printInfo();
    std::cout << std::endl;
    Patient patient("Jane", 28, "123456789", 1002);
    patient.setDiagnosis("Awaiting diagnosis");
    patient.setSymptoms("Cough");
    patient.setTreatments("Pending doctor's review");
    std::cout << "Patient Details:\n";
    patient.printInfo();
    std::cout << std::endl;
    Doctor doctor("Dr. Craig", 45, "12345612345", "DR001", "Cardiology", "Doctorate", "Cardiology Specialist", 15, "Surgeon");
    doctor.addPatient("Jane");
    std::cout << "Doctor Details:\n";
    doctor.printInfo();
    std::cout << std::endl;
    Nurse nurse("Susy", 20, "564783", "727", "Department 1", "Head Nurse", "Nursing", 5, 10, "General Ward");
    nurse.addRole("Patient care");
    std::cout << "Nurse Details:\n";
    nurse.printInfo();
    std::cout << std::endl;
    Medicine medicine("MED001", "Paracetamol", "Used to reduce fever and relieve pain", "500mg", 50);
    std::cout << "Medicine Details:\n";
    std::cout << "Medicine ID: " << medicine.getMedicineID() << std::endl;
    std::cout << "Medicine Name: " << medicine.getMedicineName() << std::endl;
    std::cout << "Description: " << medicine.getDescription() << std::endl;
    std::cout << "Dosage: " << medicine.getDosage() << std::endl;
    std::cout << "Stock: " << medicine.getStock() << std::endl;
    medicine.dispenseMedicine(10);
    std::cout << "Stock after dispensing 10 units: " << medicine.getStock() << std::endl;
    return 0;
}
