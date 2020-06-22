#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

// Número de comandos
#define Ncommands 2 

// Definir tipo array de ponteiros para função
typedef int (*fpointer)(char *argv[]);

// Função formatar o instante
std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

// Funções que retornam data
std::string get_current_date() { return format_current_date("%d/%m/%Y"); }
// e hora
std::string get_current_time() { return format_current_date("%H:%M:%S"); }

// Função exibir uso dos comandos
void displayCommands(std::string program) {
    std::cout << "Uso: \n";
    std::cout << program << " add <mensagem>\n";
    std::cout << program << " list" << std::endl;
}

// Função checar a data
int checkDate() {

    std::ifstream infile;
    std::string date;

    infile.open("diary.md");
    while(!infile.eof()) {
        std::getline(infile, date);

        // Excluindo o "#" para comparar com get_current_date()
        if (date.size())
            date = date.substr(2);

        // Caso já exista entrada com aquela data
        if (date == get_current_date())
            return 1;
    }
    // Caso não exista
    return 0;
}

// Função adicionar texto no arquivo
int addText(char *argv[]) {

    int i=2, isToday;
    std::ofstream outfile;
    std::string date, msg;

    outfile.open("diary.md", std::ios::app);

    // Verificação de acesso ao arquivo
    if (!outfile.is_open()) {
        std::cerr << "O arquivo nao pode ser acessado corretamente" << std::endl;
        return 1;
    }

    // Verificação de existência de data
    isToday = checkDate();
    if (!isToday)
        outfile << "\n" << "# " << get_current_date() << "\n" << std::endl;

    // Caso não haja mais argumentos após o "add", pedir a entrada
    if (argv[2] == nullptr) {
        std::cout << "Insira uma mensagem:" << std::endl;
        std::getline(std::cin, msg);
        outfile << "- " << get_current_time() << " " << msg << "\n";
        std::cout << "Mensagem adicionada" << std::endl;
        return 0;
    }

    // Caso haja argumentos após o "add", adicionar cada um individualmente
    outfile << "- " << get_current_time() << " ";
    while (argv[i] != nullptr) {
        outfile << argv[i] << " ";
        i++;
    }
    outfile << std::endl;
    std::cout << "Mensagem adicionada" << std::endl;

    return 0;
}

// Função listar entradas no arquivo
int list(char *argv[]) {

    int checkDay;
    int l_number = 1;
    std::string text;
    std::ifstream infile;

    infile.open("diary.md");

    // Verificação de acesso ao arquivo
	if (!infile.is_open()) {
   		std::cerr << "O arquivo nao pode ser acessado corretamente" << std::endl;
    	return 1;
  	}

    // Enquanto o arquivo não terminar, imprimir as linhas numerando-as
    while(!infile.eof()) {
        std::getline(infile, text);

        if (!text.size())
            continue;

        // Imprimir apenas o conteúdo das mensagens
        if (text.substr(0, 1) != "#") {
            std::cout << l_number << ". " << text.substr(11) << std::endl;
            l_number++;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
 
    std::string msg, commands[]{"add", "list"};
    
    // Declaração dos ponteiros para as funções e do array desses ponteiros
    fpointer ptrAddText{addText}, ptrList{list}, 
        fcommands[Ncommands]{ptrAddText, ptrList};

    // Caso não haja argumentos além do ./argv[0]
    if (argc == 1) {
        displayCommands(argv[0]);
        return 1;
    }

    // Iterar sobre todos os comandos disponíveis no array e chamar a respectiva função
    for (int i = 0; i < Ncommands; i++) {
        if (std::string(argv[1]) == commands[i]) {
            fcommands[i](argv);
            return 0;
        }
    }

    // Caso tenha sido inserido um comando indisponível
    displayCommands(argv[0]);

    return 0;
}