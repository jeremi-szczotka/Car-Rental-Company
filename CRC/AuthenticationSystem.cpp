#include "AuthenticationSystem.h"


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
            if (dynamic_cast<AdminUser*>(user) != nullptr) {
                file << "admin ";
            }
            else {
                file << "user ";
            }
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

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string userType;
            iss >> userType;
             
            if (userType == "user" || userType == "admin") {
                std::string username, password;
                if (iss >> username >> password) {
                    if (userType == "user") {
                        users.push_back(new User(username, password));
                    }
                    else if (userType == "admin") {
                        users.push_back(new AdminUser(username, password));
                    }
                }
                else {
                    std::cerr << "Invalid format in file: " << filename << std::endl;
                }
            }
        }

        file.close();
    }
    else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}


