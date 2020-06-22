#ifndef MESSAGE_H
#define MESSAGE_h

#include <string>
#include "timing.h"

struct message {

    time clock_moment;
    date calendar_moment;
    std::string text;

    bool compare_messages();

};

struct diary {

    message *content;

    int addText(message entry, std::ifstream outfile);
    int list(std::ifstream infile);

}

#endif