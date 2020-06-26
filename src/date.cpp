#include "../include/date.h"

#include <sstream>

Date::Date() : year(0), month(0), day(0) {

}

void Date::convert_from_string(const std::string &date) {

    Date calendar_moment;
    
    std::stringstream stream(date);
    char trash;

    stream >> calendar_moment.day;
    stream >> trash;
    stream >> calendar_moment.month;
    stream >> trash;
    stream >> calendar_moment.year;

}