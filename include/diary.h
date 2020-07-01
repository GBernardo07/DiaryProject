#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <vector>
#include "message.h"

struct Diary {

    Diary(const std::string &filename);
    //~Diary();

    std::string filename;
    std::vector<Message> messages;

    void add(const std::string &message);
    void write();
    void getMessages();
    //void extendArray();
    std::vector<Message> *search(std::string what, std::vector<Message> *whatVectorP);

};



#endif