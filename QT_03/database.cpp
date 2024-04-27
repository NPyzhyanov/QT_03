#include <string>
#include <memory>
#include <pqxx/pqxx>

#include "database.h"

void Database::setupConnection(std::string &options)
{
    try
    {
        if (conn == nullptr)
        {
            conn = std::make_unique<pqxx::connection>(options);
        }
        else
        {
            auto new_connection = std::make_unique<pqxx::connection>(options);
            conn.swap(new_connection);
        }
    }
    catch (...)
    {
        throw std::invalid_argument("Incorrect setup options");
    }
}


void Database::unsetConnection()
{
    conn->close();
    conn.release();
}
