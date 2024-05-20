#include "Medicine.h"
Medicine::Medicine() : medicineID("APTX4869"), medicineName("アポトキシン"), description("一切の毒物反応を残さず生物を死亡させる"), dosage("1 Pill"), stock(10) {}
Medicine::Medicine(const std::string& id, const std::string& name, const std::string& desc, const std::string& dos, int stk)
    : medicineID(id), medicineName(name), description(desc), dosage(dos), stock(stk) {}
std::string Medicine::getMedicineID() const {
    return medicineID;
}
std::string Medicine::getMedicineName() const {
    return medicineName;
}
std::string Medicine::getDescription() const {
    return description;
}
std::string Medicine::getDosage() const {
    return dosage;
}
int Medicine::getStock() const {
    return stock;
}
void Medicine::setMedicineID(const std::string& id) {
    medicineID = id;
}
void Medicine::setMedicineName(const std::string& name) {
    medicineName = name;
}
void Medicine::setDescription(const std::string& desc) {
    description = desc;
}
void Medicine::setDosage(const std::string& dos) {
    dosage = dos;
}
void Medicine::setStock(int stk) {
    stock = stk;
}
void Medicine::dispenseMedicine(int quantity) {
    if (quantity > 0 && stock >= quantity) {
        stock -= quantity;
    }
}
