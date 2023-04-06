#include <iostream>
#include <vector>
#include <string>
#include "recipe.h"
#include <limits>


int main() {

    // variables 
    uint16_t number,year;
    std::string date, doctorFullName, patientFullName;

    uint64_t patientPesel;

    std::vector<Medicine> medicines;

    bool valid_date = false;
    int day, month; // i know that i can use uint8_t 
   
    float price;

   
    std::cout << "Enter prescription data:" << std::endl;
    while (true) {
        std::cout << "Number: ";
        if (std::cin >> number) {
            break;
        }
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    //////////////////////////////////////data

 
    while (!valid_date) {
        std::cout << "Enter year: ";
        if (std::cin >> year) {
            std::cout << "Enter month: ";
            if (std::cin >> month) {
                std::cout << "Enter day: ";
                if (std::cin >> day) {
                    valid_date = is_valid_date(year, month, day);
                    if (!valid_date) {
                        std::cout << "Invalid date. Please try again." << std::endl;
                    } else {
        
                    date = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
        
                    }
                } else {
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } else {
                std::cout << "Invalid input. Please enter a number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } else {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    ///////////////////////////////////////data end

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "Doctor's full name: ";
    std::getline(std::cin, doctorFullName);
    std::cout << "Patient's full name: ";
    std::getline(std::cin, patientFullName);
    
    while (true) {
        std::cout << "Patient's PESEL: ";
        if (std::cin >> patientPesel) {
            break;
        }
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    ///////////////////////////////////////// medicines data 
    std::cout << "Enter medicines data (name, active substance, price) - enter 'q' to finish:" << std::endl;
    std::string medicineName, activeSubstance;
    
    while (true) {
        std::cout << "Medicine name: ";
        std::getline(std::cin, medicineName);
        if (medicineName == "q") {
            break;
        }
        std::cout << "Active substance: ";
        std::getline(std::cin, activeSubstance);
        
        while (true) {
            std::cout << "Price: ";
            if (std::cin >> price) {
                break;
            }

            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        medicines.push_back(Medicine(medicineName, activeSubstance, price));
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    ////////////////////////////////////////////////////
 
    Prescription prescription(number, date, doctorFullName, patientFullName, patientPesel, medicines);

    // print data////////////////////////////////////////////////
    std::cout << std::endl << "=================================================================" << std::endl;
    std::cout << std::endl << "Prescription data:" << std::endl;
    std::cout << "Number: " << prescription.getNumber() << std::endl;
    std::cout << "Date: " << prescription.getDate() << std::endl;
    std::cout << "Doctor's full name: " << prescription.getDoctorFullName() << std::endl;
    std::cout << "Patient's full name: " << prescription.getPatientFullName() << std::endl;
    std::cout << "Patient's PESEL: " << prescription.getPatientPesel() << std::endl;
    std::cout << "Medicines:" << std::endl;
    for (const auto& medicine : prescription.getMedicines()) {
        std::cout << "- Name: " << medicine.getName() << ", active substance: " << medicine.getActiveSubstance() << ", price: " << medicine.getPrice() << " PLN" << std::endl;
    }
    std::cout << std::endl << "=================================================================" << std::endl;
    return 0;
}
