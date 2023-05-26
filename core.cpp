#include <QApplication>
#include <sstream>
#include <iostream>

#include "main_window.h"
#include "config_reader.h"
#include "database_postgres.h"

int main(int argc, char** argv) {
    /* QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */
    
    // Connection string format: "user=username password=password host=127.0.0.1 port=5432 dbname=db_name"
    ConfigReader reader("config.txt");
    std::stringstream dbInfoSS{};
    dbInfoSS << "user=" << reader.getConfig("username") << \
        " password=" << reader.getConfig("password") << \
        " host=" << reader.getConfig("host") << \
        " port=" << reader.getConfig("port") << \
        " dbname=" << reader.getConfig("database");
    // std::cout << dbInfoSS.str() << std::endl;
    DatabasePostgres db{dbInfoSS.str()};
    std::cout << db.getClassifiers().getClassifierString() << std::endl;


    
    return 0;
}