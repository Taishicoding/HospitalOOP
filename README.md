Three Levels of Inheritance:
Base Class: Person{
    name
    age
    contact info
}
//1. Employee {
    Inherits from Person
    New Stuff:
        Employee ID
        Department
        Salary
}
//2. Medical Staff {
    Inherits from Employee
    New stuff:
        qualifications
        years of experience
}
//3. Doctor {
    Inherits from Medical Staff
    New stuff:
        specilisation
        patient list
}
//3. Nurse {
    Inherits from Medical Staff
    New stuff:
        shifts
        tasks
}