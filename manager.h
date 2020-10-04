#include <mutex>
#include <memory>
#include <vector>

#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class HostRepository;
class HostEntry;

class Manager {

    static constexpr int kBufferSize = 50;

    static std::mutex mutex_;
    static Manager* instance_; // for singleton pattern

    std::shared_ptr<HostRepository> pRepo_;

    int serv_sock;
    int clnt_sock;
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;
    int received_length;
    char message_buffer[kBufferSize];

    Manager(); // hide default constructor

public:
    static Manager& get_instance();

    static void signal_handler(int signum);

    bool start_listen();
    void destroy();

};