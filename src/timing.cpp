#include "../include/timing.h"

#include <sstream>

Time::Time() : hour(0), minute(0), second(0) {

}

void Time::convert_from_string(const std::string  &time) {

    Time clock_moment;

    std::stringstream stream(time);
    char trash;

    stream >> clock_moment.hour;
    stream >> trash;
    stream >> clock_moment.minute;
    stream >> trash;
    stream >> clock_moment.second;

}