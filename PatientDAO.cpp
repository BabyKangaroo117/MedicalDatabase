#include "PatientDAO.h"

void PatientDAO::insert(Patient patient) {

    DB* db = DB::getInstance();
    try {
        std::string sql = "INSERT INTO patient_info(first_name, last_name, insurance_name, policy_number, phone_number, birthdate, ssn) VALUES(?,?,?,?,?,?,?)";
        pstmt = db->getPreparedStatement(sql);
        pstmt->setString(1, patient.getFirstName());
        pstmt->setString(2, patient.getLastName());
        std::cout << patient.getLastName();
        pstmt->setString(3, patient.getInsuranceName());
        pstmt->setString(4, patient.getPolicyNumber());
        pstmt->setInt(5, patient.getPhoneNumber());
        pstmt->setInt(6, patient.getBirthdate());
        pstmt->setInt(7, patient.getSSN());
        pstmt->execute();
        /*
        std::cout << rowInserted << std::endl;
        if (rowInserted > 0) {
           std::cout << "A new patient was inserted" << std::endl;
        }
        */
        delete pstmt;
    }
    catch (sql::SQLException e) {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
    }

}