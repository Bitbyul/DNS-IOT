#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <sstream>
#include <iostream>
#include <chrono>
#include <ctime>

static const std::string COMMON_FMT("[%TimeStamp%][%Severity%]:  %Message%");

class Logger {

public:

    template <typename T>
    static void concat_all(std::ostringstream& ss, T arg) {
        ss << arg << "\n";
    }

    template <typename T, typename... Types>
    static void concat_all(std::ostringstream& ss, T arg, Types... args) {
        ss << arg;
        concat_all(ss, args...);
    }

    template <typename... Types>
    static void i(Types... args){
        std::ostringstream ss;

        concat_all(ss, args...);

        std::cout << "[" << now_time() << "][I] " << ss.str();
    }

    template <typename... Types>
    static void e(Types... args){
        std::ostringstream ss;

        concat_all(ss, args...);

        std::cout << "[" << now_time() << "][E] " << ss.str();
    }

private:

    Logger(){

    };

    static const char* now_time(){
        static char str_date[50];
        struct std::tm* pNowTimeInfo;

        auto now = time(NULL);
        pNowTimeInfo = std::localtime(&now);

        sprintf(str_date, "%d/%02d/%02d %02d:%02d:%02d", pNowTimeInfo->tm_year+1900, pNowTimeInfo->tm_mon+1, pNowTimeInfo->tm_mday, 
                                        pNowTimeInfo->tm_hour, pNowTimeInfo->tm_min, pNowTimeInfo->tm_sec);

        return str_date;
    }
};

#endif