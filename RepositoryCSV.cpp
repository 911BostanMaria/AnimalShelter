#include "RepositoryCSV.h"
#include <fstream>

RepositoryCSV::RepositoryCSV(const std::string &fileName) {
    this -> fileName = fileName;
    std::ofstream file(this -> fileName);
}


void RepositoryCSV::writeToFile() {
    std::ofstream file(this -> fileName);
    for(Shelter &e : this -> user_data){
        file << e.get_breed() << ',' << e.get_name() << ',' << e.get_age() << ',' <<e.get_link();
        file << '\n';
    }
    file.close();
}


RepositoryCSV::~RepositoryCSV() {
    this -> writeToFile();
}

void RepositoryCSV::open() {
    system("explorer.exe example.csv");
}






