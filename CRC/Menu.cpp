#include "Menu.h"
#include <iostream>

void Menu::loginAsAdmin() {
	std::string adminUsername, adminPassword;
	system.loadFromFile("users.txt");
	std::cout << "Enter admin username: ";
	std::cin >> adminUsername;
	std::cout << "Enter admin password: ";
	std::cin >> adminPassword;

	User* loggedInAdmin = system.login(adminUsername, adminPassword);
	if (loggedInAdmin != nullptr && dynamic_cast<AdminUser*>(loggedInAdmin) != nullptr) {
		std::cout << "Logged in as admin: " << loggedInAdmin->getUsername() << std::endl;
		Car c1;
		c1.loadFromFile("cars.txt");
		int c = 0;
		bool x = true;
		while (x) {
			switch (c) {
			case 0:
				std::cout << "-------------------------------" << std::endl;
				std::cout << "Choose your option:" << std::endl;
				std::cout << "1. Car list." << std::endl;
				std::cout << "2. Add a car." << std::endl;
				std::cout << "3. Delete a car." << std::endl;
				std::cout << "4. Quit." << std::endl;
				std::cout << "--------------------------------" << std::endl;
				std::cin >> c;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input, try again:" << std::endl;
					std::cout << " " << std::endl;
					c = 0;
				}
				else continue;
				break;
			case 1:
				c1.displayCars();
				c = 0;
				Car::cars.resize(0);
				break;
			case 2:
				c1.addCar("cars.txt");
				c = 0;
				Car::cars.resize(0);
				break;
			case 3:
				int k;
				c1.displayCars();
				std::cout << "Chose a car to delete: ";
				std::cin >> k;
				c1.delete_car(k, "cars.txt");
				c = 0;

				break;
			case 4:
				std::cout << "Vamos" << std::endl;
				x = false;
				break;
			default:
				std::cout << "Invalid choice!" << std::endl;
				
				c = 0;
				break;
			}
		}
	}
	else {
		std::cout << "Login failed. Invalid credentials or not an admin." << std::endl;
		loginAsAdmin();
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
		Car c1;
		Rent g1;
		
		c1.loadFromFile("cars.txt");
		int c = 0;
		bool x = true;
		while (x) {
			switch (c) {
			case 0:
				std::cout << "-------------------------------" << std::endl;
				std::cout << "Choose your option:" << std::endl;
				std::cout << "1. Car list." << std::endl;
				std::cout << "2. Rent a car." << std::endl;
				std::cout << "3. Return a vehicle." << std::endl;
				std::cout << "4. Quit" << std::endl;
				std::cout << "--------------------------------" << std::endl;
				std::cin >> c;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input, try again:" << std::endl;
					std::cout << " " << std::endl;
					c = 0;
				}
				else continue;
				break;
			case 1:
				c1.displayCars();
				c = 0;
				break;
			case 2:				
				int l;
				c1.displayCars();
				std::cout << "Chose a car to rent." << std::endl;
				std::cin >> l;
				
				g1.rentAcar(l,"cars.txt","rented.txt");
				c1.getter(l);
				c = 0;
				break;
			case 3:
				int o;
				g1.loadRented("rented.txt");
				if (g1.displayRented("rented.txt")) {
					std::cout << "Chose a car to rent." << std::endl;
					std::cin >> o;
					g1.returnCar(o, "cars.txt", "rented.txt");
					g1.rClear();
					
				}
				c = 0;
				break;
			case 4:
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
		loginAsUser();
	}
}

void Menu::display() {
	bool s = true;
	int choice = 0;
	while (s) {
		switch (choice) {
		case 0:
			std::cout << "-------------------------------" << std::endl;
			std::cout << "Welcome to a Car Rental Company" << std::endl;
			std::cout << "Choose the option:" << std::endl;
			std::cout << "1. Admin" << std::endl;
			std::cout << "2. User" << std::endl;
			std::cout << "3. Quit" << std::endl;
			std::cout << "--------------------------------" << std::endl;
			std::cin >> choice;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input, try again:" << std::endl;
				std::cout << " " << std::endl;
				choice = 0;
			}
			else continue;
			break;
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
			choice = 0;
			break;
		}
	}
}
