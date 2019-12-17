#ifndef __WH_LOG_H_
#define __WH_LOG_H_
#include <ctime>
#include <iostream>

namespace wh {
void info(const std::string& msg)
{
    time_t my_time = time(NULL);
    std::string s = std::string(ctime(&my_time));
    s = s.substr(11, 14);
    std::cout << "[" << s << "]\n[\033[0;32minfo\033[0m]  " << msg << std::endl;
}
void warning(const std::string& msg)
{
    time_t my_time = time(NULL);
    std::cout << "[" << ctime(&my_time) << "]"
              << "[\033[0;33minfo\033[0m]  " << msg << std::endl;
}
void error(const std::string& msg)
{
    time_t my_time = time(NULL);
    std::cout << "[" << ctime(&my_time) << "]"
              << "[\033[0;31minfo\033[0m]  " << msg << std::endl;
}
}

#endif