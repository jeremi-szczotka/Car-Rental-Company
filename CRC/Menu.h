
#pragma once

#include "AuthenticationSystem.h"

class Menu : public Car {
private:
    AuthenticationSystem system;

    void loginAsAdmin();
    void loginAsUser();

public:
    void display();
};


