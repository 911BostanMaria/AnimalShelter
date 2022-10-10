#pragma once
#include <vector>
#include "Shelter.h"

class User {
protected:
    std::vector<Shelter> user_data;
    std::string fileName;


public:
    void user_adopt(Shelter &pet);

    std::vector<Shelter> &getData() { return this->user_data;}

    User();

    unsigned long getSize() const{return this -> user_data.size();};

    virtual void writeToFile() = 0;

    virtual void open() = 0;

};

class UserException : public std::exception {
private:
    std::string message;
public:
    explicit UserException(const std::string &msg);
    const char* what() const noexcept override;
};