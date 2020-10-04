#include <memory>
#include <vector>
#include <string>

class ConnectionPool;
class HostEntry;

class HostRepository {

    static constexpr int kMaxConnection = 5;

    std::shared_ptr<ConnectionPool> pConPool_;

    std::vector<std::shared_ptr<HostEntry>> cached_host_list_;
public:

    HostRepository();

    void db_test();
    int load_dns_table_from_db();
    int save_dns_table_to_db();

    HostEntry* const getByDomain(std::string);
    HostEntry* const getByIP(std::string);
};