#include "../include/app.h"

#include <iostream>
#include <string>

App::App(const std::string &filename) : diary(filename) {

};

int App::run(int argc, char *argv[]) {
    if (argc == 1)
        return show_usage(argv[0]);

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2)
            add();
        else {
            for (int i = 2; i < argc; i++) {
                std::cout << argv[i] << std::endl;
                add(argv[i]);
            }
        }
    } 
    else if (action == "list")
        list();
    else
        return show_usage(argv[0]);

    return 0;
};

int App::add()
{
    std::string message;
    for (int j = 0; j < 10; j++) {
        std::cout << "Enter your message:" << std::endl;
        std::getline(std::cin, message);

        diary.add(message);
    }

    return 1;
};

int App::add(const std::string message) {
    diary.add(message);
    diary.write();

    return 1;
};

int App::list() {
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }

    return 1;
};

int App::show_usage(char *program) {
    std::cout << "Uso: \n";
    std::cout << program << " add <mensagem>\n";
    std::cout << program << " list" << std::endl;

    return 1;
};