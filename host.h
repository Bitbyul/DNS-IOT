#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <netdb.h>
#include <arpa/inet.h>

/*
struct hostent
{
  char *h_name;			// Official name of host.
  char **h_aliases;		// Alias list.
  int h_addrtype;		// Host address type.
  int h_length;			// Length of address.
  char **h_addr_list;		// List of addresses from name server.
};
*/

class HostEntry {

    std::string h_name_;			// Official name of host.
    std::vector<std::string> h_aliases_;		// Alias list.
    int h_addrtype_;		// Host address type.
    int h_length_;			// Length of address.
    std::vector< std::shared_ptr<char> > h_addr_list_;		// List of addresses from name server.
    int hit_count_;			// DNS Query hit coun
    std::time_t last_updated_time_ = -1; // Last updated time from external DNS Server.

public:
    friend class HostBuilder;

    std::string as_str();
    
    std::string name();
    const std::vector< std::shared_ptr<char> >& addr_list();
    const std::vector<std::string>& aliases();
    
};

/*
    For builder pattern
*/
class HostBuilder {
    std::shared_ptr<HostEntry> pHost_;

public:
    HostBuilder();

    HostBuilder& name(const char *);
    //HostBuilder& aliases(char **);
    HostBuilder& addrtype(int);
    HostBuilder& addr_length(int);
    //HostBuilder& addr_list(char **);
    HostBuilder& hit_count(int);
    HostBuilder& last_updated_time(std::time_t);

    HostBuilder& add_alias(const char *);
    HostBuilder& add_addr(const char *);

    HostBuilder& from_hostent(struct hostent*);

    std::shared_ptr<HostEntry> build();
};
