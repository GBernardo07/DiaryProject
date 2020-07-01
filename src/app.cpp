#include "../include/app.h"

#include <iostream>
#include <string>

App::App(const std::string &filename) : diary(filename) {

    diary.filename = filename;

};

int App::run(int argc, char *argv[]) {

    std::vector<Message> *foundIn;
    diary.getMessages();
    std::string longEntry;

    if (argc == 1)
        return show_usage(argv[0]);

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2)
            add();
        else {
            for (int i = 2; i < argc; i++) {
                longEntry += argv[i];
                longEntry += ' ';
            }
            longEntry.erase(longEntry.end()-1);
            add(longEntry);
        }
        diary.write();
    } 

    else if (action == "list")
        list();
    else if (action == "search") {
        std::vector<Message> whatVector;
        foundIn = diary.search(argv[2], &whatVector);
        if (foundIn != nullptr) {
            std::cout << "Achado em: " << std::endl;
            for (int i = 0; i < whatVector.size(); ++i) {
                std::cout << whatVector[i].content << std::endl;
            } 
        }
        else {
            std::cout << "Nao existem mensagens com esse termo" << std::endl;
        }
    }
    else
        return show_usage(argv[0]);

    return 0;
};

int App::add()
{
    std::string message;
        std::cout << "Enter your message:" << std::endl;
        std::getline(std::cin, message);

        diary.add(message);

    return 1;
};

int App::add(const std::string message) {
    diary.add(message);

    return 1;
};

int App::list() {
    for (size_t i = 0; i < diary.messages.size(); ++i) {
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