#pragma once
#include <string>

class Shelter {
private:
    std::string breed, name, link;
    unsigned int age;

public:
    // Constructor for the shelter class.
    // Parameter breed: the breed of the pet in the shelter, represented as a string.
    // Parameter name: the name of the pet in the shelter, represented as a string.
    // Parameter age: the age of the pet in the shelter, represented as an unsigned integer.
    // Parameter link: the link to the pet photograph, represented as a string.
    Shelter(const std::string &breed,const std::string &name,unsigned int age, const std::string &link);
    Shelter(): breed{""}, name{""}, link{""}, age{0}{};

    // Getters for the private parameters
    std::string get_breed() { return this->breed; }
    std::string get_name() { return this->name; }
    unsigned int get_age() const { return this->age; }
    std::string get_link() { return this->link; }

    // Setters for the private parameters:
    void set_breed(const std::string &new_value) { this->breed  = new_value; }
    void set_name(const std::string &new_value) { this->name  = new_value; }
    void set_age(unsigned int new_value) { this->age = new_value; }
    void set_link(const std::string &new_value) { this->link  = new_value; }

    friend std::ostream &operator<<(std::ostream &os, Shelter dog);

    friend std::istream &operator>>(std::istream &is, Shelter &dog);

};