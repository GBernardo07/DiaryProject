#include "../include/timing.h"

#include <sstream>

Time::Time() : hour(0), minute(0), second(0) {

}

void Time::convert_from_string(const std::string  &time) {

    std::stringstream stream(time);
    char trash;

    stream >> hour;
    stream >> trash;
    stream >> minute;
    stream >> trash;
    stream >> second;

}

std::string Time::convert_to_string() {

    std::stringstream stream;

    if (hour < 10)
        stream << '0';

    stream << hour;
    stream << ':';

    if (minute < 10)
        stream << '0';

    stream << minute;
    stream << ':';

    if (second < 10)
        stream << '0';
    
    stream << second;

    return stream.str();
}