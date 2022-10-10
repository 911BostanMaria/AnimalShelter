#include "UserInterface.h"
#include <iostream>


void UI::printMenuUser() {
    std::cout<<"1. see all dogs on adoption list\n";
    std::cout<<"2. see dogs of given breed having age less than a given number\n";
    std::cout<<"3. see dogs you adopted\n";
    std::cout<<"4. exit\n";
}

void UI::admin_add() {
    std::string name, breed, link;
    unsigned int age;
    std::cout<<"dog's name: \n";
    std::cin>>name;
    std::cout<<"dog's breed: \n";
    std::cin>>breed;
    std::cout<<"dog's age: \n";
    std::cin>>age;
    std::cout<<"link to dog's picture: \n";
    std::cin>>link;
    try {
        service.service_add(breed, name, age, link);
    }
    catch(std::invalid_argument&e){
        std::cout<<e.what();
    }
}

void UI::admin_delete() {
    std::string name;
    std::cout<<"dog's name: \n";
    std::cin>>name;
    try {
        service.service_delete(name);
    }
    catch(std::invalid_argument&e){
        std::cout<<e.what();
    }
}

void UI::admin_update() {
    std::string initial_name,name,link;
    unsigned int age;
    std::cout<<"dog's initial name: \n";
    std::cin>>initial_name;
    std::cout<<"dog's name: \n";
    std::cin>>name;
    std::cout<<"dog's age: \n";
    std::cin>>age;
    std::cout<<"link to dog's picture: \n";
    std::cin>>link;
    try {
        service.service_update(initial_name, name, age, link);
    }
    catch(std::invalid_argument&e){
        std::cout<<e.what();
    }
}

void UI::admin_print() {
    int i;
    std::vector<Shelter> data;
    data = service.getData();
    for(i=0; i< data.size(); i++)
        std::cout<<"BREED  : "<<data[i].get_breed()<<"  NAME:  "<<data[i].get_name()<<"  AGE:  "<<data[i].get_age()
        <<"  LINK:  "<<data[i].get_link()<<"\n";
    std::cout<<"\n";
}

void UI::user_print(){
    int i;
    std::vector<Shelter> data;
    data = service.get_user_data();
    for(i=0; i< data.size(); i++)
        std::cout<<"breed: "<<data[i].get_breed()<<" name: "<<data[i].get_name()<<" age: "<<data[i].get_age()<<" link: "<<data[i].get_link()<<"\n";
    std::cout<<"\n";
}
void UI::user_filter(){
    unsigned int age;
    std::string breed;
    std::cout<<"age: \n";
    std::cin>>age;
    std::cout<<"breed: \n";
    std::cin>>breed;
    std::vector<Shelter> data = service.service_filter(breed,age);
    for(int i=0; i< data.size(); i++)
        std::cout<<"breed: "<<data[i].get_breed()<<" name: "<<data[i].get_name()<<" age: "<<data[i].get_age()<<" link: "<<data[i].get_link()<<"\n";
    std::cout<<"\n";
}

void UI::printMenuAdmin() {
    std::cout<<"1. add a dog\n";
    std::cout<<"2. delete a dog\n";
    std::cout<<"3. update a dog's info\n";
    std::cout<<"4. see all dogs on adoption list\n";
    std::cout<<"5. exit\n"<<"\n";
}

void UI::console(int option) {
    service.service_entities_add();
    if (option == 1) {
        int admin_option=1;
        while (admin_option != 5) {
            printMenuAdmin();
            std::cout<<"your option: ";
            std::cin >> admin_option;
            if (admin_option == 1)
                admin_add();
            else if (admin_option == 2)
                admin_delete();
            else if (admin_option == 3)
                admin_update();
            else if (admin_option == 4)
                admin_print();
            else if (admin_option == 5)
                return;
            else
                std::cout << "invalid option";
        }
    }

    if (option == 2) {
        int user_option=1;
        while (user_option != 4) {
            printMenuUser();
            std::cout<<"your option: \n";
            std::cin >> user_option;
            if (user_option == 1) { // SEE ALL DOGS IN DATA BASE
                unsigned int i = 0;
                std::vector<Shelter> data;
                data = service.getData();
                while (i < data.size()) {
                    std::cout << data[i].get_breed() << " " << data[i].get_name() << " " << data[i].get_age() << " "
                              << data[i].get_link()
                              << std::endl;
                    std::cout << "do you wish to adopt dog? yes/no \n";
                    std::string wish;
                    std::cin >> wish;
                    if (wish == "yes") {
                        service.service_user_adopt(data[i]);
                        data = service.getData();
                    }
                    i++;
                    std::cout << "do you wish to see other pets? yes/no \n";
                    std::string wish2;
                    std::cin >> wish2;
                    if (wish2 == "no")
                        i=data.size()+1;
                    else
                        if (i == data.size()-1)
                            i=0;
                    }
                }
            else if (user_option == 2)
                user_filter();
            else if (user_option == 3)
                service.openRepo();
            else if (user_option == 4)
                return;
            else
                std::cout << "invalid option";

        }
    }
}
