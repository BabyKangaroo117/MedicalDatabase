#ifndef _DB_H_
#define _DB_H_

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include <string>


class DB {
private:
    const std::string server = "localhost";
    const std::string username = "root";
    const std::string password = "Enter password here";
    static DB* instance_ptr;

    sql::Driver* driver;
    sql::Connection* con;

    DB();

public:
    DB(const DB& obj) = delete;
    static DB* getInstance();
    sql::Connection* connection();
    sql::PreparedStatement* getPreparedStatement(std::string sql);
    sql::Statement* getCreateStatement();
};

#endif