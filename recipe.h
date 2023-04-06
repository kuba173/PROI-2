#pragma once
#include <string>
#include <vector>
#include <iostream>

class Medicine {

public:
    Medicine(const std::string& name, const std::string& active_substance, float price);

    const std::string& getName() const;
    void setName(const std::string& name);

    const std::string& getActiveSubstance() const;
    void setActiveSubstance(const std::string& active_substance);

    float getPrice() const;
    void setPrice(float price);

private:
    std::string name;
    std::string active_substance;
    float price;

};

class Prescription {
public:
    Prescription(uint16_t number, const std::string& date, const std::string& doctor_name,
        const std::string& patient_name,uint64_t patient_pesel, const std::vector<Medicine>& medicines);

    uint16_t getNumber();
    void setNumber(uint16_t number);

    const std::string& getDate() const;
    void setDate(const std::string& date);

    const std::string& getDoctorFullName() const;
    void setDoctorFullName(const std::string& doctor_name);

    const std::string& getPatientFullName() const;
    void setPatientFullName(const std::string& patient_name);

    uint64_t getPatientPesel();
    void setPatientPesel(uint64_t patient_pesel);

    const std::vector<Medicine>& getMedicines() const;
    void setMedicines(const std::vector<Medicine>& medicines);

 
private:
    uint16_t number;
    std::string date;
    std::string doctor_name;
    std::string patient_name;
    uint64_t patient_pesel;
    std::vector<Medicine> medicines;
};
/////////////////////////////////////////////////////////////////////////////////////////////////
bool is_valid_date(uint16_t year, int month, int day);  // i know that i can use uint8_t 

