#include "host.h"
#include "tools/logger.h"

using namespace std;

std::string HostEntry::as_str() {
    ostringstream ss;

    //호스트 이름 출력
    ss << "official host name : " << h_name_ << "\n";

    //호스트 별명 출력
    ss << "aliases name :\n";
    for(auto iter = h_aliases_.begin(); iter != h_aliases_.end(); iter++) {
        ss << "\t" << *iter << "\n";
    }

    //호스트 주소체계 출력
    ss << "host address type : " << (h_addrtype_ == AF_INET ? "AF_INET" : "AF_INET6") << "\n";

    //호스트 주소 길이 출력
    ss << "length of host address : " << h_length_ << "\n";

    //호스트 주소를 dotted decimal 형태로 출력 
    struct in_addr myinaddr; //IP 주소를 저장할 구조체 
    ss << "addresses for host :\n";
    for(auto iter = h_addr_list_.begin(); iter != h_addr_list_.end(); iter++) {
        myinaddr.s_addr = * (u_long * )((*iter).get());  // IPv4 only
        ss << "\t" << * (u_long * )((*iter).get());
        ss << "\t" << inet_ntoa(myinaddr) << "\n";
    }
    
    //캐시된 시간 출력
    ss << "Cached time : " << std::put_time(std::localtime(&last_updated_time_), "%F %T %z") << "\n";

    return ss.str();
}

std::string HostEntry::name() {
    return h_name_;
}

const std::vector< std::shared_ptr<char> >& HostEntry::addr_list() {
    return h_addr_list_;
}

const std::vector<std::string>& HostEntry::aliases() {
    return h_aliases_;
}

HostBuilder::HostBuilder() : pHost_(new HostEntry()) {
}

HostBuilder& HostBuilder::name(const char * str) {
    pHost_->h_name_ = str;
    return *this;
}

HostBuilder& HostBuilder::addrtype(int type) {
    pHost_->h_addrtype_ = type;
    return *this;
}

HostBuilder& HostBuilder::addr_length(int length) {
    pHost_->h_length_ = length;
    return *this;
}

HostBuilder& HostBuilder::hit_count(int count) {
    pHost_->hit_count_ = count;
    return *this;
}

HostBuilder& HostBuilder::last_updated_time(time_t t) {
    pHost_->last_updated_time_ = t;
    return *this;
}

HostBuilder& HostBuilder::add_alias(const char * str) {
    pHost_->h_aliases_.push_back(str);
    return *this;
}

HostBuilder& HostBuilder::add_addr(const char * str) {

    shared_ptr<char> pAddr(new char[16], std::default_delete<char[]>()); // reserved for IPv6
    fill(pAddr.get(), pAddr.get()+16, 0);
    auto a = inet_addr(str);

    Logger::i("ㅋㅋ:", a);

    memcpy(pAddr.get(), &a, sizeof(in_addr_t)); // IPv4 only

    pHost_->h_addr_list_.push_back(pAddr);

    return *this;
}

HostBuilder& HostBuilder::from_hostent(struct hostent* legacy_host) {

    pHost_->h_name_ = legacy_host->h_name;

    int i = 0;
    while (legacy_host->h_aliases[i] != NULL) {
        pHost_->h_aliases_.push_back(legacy_host->h_aliases[i]);
        i++;
    }
    //host_.h_aliases_ = legacy_host->h_aliases;
    pHost_->h_addrtype_ = legacy_host->h_addrtype;
    pHost_->h_length_ = legacy_host->h_length;
    i = 0;
    while (legacy_host->h_addr_list[i] != NULL) {

        shared_ptr<char> pAddr(new char[16], std::default_delete<char[]>()); // reserved for IPv6
        fill(pAddr.get(), pAddr.get()+16, 0);
        memcpy(pAddr.get(), (struct in_addr * )legacy_host->h_addr_list[i], sizeof(in_addr_t)); // IPv4 only

        pHost_->h_addr_list_.push_back(pAddr);
        i++;
    }
    //host_.h_addr_list_ = legacy_host->h_addr_list;
    pHost_->hit_count_ = 0;

    return *this;
}

std::shared_ptr<HostEntry> HostBuilder::build() {
    return pHost_;
}