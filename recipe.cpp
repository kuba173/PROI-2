#include "recipe.h"
#include <string>

////////////////////////////////////////////////////////////////////////////////////


Medicine::Medicine(const std::string& name, const std::string& active_substance, float price): name(name), active_substance(active_substance), price(price){}

const std::string& Medicine::getName() const {
return name;
}

void Medicine::setName(const std::string& value) {
name = value;
}

const std::string& Medicine::getActiveSubstance() const {
return active_substance;
}

void Medicine::setActiveSubstance(const std::string& value) {
active_substance = value;
}

float Medicine::getPrice() const{
return price;
}

void Medicine::setPrice(float value) {
price = value;
}

/////////////////////////////////////////////////

Prescription::Prescription(uint16_t number, const std::string& date, const std::string& doctor_name, const std::string& patient_name, uint64_t patient_pesel, const std::vector<Medicine>& medicines): number(number), date(date), doctor_name(doctor_name),patient_name(patient_name), patient_pesel(patient_pesel), medicines(medicines){}

uint16_t Prescription::getNumber() {
return number;
}

void Prescription::setNumber(uint16_t value) {
number = value;
}

const std::string& Prescription::getDate() const {
return date;
}

void Prescription::setDate(const std::string& value) {
date = value;
}

const std::string& Prescription::getDoctorFullName() const {
return doctor_name;
}

void Prescription::setDoctorFullName(const std::string& value) {
doctor_name = value;
}

const std::string& Prescription::getPatientFullName() const {
return patient_name;
}

void Prescription::setPatientFullName(const std::string& value) {
patient_name = value;
}

uint64_t Prescription::getPatientPesel() {
return patient_pesel;
}

void Prescription::setPatientPesel(uint64_t value) {
patient_pesel = value;
}

const std::vector<Medicine>& Prescription::getMedicines() const {
return medicines;
}

void Prescription::setMedicines(const std::vector<Medicine>& value) {
medicines = value;
}




bool is_valid_date(uint16_t year, int month, int day) {
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int days_in_month;

    switch (month) {
        case 2:
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                days_in_month = 29;
            } else {
                days_in_month = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days_in_month = 30;
            break;
        default:
            days_in_month = 31;
    }

    return day <= days_in_month;
}
