#pragma once
#include <vector>
#include "Shelter.h"

class Repository {
private:
    std::vector<Shelter> data;
    std::string fileName;

public:


    Repository(const std::string &fileName);

    unsigned int getSize() const { return this->data.size(); }

    void add_pet(Shelter &pet);

    int find_by_name(Shelter &pet);


    std::vector<Shelter> & getData() {return this->data;}

    void add_ten_pets();

    void update_info(const std::string& initial_name, const std::string& new_name, unsigned int new_age, const std::string& new_link);

    void delete_pet(const std::string& name);

    std::vector<Shelter> filter(const std::string &breed, unsigned int age);

    void readFromFile();

    void writeToFile();


};

