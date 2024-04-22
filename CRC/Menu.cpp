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
        // Tutaj mo�esz doda� logik� dla interfejsu u�ytkownika
        Car c1;
        c1.loadFromFile("cars.txt");
        // Tutaj mo�esz doda� logik� dla interfejsu admina
        
        int c=0;
        bool x = true;
        while (x) {
            switch (c) {
            case 0:
                std::cout << "-------------------------------" << std::endl;
                std::cout << "Choose your option:" << std::endl;
                std::cout << "1. Car list." << std::endl;
                std::cout << "2. Rent a car." << std::endl;
                std::cout << "3. Quit" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cin >> c;
                break; 
            case 1:
                c1.displayCars();
                c = 0;
                break;
            case 2:

                break;
            case 3:
                std::cout << "Vamos" << std::endl;
                x = false;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
            }
        }
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
            s = false;
            break;
        case 2:
            loginAsUser();
            s = false;
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
