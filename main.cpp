#include <iostream>
#include "UserInterface.h"
#include "tests.h"

int main() {
    int option, optionFile;
    std::cout << "1 for admin \n 2 for user: ";
    std::cin >> option;
    std::string fileName = "readFrom";
    Repository r(fileName);
    Service s(r);
    UI u(s);
    if (option == 2) {
        std::cout << "1 for html 0 for cvs: ";
        std::cin >> optionFile;
        if (optionFile == 1) {
            s.handleUserRepo("html");
        }
        else if(optionFile == 0){
            s.handleUserRepo("csv");
        }
    }
    u.console(option);
    return 0;
}
