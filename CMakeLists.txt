cmake_minimum_required(VERSION 3.0.0)
project(dns-server VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(dns-server main.cpp host.h host.cpp manager.h manager.cpp tools/logger.h tools/datatype.cpp tools/datatype.h database/ConnectionPool.cpp database/ConnectionPool.h database/HostRepository.cpp database/HostRepository.h)

find_library(MYSQL_LIB mysqlcppconn)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME} ${MYSQL_LIB})