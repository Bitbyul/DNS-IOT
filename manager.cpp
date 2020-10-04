#include "manager.h"

#include "tools/logger.h"
#include "tools/datatype.h"
#include "host.h"
#include "database/HostRepository.h"

using namespace std;

mutex Manager::mutex_;
Manager* Manager::instance_ = nullptr;

/*
    Manager 생성자
    싱글턴 패턴으로 인해 최초 1번만 호출
*/
Manager::Manager() : serv_sock(0), clnt_sock(0), pRepo_(new HostRepository) {
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(7143);

}

/*
    싱글턴 패턴 인스턴스 가져오기
*/
Manager& Manager::get_instance(){

    unique_lock<mutex> lk(mutex_); // 상호 배제
    if(instance_==nullptr) {
        instance_ = new Manager();
    }
    lk.unlock();

    return *instance_;
}

/*
    네트워크 대기 시작
*/
bool Manager::start_listen(){

    Logger::i("Preparing to listen...");

    serv_sock=socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock==-1){
        Logger::e("socket() error.");
        return false;
    }

    if(bind(serv_sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr))==-1){
	    Logger::e("bind() error");
        return false;
    }

    if(listen(serv_sock,5)==-1){
        Logger::e("listen() error");
        return false;
    }
    
    Logger::i("IP: ", inet_ntoa(serv_addr.sin_addr), " / Port: ", ntohs(serv_addr.sin_port));
    Logger::i("Listening...");

    while (1) {
        clnt_addr_size=sizeof(clnt_addr);
        clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_size);

        Logger::i("Client<", inet_ntoa(clnt_addr.sin_addr), "> connected.");

        //데이터 수신및 전송 //
        while((received_length=read(clnt_sock,message_buffer, kBufferSize))!=0)
        {
            HostBuilder host_builder;
            message_buffer[received_length-1] = '\0';
            Logger::i("Received query: ", message_buffer);

            if ( DataType::is_ipaddr(message_buffer) ) {
                // IP 주소로부터 알아오기

                auto host_entry = pRepo_->getByIP(message_buffer);
                if (host_entry != nullptr) {

                    Logger::i("Cache hit!!");
                    std::cout << "----- Host Info -----\n" << host_entry->as_str() << "\n";
                } else {

                    struct hostent * host;
                    struct sockaddr_in addr;
                    
                    memset( & addr, 0, sizeof(addr));
                    addr.sin_addr.s_addr = inet_addr(message_buffer);

                    host = gethostbyaddr((char * ) & addr.sin_addr, 4, AF_INET);

                    if (!host) {
                        Logger::e("Cannot get host by IP Address");
                        write(clnt_sock, "Cannot get host by IP Address", 30);
                        break;
                    }

                    auto now = std::chrono::system_clock::now();
                    std::time_t t = std::chrono::system_clock::to_time_t(now);
                    
                    std::cout << "----- Host Info -----\n" << host_builder.from_hostent(host).last_updated_time(t).build()->as_str() << "\n";
                }

                write(clnt_sock, "IP", 3);

            } else {
                // 도메인 이름으로부터 알아오기

                auto host_entry = pRepo_->getByDomain(message_buffer);
                if (host_entry != nullptr) {

                    Logger::i("Cache hit!!");
                    std::cout << "----- Host Info -----\n" << host_entry->as_str() << "\n";
                } else {

                    struct hostent * host;
                    struct in_addr myinaddr; //IP 주소를 저장할 구조체 

                    host = gethostbyname(message_buffer);

                    if (!host) {
                        Logger::e("Cannot get host by Domain Name");
                        write(clnt_sock, "Cannot get host by Domain Name", 31);
                        break;
                    }

                    auto now = std::chrono::system_clock::now();
                    std::time_t t = std::chrono::system_clock::to_time_t(now);
                    
                    std::cout << "----- Host Info -----\n" << host_builder.from_hostent(host).last_updated_time(t).build()->as_str() << "\n";
                }
                write(clnt_sock, "Domain", 7);
                
            }
        }

        Logger::i("Client<", inet_ntoa(clnt_addr.sin_addr), "> disconnected.");

        //close(clnt_sock);
    }
    return true;
}

void Manager::signal_handler(int signum){

    if (signum == 2){ // SIGINT
        std::cout << "SIGINT received\n";
        Manager::get_instance().destroy();
        exit(signum);
    }
}

void Manager::destroy(){
    Logger::i("Destroying...");
    close(serv_sock);
    close(clnt_sock);

    pRepo_->save_dns_table_to_db();

    Logger::i("Destroyed.");
}
