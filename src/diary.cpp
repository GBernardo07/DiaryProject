#include "../include/diary.h"
#include "../include/currenttime.h"

#include <iostream>

Diary::Diary(const std::string &filename) : messages_capacity(10), messages(nullptr), messages_size(0) {
   
    messages = new Message[messages_capacity];
}

void Diary::add(const std::string &message) {
    if (messages_size == messages_capacity)
        return;
    Message base_msg;
    base_msg.content = message;
    base_msg.date.convert_from_string(get_current_date());
    base_msg.time.convert_from_string(get_current_time());
    messages[messages_size] = base_msg;
    messages_size++;   
}

void Diary::write() {
    // gravar as mensagens no disco
}