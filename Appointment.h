#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class Appointment {
private:
    std::string appointmentID;
    std::string date;
    std::string time; 
    std::string patientID;
    std::string doctorID; 
    std::string description; 

public:
    Appointment(const std::string& id, const std::string& date, const std::string& time,
                const std::string& patientID, const std::string& doctorID, const std::string& description);
    std::string getAppointmentID() const;
    std::string getDate() const;
    std::string getTime() const;
    std::string getPatientID() const;
    std::string getDoctorID() const;
    std::string getDescription() const;
    void setDate(const std::string& newDate);
    void setTime(const std::string& newTime);
    void setDescription(const std::string& newDescription);
    void printInfo() const;
};

#endif 
