//
// Created by andrei on 28.03.2022.
//

#pragma once
#include <vector>
#include <iostream>
#include <string>

class ValidationException : public std::exception {
private:
    std::string errorMsg;
public:
    ValidationException(const std::string &msg);
    const char* what() const noexcept override;
};


class ValidatePet {
public:
    static void validate_name(const std::string &name);

    static void validate_breed(const std::string &breed);

    static void validate_age(unsigned int age);

    static void validate_link(const std::string &link);

    static void validate_pet(std::string &name, const std::string &breed, unsigned int age, const std::string &link);
};