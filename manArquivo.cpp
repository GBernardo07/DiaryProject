#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) {
 
    std::string msg;
    std::ofstream outputfile;

    outputfile.open("mensagem.txt");

    if (argc == 1)
        std::cout << "Uso: "<< argv[0] << " add <mensagem>" << std::endl;
    else if (argc == 2) {
        if (std::string(argv[1]) == "add") {
            std::cout << "Insira uma mensagem:" << std::endl;
            std::getline(std::cin, msg);
            std::cout << "Mensagem adicionada" << std::endl;
        }
        else
            std::cout << "Uso: "<< argv[0] << " add <mensagem>" << std::endl;
    }
    else {    
        msg = argv[2];        
        std::cout << "Mensagem adicionada" << std::endl;
    }

    outputfile << msg;
    outputfile.close();

    return 0;
}