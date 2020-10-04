#include <unordered_map>
#include <memory>
#include <mutex>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

constexpr auto kDBURL = "tcp://127.0.0.1:3306";
constexpr auto kDBUsername = "dns-iot";
constexpr auto kDBPassword = "dnS200930#";
constexpr auto kDBScheme = "dns_iot";

enum PoolState{
    IDLE,
    USED
};

class ConnectionPool {
    std::unordered_map< std::shared_ptr<sql::Connection>, PoolState > pool_;
    sql::Driver* driver_;
    std::mutex mutex_;

public:
    ConnectionPool(int numConnection);
    std::shared_ptr<sql::Connection> get_connection();
    void release_connection(std::shared_ptr<sql::Connection> pCon);
};