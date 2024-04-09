#include<iostream>
#include"User.h"
#include "AuthenticationSystem.h"

int main() {
    AuthenticationSystem system;

    // Zapisujemy u¿ytkowników do pliku
    system.saveToFile("users.txt");

    // Odczytujemy u¿ytkowników z pliku
    system.loadFromFile("users.txt");

    // Interfejs wyboru roli u¿ytkownika i logowanie
    std::cout << "-----------------" << std::endl;
    std::cout << "Welcome to a Car Rental Company" << std::endl;
    std::cout << "Choose who you are:" << std::endl;
    std::cout << "1. Admin" << std::endl;
    std::cout << "2. User" << std::endl;
    std::cout << "-----------------" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1: {
        std::string adminUsername, adminPassword;
        std::cout << "Enter admin username: ";
        std::cin >> adminUsername;
        std::cout << "Enter admin password: ";
        std::cin >> adminPassword;

        User* loggedInAdmin = system.login(adminUsername, adminPassword);
        if (loggedInAdmin != nullptr && dynamic_cast<AdminUser*>(loggedInAdmin) != nullptr) {
            std::cout << "Logged in as admin: " << loggedInAdmin->getUsername() << std::endl;
            // Tutaj mo¿esz dodaæ logikê dla interfejsu admina
        }
        else {
            std::cout << "Login failed. Invalid credentials or not an admin." << std::endl;
        }
        break;
    }
    case 2: {
        std::string userUsername, userPassword;
        std::cout << "Enter user username: ";
        std::cin >> userUsername;
        std::cout << "Enter user password: ";
        std::cin >> userPassword;

        User* loggedInUser = system.login(userUsername, userPassword);
        if (loggedInUser != nullptr && dynamic_cast<AdminUser*>(loggedInUser) == nullptr) {
            std::cout << "Logged in as user: " << loggedInUser->getUsername() << std::endl;
            // Tutaj mo¿esz dodaæ logikê dla interfejsu u¿ytkownika
        }
        else {
            std::cout << "Login failed. Invalid credentials or not a user." << std::endl;
        }
        break;
    }
    default:
        std::cout << "Invalid choice!" << std::endl;
        break;
    }

    // Usuwanie u¿ytkowników i zakoñczenie programu
    for (User* user : system.users) {
        delete user;
    }
    system.users.clear();

    return 0;
}

