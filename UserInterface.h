#pragma once
#include <string>
#include "User.h"
#include "Service.h"
#include "Validator.h"

class UI {
private:
    Service &service;

public:
    UI(Service &s) : service{s}{};

    static void printMenuAdmin();

    static void printMenuUser();

    void admin_add();

    void admin_delete();

    void admin_update();

    void admin_print();

    void console(int option);

    void user_filter();

    void user_print();
};