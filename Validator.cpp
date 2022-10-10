#include "Validator.h"

ValidationException::ValidationException(const std::string &msg) {
    this -> errorMsg = msg;
}

const char *ValidationException::what() const noexcept {
    return this -> errorMsg.c_str();
}

void ValidatePet::validate_name(const std::string &name) {
    if(name.empty())
        throw ValidationException("Give your pet a name\n");
}

void ValidatePet::validate_breed(const std::string &breed) {
    if(breed.empty())
        throw ValidationException("Breed cannot be empty!\n");

}

void ValidatePet::validate_age(unsigned int age) {
    if(age>=16)
        throw ValidationException("Lifespan of a dog cannot be greater than that. Dog died probably.\n");
}

void ValidatePet::validate_link(const std::string &link) {
    if(link.empty())
        throw ValidationException("Link cannot be empty!\n");

}

void ValidatePet::validate_pet(std::string &name, const std::string &breed,unsigned int age,const std::string &link){
    std::string errorMsg;
    if(name.empty())
        errorMsg += "Give your pet a name.\n";
    if(breed.empty())
        errorMsg += "Breed cannot be empty! \n";
    if(age>=16)
        errorMsg += "Lifespan of a dog cannot be greater than that. Dog died probably.\n";
    if(link.empty())
        errorMsg += "Link cannot be empty! \n";

}
