#ifndef DATE_H    
#define DATE_H

#include <string>


struct Date {

    Date();
    unsigned year;
    unsigned month;
    unsigned day;

    void convert_from_string(const std::string &date);
};


#endif