#ifndef PATIENTDAO_H_
#define PATIENTDAO_H_

#include <vector>
#include "Patient.h"
#include "DB.h"
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <iostream>


class PatientDAO {
private:
    sql::PreparedStatement* pstmt;

public:
    void insert(Patient patient);
};

#endif