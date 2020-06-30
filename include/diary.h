#ifndef DIARY_H
#define DIARY_H

#include <string>
#include "message.h"

struct Diary {

    Diary(const std::string &filename);
    ~Diary();

    std::string filename;
    Message *messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string &message);
    void write();
    void getMessages();
    void extendArray();
    Message *search(std::string what);

};



#endif