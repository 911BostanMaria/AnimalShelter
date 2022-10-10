//
// Created by maria on 19/04/2022.
//

#include "Service.h"

void Service::service_add(string &breed, string &name, unsigned int age, string &link) {
    try {
        ValidatePet::validate_breed(breed);
        ValidatePet::validate_name(name);
        ValidatePet::validate_age(age);
        Shelter pet(breed,name,age,link);
        r.add_pet(pet);
    }catch (ValidationException& ex) {
        std::cout << ex.what() << std::endl;
    }}

void Service::service_delete(const std::string& name) {
    try {
        ValidatePet::validate_name(name);
        r.delete_pet(name); }
    catch (ValidationException& ex) {
        std::cout << ex.what() << std::endl;
    }}

void Service::service_update(const std::string& initial_name, const std::string& name, unsigned int age,
                             const std::string& link){
    try{
        ValidatePet::validate_age(age);
        ValidatePet::validate_name(name);
        ValidatePet::validate_link(link);
        r.update_info(initial_name, name, age,link);}
    catch (ValidationException& ex) {
        std::cout << ex.what() << std::endl;}
}

void Service::service_entities_add(){
    r.add_ten_pets();
}

std::vector<Shelter> Service::service_filter(const std::string& breed, unsigned int age){
    try{
        ValidatePet::validate_age(age);
        std::vector<Shelter> list;
        return r.filter(breed,age);}
    catch (ValidationException& ex) {
        std::cout << ex.what() << std::endl;}
}

void Service::service_user_adopt(Shelter &pet) {
    user->user_adopt(pet);
    std::string name = pet.get_name();
    service_delete(name);

}

void Service::handleUserRepo(const string &type) {
    std::string fileName;
    if(type == "html"){
        user = new RepositoryHTML("example.html");
    }
    else if(type == "csv"){
        user = new RepositoryCSV("example.csv");
    }
}

void Service::openRepo() {
    this -> user->open();
}

Service::~Service() {
    delete this -> user;
}

