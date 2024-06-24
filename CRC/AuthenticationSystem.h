#pragma once
#include "Rent.h"
#include "Car.h"
#include "User.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class AuthenticationSystem {
public:
    ~AuthenticationSystem();
    std::vector<User*> users;
    void loadFromFile(const std::string& filename);
    User* login(const std::string& username, const std::string& password);
};



