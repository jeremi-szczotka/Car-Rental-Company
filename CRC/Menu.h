#pragma once
#include "AuthenticationSystem.h"

class Menu : public Car , Rent{
private:
    AuthenticationSystem system;
    void loginAsAdmin();
    void loginAsUser();

public:
    void display();
};


