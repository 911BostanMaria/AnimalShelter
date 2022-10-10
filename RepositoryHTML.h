//
// Created by andrei on 19.04.2022.
//

#pragma once
#include "User.h"

class RepositoryHTML : public User {
public:
    RepositoryHTML(const std::string &fileName);
    void writeToFile() override;
    ~RepositoryHTML();
    void open() override;
};