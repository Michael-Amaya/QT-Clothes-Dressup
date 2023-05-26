#include "database_postgres.h"
#include <string>
#include <iostream>
#include "libpq-fe.h"
 
DatabasePostgres::DatabasePostgres(std::string dbString) : dbString{dbString},dbConnected(false){
    this->connect();
}

DatabasePostgres::~DatabasePostgres() {
    if (this->dbConnected){ 
        PQfinish(this->connection);
    }
}

bool DatabasePostgres::connect() {
    this->connection = PQconnectdb(this->dbString.c_str());
    if (PQstatus(this->connection) != CONNECTION_OK) {
        // Throw some error
        // TODO: Create exception for when database fails to connect.
        return false;
    }

    this->dbConnected = true;
    return this->dbConnected;
}

ClotheClassifiers DatabasePostgres::getClassifiers() {
    PGresult* result = PQexec(this->connection, "SELECT classifier FROM classifiers;");
    if(PQresultStatus(result) != PGRES_TUPLES_OK) {
        // Throw some error
        // TODO: Create exception for when database fails to query.

    }

    ClotheClassifiers toReturn{};

    for(size_t i = 0; i < PQntuples(result); i++) {
        toReturn.addClassifier(std::string(PQgetvalue(result, i, 0)));
    }

    PQclear(result);
    return toReturn;
}