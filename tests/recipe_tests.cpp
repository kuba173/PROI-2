#include "catch_amalgamated.hpp"
#include "../recipe.h"


TEST_CASE("Test Prescription class") {
    
    Prescription prescription(123, "2023-04-01", "Dr. John Smith", "Dwayn Rock", 12345678901, {Medicine("Medicine A", "Substance A", 10.0), Medicine("Medicine B", "Substance B", 20.0)});
    SECTION("Test constructor and getter methods") {

    
        CHECK(prescription.getNumber() == 123);
        CHECK(prescription.getDate() == "2023-04-01");
        CHECK(prescription.getDoctorFullName() == "Dr. John Smith");
        CHECK(prescription.getPatientFullName() == "Dwayn Rock");
        CHECK(prescription.getPatientPesel() == 12345678901);
    
        const std::vector<Medicine>& medicines = prescription.getMedicines();
        CHECK(medicines.size() == 2);
        CHECK(medicines[0].getName() == "Medicine A");
        CHECK(medicines[0].getActiveSubstance() == "Substance A");
        CHECK(medicines[0].getPrice() == 10.0);
        CHECK(medicines[1].getName() == "Medicine B");
        CHECK(medicines[1].getActiveSubstance() == "Substance B");
        CHECK(medicines[1].getPrice() == 20.0);
    }
    
    SECTION("Test setter methods") {
        prescription.setNumber(456);
        prescription.setDate("2023-04-02");
        prescription.setDoctorFullName("Dr. Beluga Rock");
        prescription.setPatientFullName("Will Smith");
        prescription.setPatientPesel(98765432101);
        prescription.setMedicines({Medicine("Medicine C", "Substance C", 30.0)});

        CHECK(prescription.getNumber() == 456);
        CHECK(prescription.getDate() == "2023-04-02");
        CHECK(prescription.getDoctorFullName() == "Dr. Beluga Rock");
        CHECK(prescription.getPatientFullName() == "Will Smith");
        CHECK(prescription.getPatientPesel() == 98765432101);

        const std::vector<Medicine>& new_medicines = prescription.getMedicines();
        CHECK(new_medicines.size() == 1);
        CHECK(new_medicines[0].getName() == "Medicine C");
        CHECK(new_medicines[0].getActiveSubstance() == "Substance C");
        CHECK(new_medicines[0].getPrice() == 30.0);
    }
  
}
TEST_CASE("Test Medicine class") {
    
    Medicine medicine("Medicine A", "Substance A", 10.0);
    
    SECTION("Test constructor and getter methods") {
        CHECK(medicine.getName() == "Medicine A");
        CHECK(medicine.getActiveSubstance() == "Substance A");
        CHECK(medicine.getPrice() == 10.0);
    }
    
    SECTION("Test setter methods") {
        medicine.setName("Medicine B");
        medicine.setActiveSubstance("Substance B");
        medicine.setPrice(20.0);

        CHECK(medicine.getName() == "Medicine B");
        CHECK(medicine.getActiveSubstance() == "Substance B");
        CHECK(medicine.getPrice() == 20.0);
    }
  
}