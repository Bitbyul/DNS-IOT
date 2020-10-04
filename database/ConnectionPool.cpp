#include "ConnectionPool.h"

using namespace std;

ConnectionPool::ConnectionPool(int numConnection) {

    driver_ = get_driver_instance();
    sql::Connection* con;
    
    for(int i=0; i<numConnection; i++)
        con = driver_->connect(kDBURL, kDBUsername, kDBPassword);
        con->setSchema(kDBScheme);
        pool_.insert(make_pair(con, PoolState::IDLE));
}

std::shared_ptr<sql::Connection> ConnectionPool::get_connection() {

    unique_lock<mutex> lk(mutex_); // 상호 배제

    for(auto iter = pool_.begin(); iter!=pool_.end(); iter++) {
        if(iter->second == PoolState::IDLE) {
            iter->second = PoolState::USED;
            return iter->first;
        }
    }

}

void ConnectionPool::release_connection(shared_ptr<sql::Connection> pCon) {

    unique_lock<mutex> lk(mutex_); // 상호 배제

    auto iter = pool_.find(pCon);
    if(iter!=pool_.end()){
        if(iter->second == PoolState::USED) iter->second = PoolState::IDLE;
    }
}
