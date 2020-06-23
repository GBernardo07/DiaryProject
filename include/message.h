#ifndef MESSAGE_H
#define MESSAGE_h

#include <string>
#include "timing.h"
#include "date.h"

struct Message {

    std::string content;
    Date date;
    Time time;

    bool compare_messages();

};

#endif