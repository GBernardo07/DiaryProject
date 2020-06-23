#ifndef APP_H
#define APP_H

#include <string>
#include "diary.h"

struct App {
    
    Diary diary;

    App(const std::string &filename);

    int run(int argc, char *argv[]);
    int show_usage(char *argv);
    int add();
    int add(const std::string message);
    int list();
};

#endif