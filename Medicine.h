#ifndef MEDICINE_H
#define MEDICINE_H
#include <string>
class Medicine{
private:
    std::string medicineID;
    std::string medicineName;
    std::string description;
    std::string dosage;
    int stock;
public:
    Medicine(); 
    Medicine(const std::string& id, const std::string& name, const std::string& desc, const std::string& dos, int stk);
    std::string getMedicineID() const;
    std::string getMedicineName() const;
    std::string getDescription() const;
    std::string getDosage() const;
    int getStock() const;
    void setMedicineID(const std::string& id);
    void setMedicineName(const std::string& name);
    void setDescription(const std::string& desc);
    void setDosage(const std::string& dos);
    void setStock(int stk);
    void dispenseMedicine(int quantity); 
};
#endif
