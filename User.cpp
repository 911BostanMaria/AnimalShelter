#include <stdexcept>
#include "User.h"

void User::user_adopt(Shelter& pet) {
    user_data.push_back(pet);
    this -> writeToFile();
}

User::User() = default;


UserException::UserException(const std::string &msg) {
    this -> message = msg;
}

const char *UserException::what() const noexcept {
    return this -> message.c_str();
}
