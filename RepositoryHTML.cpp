#include <fstream>
#include "RepositoryHTML.h"


RepositoryHTML::RepositoryHTML(const std::string &fileName) {
    this -> fileName = fileName;
    std::ofstream f(this -> fileName);
}

void RepositoryHTML::writeToFile() {
    std::ofstream file(this -> fileName);
    file << "<!DOCTYPE html>\n<html>\n<head><title> Events </title> \n</head> \n <body> \n";
    file << "<table border=\"1\">\n";
    for(Shelter &e : this -> user_data){
        file << "<tr><td>" << e.get_breed() << "</td>";
        file << "<td>" << e.get_name() << "</td>";
        file << "<td>" << e.get_age() << "</td>";
        file << "<td> <a href = \"\">" << e.get_link() << "</a> </td>";
        file << '\n';
    }
    file << " </tr> </table> </body> </html>";
    file.close();
}

RepositoryHTML::~RepositoryHTML() {
    this -> writeToFile();
}


void RepositoryHTML::open() {
    system("explorer.exe example.html");
}


