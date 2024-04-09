#include "AuthenticationSystem.h"
#include <fstream>

void AuthenticationSystem::addUser(User* user) {
    users.push_back(user);
}

User* AuthenticationSystem::login(const std::string& username, const std::string& password) {
    for (User* user : users) {
        if (user->authenticate(username, password)) {
            return user;
        }
    }
    return nullptr;
}

void AuthenticationSystem::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (User* user : users) {
            user->saveToFile(file);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

void AuthenticationSystem::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        for (User* user : users) {
            delete user;
        }
        users.clear();
        User* user = nullptr;
        while ((user = User::loadFromFile(file)) != nullptr) {
            users.push_back(user);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}
