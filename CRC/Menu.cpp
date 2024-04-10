#include "Menu.h"
#include <iostream>

void Menu::loginAsAdmin() {
    std::string adminUsername, adminPassword;
    std::cout << "Enter admin username: ";
    std::cin >> adminUsername;
    std::cout << "Enter admin password: ";
    std::cin >> adminPassword;
    system.loadFromFile("users.txt");

    User* loggedInAdmin = system.login(adminUsername, adminPassword);
    if (loggedInAdmin != nullptr && dynamic_cast<AdminUser*>(loggedInAdmin) != nullptr) {
        std::cout << "Logged in as admin: " << loggedInAdmin->getUsername() << std::endl;
        // Tutaj mo¿esz dodaæ logikê dla interfejsu admina
    }
    else {
        std::cout << "Login failed. Invalid credentials or not an admin." << std::endl;
    }
}

void Menu::loginAsUser() {
    std::string userUsername, userPassword;
    std::cout << "Enter user username: ";
    std::cin >> userUsername;
    std::cout << "Enter user password: ";
    std::cin >> userPassword;
    system.loadFromFile("users.txt");

    User* loggedInUser = system.login(userUsername, userPassword);
    if (loggedInUser != nullptr && dynamic_cast<AdminUser*>(loggedInUser) == nullptr) {
        std::cout << "Logged in as user: " << loggedInUser->getUsername() << std::endl;
        // Tutaj mo¿esz dodaæ logikê dla interfejsu u¿ytkownika
    }
    else {
        std::cout << "Login failed. Invalid credentials or not a user." << std::endl;
    }
}

void Menu::display() {

    std::cout << "-------------------------------" << std::endl;
    std::cout << "Welcome to a Car Rental Company" << std::endl;
    std::cout << "Choose the option:" << std::endl;
    std::cout << "1. Admin" << std::endl;
    std::cout << "2. User" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    int choice;
    bool s = true;

    std::cin >> choice;
    while (s) {
        switch (choice) {
        case 1:
            loginAsAdmin();
            break;
        case 2:
            loginAsUser();
            break;
        case 3:
            std::cout << "Vamos" << std::endl;
            s = false;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
        }
    }
        system.users.clear();
}
