#ifndef _DB_H_
#define _DB_H_
#include "DB.h"

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
    const std::string password = "Enter mysql password here";
    static DB *instance_ptr;

    sql::Driver *driver;
    sql::Connection *con;

    DB() {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema("medicaldatabase");       //Set the database name
    }

public:
    DB(const DB& obj) = delete;

    static DB* getInstance() {
        if (instance_ptr == NULL) {
            try {
                instance_ptr = new DB();
            }
            catch (sql::SQLException e) {
                std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
                system("pause");
                exit(1);
            }
            return instance_ptr;
        }
        else {
            return instance_ptr;
        }

    }

    sql::Connection* connection() {
        return con;
    }

    sql::PreparedStatement *getPreparedStatement(std::string sql) {
        return con->prepareStatement(sql);
    }

    sql::Statement* getCreateStatement() {
        return con->createStatement();
    }
};

#endif