#include "DB.h"


DB::DB() {
    driver = get_driver_instance();
    con = driver->connect(server, username, password);
    con->setSchema("medicaldatabase");       //Set the database name
}

DB* DB::getInstance() {
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

sql::Connection* DB::connection() {
    return con;
}

sql::PreparedStatement* DB::getPreparedStatement(std::string sql) {
    return con->prepareStatement(sql);
}

sql::Statement* DB::getCreateStatement() {
    return con->createStatement();
}