#include "HostRepository.h"

#include "ConnectionPool.h"
#include "../manager.h"
#include "../host.h"
#include "../tools/logger.h"

HostRepository::HostRepository() : pConPool_(new ConnectionPool(HostRepository::kMaxConnection)) {
    load_dns_table_from_db();
}

void HostRepository::db_test(){

    auto con = pConPool_->get_connection();

    try {
        sql::Statement *stmt;
        sql::ResultSet *res;

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'db_test' AS _message");
        while (res->next()) {
            std::cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            std::cout << res->getString("_message") << std::endl;
            std::cout << "\t... MySQL says it again: ";
            /* Access column data by numeric offset, 1 is the first column */
            std::cout << res->getString(1) << std::endl;
        }
        delete res;
        delete stmt;

    } catch (sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

    pConPool_->release_connection(con);
}

/*
    DNS 테이블을 DB 에서 메모리로 적제
*/
int HostRepository::load_dns_table_from_db(){
    
    Logger::i("Loading DNS Table From db...");

    int row_count = 0;

    auto con = pConPool_->get_connection();

    try {
        sql::Statement *stmt;
        sql::PreparedStatement *prestmtAliases;
        sql::PreparedStatement *prestmtAddrlist;
        sql::ResultSet *res;
        sql::ResultSet *res2;

        stmt = con->createStatement();
        prestmtAliases = con->prepareStatement("SELECT alias FROM aliases WHERE entry_id=?");
        prestmtAddrlist = con->prepareStatement("SELECT addr FROM addr_list WHERE entry_id=?");
        res = stmt->executeQuery("SELECT * FROM host_entry");
        while (res->next()) {
            HostBuilder builder;

            std::cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            std::cout << res->getString("h_name") << std::endl;
            std::cout << "\t... MySQL says it again: ";
            /* Access column data by numeric offset, 1 is the first column */
            std::cout << res->getString(1) << std::endl;

            auto b = builder.name(res->getString("h_name").c_str()).addrtype(res->getInt("h_addrtype"))
                                    .addr_length(res->getInt("h_length")).hit_count(res->getInt("hit_count"));

            prestmtAliases->setInt(1, res->getInt("id"));
            res2 = prestmtAliases->executeQuery();
            
            while (res2->next())
                b.add_alias(res2->getString("alias").c_str());
                
            prestmtAddrlist->setInt(1, res->getInt("id"));
            res2 = prestmtAddrlist->executeQuery();
            
            while (res2->next())
                b.add_addr(res2->getString("addr").c_str());
            
            cached_host_list_.push_back(b.build());

            row_count++;
        }
        delete res;
        delete res2;
        delete stmt;
        delete prestmtAliases;
        delete prestmtAddrlist;

    } catch (sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

    pConPool_->release_connection(con);

    for(auto iter = cached_host_list_.begin(); iter != cached_host_list_.end(); iter++) {
        std::cout << (*iter)->as_str();
    }

    Logger::i("Loaded table rows: ", row_count);

    return row_count;
}

/*
    DNS 테이블을 메모리에서 DB로 저장
*/
int HostRepository::save_dns_table_to_db(){

    auto con = pConPool_->get_connection();

    try {
        sql::Statement *stmt;
        sql::ResultSet *res;

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'save_dns_table_to_db' AS _message");
        while (res->next()) {
            std::cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            std::cout << res->getString("_message") << std::endl;
            std::cout << "\t... MySQL says it again: ";
            /* Access column data by numeric offset, 1 is the first column */
            std::cout << res->getString(1) << std::endl;
        }
        delete res;
        delete stmt;

    } catch (sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

    pConPool_->release_connection(con);

    return 0;
}

/*
    Domain 이름으로 Host 검색
*/
HostEntry* const HostRepository::getByDomain(std::string ip_str) {
    
    for(auto iter = cached_host_list_.begin(); iter != cached_host_list_.end(); iter++) { // 캐시 테이블 순회
        if(ip_str == (*iter)->name()) return (*iter).get();
        for(auto iter2 = (*iter)->aliases().begin(); iter2 != (*iter)->aliases().end(); iter2++) // HostEntry 내 Alias 리스트 순회
            if(ip_str == *iter2) return (*iter).get();
    }

    return nullptr;
}

/*
    IP 주소로 Host 검색
*/
HostEntry* const HostRepository::getByIP(std::string ip_str) {
    
    struct in_addr myinaddr; //IP 주소를 저장할 구조체 

    for(auto iter = cached_host_list_.begin(); iter != cached_host_list_.end(); iter++) { // 캐시 테이블 순회

        for(auto iter2 = (*iter)->addr_list().begin(); iter2 != (*iter)->addr_list().end(); iter2++) { // HostEntry 내 IP 리스트 순회

            myinaddr.s_addr = *(u_long*)((*iter2).get());  // IPv4 only
            
            if(ip_str == inet_ntoa(myinaddr)) return (*iter).get();
        }
    }

    return nullptr;
}