#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <memory>
#include <pqxx/pqxx>

class Database
{
public:
    ~Database() { unsetConnection(); }
    
    void setupConnection(std::string &options);
    void unsetConnection();
    
private:
    std::unique_ptr<pqxx::connection> conn = nullptr;
};

#endif // DATABASE_H
