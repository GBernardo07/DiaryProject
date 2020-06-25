#include "../include/diary.h"

#include <iostream>

Diary::Diary(const std::string &filename) : messages_capacity(10), messages(nullptr), messages_size(0) {
   
    messages = new Message[messages_capacity];
}

void Diary::add(const std::string &message) {
    if (messages_size == messages_capacity)
        return;
    Message base_msg;
    base_msg.content = message;
    messages[messages_size] = base_msg;
    messages_size++;   
}

void Diary::write() {
    // gravar as mensagens no disco
}