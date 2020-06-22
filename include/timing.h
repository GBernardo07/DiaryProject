#ifndef TIME_H
#define TIME_H

struct date {
    
    int day;
    int month;
    int year;

    bool compare_dates(const date &another_date);

};

struct time {

    int hour;
    int minute;
    int second;

};

#endif