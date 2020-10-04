#include <iostream>
#include <csignal>

#include "manager.h"
#include "tools/logger.h"

using namespace std;

void signal_handler(int signum) {
    std::cout << signum << " received\n";
}

int main(int argc, char** argv){
    Logger::i("Started Domain Name Server service.");
    
    auto manager = Manager::get_instance();
    
    signal(SIGINT, Manager::signal_handler); // SIGINT 핸들러 등록

    if( manager.start_listen() == false )
        Logger::e("Server has encountered a problem. shutdown...");

    return 0;
}