#include "datatype.h"

namespace DataType {

    bool is_ipaddr(const char* str) {
        struct sockaddr_in sa;
        int result = inet_pton(AF_INET, str, &(sa.sin_addr));
        
        return result != 0;
    }
};