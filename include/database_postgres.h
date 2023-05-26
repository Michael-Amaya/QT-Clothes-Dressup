#include <string>
#include "libpq-fe.h"
#include "database_system.h"

class DatabasePostgres : public DatabaseSystem {
private:
    PGconn* connection;
    std::string dbString;
    bool dbConnected;
public:
    DatabasePostgres(std::string dbString);
    ~DatabasePostgres();

    bool connect() override;
    ClotheClassifiers getClassifiers() override;
};