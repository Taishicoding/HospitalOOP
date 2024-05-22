terminal: Hospital.cpp Patient.cpp Employee.cpp Person.cpp Appointment.cpp MedStaff.cpp Nurse.cpp Doctor.cpp HospitalSystem.cpp main.cpp 
	clang++ -std=c++11 Hospital.cpp Patient.cpp Employee.cpp Person.cpp Appointment.cpp MedStaff.cpp Nurse.cpp Doctor.cpp HospitalSystem.cpp main.cpp -o interface
	./interface

unit testing: 


clear: 
	rm -f interface
