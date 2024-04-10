
#pragma once

#include "AuthenticationSystem.h"

class Menu {
private:
    AuthenticationSystem system;

    void loginAsAdmin();
    void loginAsUser();

public:
    void display();
};


