#ifndef TIME_H
#define TIME_H

#include <string>

struct Time {

    Time();
    unsigned hour;
    unsigned minute;
    unsigned second;

    void convert_from_string(const std::string  &time);
    std::string convert_to_string();
};

#endif