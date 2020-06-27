#include "../include/diary.h"
#include "../include/currenttime.h"

#include <iostream>
#include <fstream>

Diary::Diary(const std::string &filename) : messages_capacity(5), messages(nullptr), messages_size(0) {
   
    messages = new Message[messages_capacity];
}

Diary::~Diary() {

    delete[] messages;
}

void Diary::add(const std::string &message) {
    if (messages_size == messages_capacity)
        extendArray();
    Message base_msg;
    base_msg.content = message;
    base_msg.date.convert_from_string(get_current_date());
    base_msg.time.convert_from_string(get_current_time());
    messages[messages_size] = base_msg;
    messages_size++;  
}

void Diary::write() {

    std::ofstream outfile;
    outfile.open(filename);

    outfile << "# " << messages[0].date.convert_to_string() << std::endl;
    outfile << "- " << messages[0].time.convert_to_string() << " " << messages[0].content << std::endl;

    for (int i = 1; i < messages_size; i++){
        if (!messages[i].date.isEqual(messages[i-1].date)) {
            outfile << "# " << messages[i].date.convert_to_string() << std::endl;
        }
        outfile << "- " << messages[i].time.convert_to_string() << " " << messages[i].content << std::endl;
    }

    outfile << "\n" << std::endl;
}

void Diary::getMessages() {

    int i=0;
    Message oldMessage;
    std::string line;
    std::ifstream infile;

    infile.open(filename);

    if (!infile.is_open())
        return;
        
    while (!infile.eof()){
        if (messages_size == messages_capacity)
            extendArray();

        std::getline(infile, line);
        
        if (line.substr(0,1) == "#") {
            line.erase(0,2);
            oldMessage.date.convert_from_string(line);
        }
        else if (line.substr(0,1) == "-") {
            line.erase(0,2);
            oldMessage.time.convert_from_string(line);
            oldMessage.content = line.substr(9);
            messages[i] = oldMessage;
            messages_size++;
            i++;
        }
    }
}

void Diary::extendArray() {

    messages_capacity *= 2;
    Message *moreMessages = new Message[messages_capacity];

    for (int i = 0; i < messages_size; i++)
        moreMessages[i] = messages[i];

    delete[] messages;
    messages = moreMessages;
}