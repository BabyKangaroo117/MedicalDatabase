#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "DB.h"
#include "PatientDAO.h"
#include "Patient.h"

using namespace std;
DB *DB::instance_ptr = NULL;


int main()
{
    PatientDAO patientDAO;
    
    DB *db = DB::getInstance();

    sql::Statement* stmt;


    stmt = db->getCreateStatement();
    stmt->execute("DROP TABLE IF EXISTS patient_info");
    cout << "Finished dropping table (if existed)" << endl;
    stmt->execute("CREATE TABLE patient_info (id serial PRIMARY KEY, first_name VARCHAR(20), last_name VARCHAR(20), insurance_name VARCHAR(30), policy_number VARCHAR(30), phone_number Integer, birthdate Integer, ssn Integer);");
    cout << "Finished creating table" << endl;
    delete stmt;
    
    Patient patient("Joseph", "Porrino", "Aetna", "sfeagsadfas", 2156751234, 8271998, 124321);
    patientDAO.insert(patient);
    
    Patient patient_2("John", "Porrino", "Aetna", "sfeagsadfas", 2154341234, 8271998, 124321);
    patientDAO.insert(patient_2);
    
    delete db->connection();
    system("pause");
    return 0;
}