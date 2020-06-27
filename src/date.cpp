#include "../include/date.h"

#include <sstream>
#include <iostream>

Date::Date() : year(0), month(0), day(0) {

}

void Date::convert_from_string(const std::string &date) {
    
    std::stringstream stream(date);
    char trash;

    stream >> day;
    stream >> trash;
    stream >> month;
    stream >> trash;
    stream >> year;

}

std::string Date::convert_to_string() {

    std::stringstream stream;
    
    if (day < 10)
        stream << '0';

    stream << day;
    stream << '/';
    
    if (month < 10)
        stream << '0';

    stream << month;
    stream << '/';
    stream << year;

    return stream.str();
}

int Date::isEqual(const Date &date) {

    if(day != date.day)
        return 0;
    else if(month != date.month)
        return 0;
    else if(year != date.year)
        return 0;
    else
        return 1;
}