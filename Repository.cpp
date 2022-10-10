//
// Created by maria on 06/04/2022.
//

#include <stdexcept>
#include <algorithm>
#include "Repository.h"
#include <fstream>
#include <iostream>


// Function to add a pet to the adoption list, if the pet is already in the data, we'll throw an exception.
void Repository::add_pet(Shelter &pet) {
    if(find_by_name(pet)==1)
        throw std::invalid_argument("Pet already on the adoption list.");
    this->data.push_back(pet);
    this->writeToFile();
}

// Function to see if a pet is already in the adoption list, searching by its name.
int Repository::find_by_name(Shelter &pet) {
    int found = 0;
    for(int i=0; i<data.size(); i++)
        if(this->data[i].get_name() == pet.get_name())
            found = 1;
    return found;
}

// Function to filter the adoption list by breed and age.
// Parameter breed: the breed of the pets the user chose, type string.
std::vector<Shelter> Repository::filter(const std::string& breed,unsigned int age){
    std::vector<Shelter> list;
    for(int i=0; i<data.size(); i++)
        if(this->data[i].get_age() < age && this->data[i].get_breed()==breed)
            list.push_back(this->data[i]);
    return list;
}

// Function to delete pet from the adoption list (in case the pet is adopted.)
// Throws exception is the pet is not found, deletes it from the list otherwise.
void Repository::delete_pet(const std::string& name) {
    auto it = std::find_if(this->data.begin() , this->data.end() , [name](Shelter &e){return name == e.get_name();});
    if(it == this -> data.end())
        throw std::invalid_argument("Pet with the name" + name + " does not exist!");
    this -> data.erase(it);
    this->writeToFile();
}

void Repository::update_info(const std::string& initial_name, const std::string& new_name, unsigned int new_age,
                             const std::string& new_link) {
    int found=0;
    for (int i = 0; i < data.size(); i++)
        if (initial_name == this->data[i].get_name()) {
            found=1;
            this->data[i].set_name(const_cast<std::string &>(new_name));
            this->data[i].set_age(new_age);
            this->data[i].set_link(const_cast<std::string &>(new_link));
        }
    if(found==0)
        throw std::invalid_argument("Pet does not exist on adoption list.");
    this->writeToFile();
}

// Function to add ten entities to the available adoption list. Entities of type Shelter.
void Repository::add_ten_pets() {
    Shelter pet1("Bulldog", "Rex", 5, "link");
    this->data.push_back(pet1);
    Shelter pet2("Akita", "Archie", 1, "link");
    this->data.push_back(pet2);
    Shelter pet3("Collie", "Martha", 9, "link");
    this->data.push_back(pet3);
    Shelter pet4("Cocker Spaniel",  "Max", 12, "link");
    this->data.push_back(pet4);
    Shelter pet5( "Corgi","Eve", 7, "link");
    this->data.push_back(pet5);
    Shelter pet6("Collie","Martha", 9,"link");
    this->data.push_back(pet6);
    Shelter pet7("Rottweiler","Eminem", 2,"link");
    this->data.push_back(pet7);
    Shelter pet8("Saint Bernard", "Bernard", 10, "link");
    this->data.push_back(pet8);
    Shelter pet9("Scottish Terrier","Mariah Carey", 4, "link");
    this->data.push_back(pet9);
    Shelter pet10("German Shepherd","Pitbull", 6,"link");
    this->data.push_back(pet10);
}

Repository::Repository(const std::string &fileName) {
    this -> fileName = fileName;
    this -> readFromFile();
}

void Repository::readFromFile() {
    std::ifstream file(this -> fileName);
    Shelter e;
    if(!file.is_open())
        return ;
    while(file >> e){
        this ->add_pet(e);
    }
    file.close();
}

void Repository::writeToFile() {
    std::ofstream file(this -> fileName);
    if(!file.is_open()){
        return ;}
    for(Shelter &s : this -> data){
        file << s;
    }
    file.close();
}




