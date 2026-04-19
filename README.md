Overview

This is an Object-Oriented Programming (OOP) design for a basic hospital management system.
It demonstrates how inheritance can be used to model real-world relationships, starting from a general Person class and extending into more specialized roles like Doctor and Nurse.

Base Class: Person
name
age
contactInfo
Level 1: Employee (inherits from Person)

Additional Attributes:

employeeID
department
salary
Level 2: MedicalStaff (inherits from Employee)

Additional Attributes:

qualifications
yearsOfExperience
Level 3: Specialized Roles
Doctor (inherits from MedicalStaff)

Additional Attributes:

specialisation
patientList
Nurse (inherits from MedicalStaff)

Additional Attributes:

shifts
tasks
Visual Hierarchy
Person
└── Employee
    └── MedicalStaff
        ├── Doctor
        └── Nurse
