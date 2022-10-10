#pragma once
#include "Repository.h"
#include "Validator.h"
#include "User.h"
#include "RepositoryCSV.h"
#include "RepositoryHTML.h"

using std::string;

class Service {
    Repository &r;
    User *user;

public:
    Service(Repository &r) : r{r}{};

    std::vector<Shelter> &getData() { return r.getData() ; }

    void service_add(std::string &breed, std::string &name, unsigned int age, std::string &link);

    void service_delete(const string& name);

    void service_update(const string& initial_name, const string& name, unsigned int age, const string& link);

    void service_entities_add();

    void service_user_adopt(Shelter &pet);

    std::vector<Shelter> service_filter(const string& breed, unsigned int age);

    std::vector<Shelter> get_user_data() { return user->getData();}

    void handleUserRepo(const std::string &type);

    void openRepo();

    ~Service();
};