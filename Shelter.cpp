#include "Shelter.h"
#include <ostream>
#include <fstream>

Shelter::Shelter(const std::string &breed, const std::string &name, unsigned int age, const std::string &link) {
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->link = link;
}

std::ostream &operator<<(std::ostream &os, Shelter dog) {
    os << dog.get_breed() << ',';
    os << dog.get_name() << ',';
    os << dog.get_age() << ',';
    os << dog.get_link();
    os << '\n';
    return os;
}

std::istream &operator>>(std::istream &is, Shelter &dog) {
    std::string age;
    if(is.eof())
        is.setstate(std::ios_base::failbit);
    else {
        getline(is , dog.breed , ',');
        getline(is , dog.name , ',');
        getline(is , age , ',');
        dog.age = atoi(age.c_str());
        getline(is , dog.link , '\n');
    }

    return is;
}