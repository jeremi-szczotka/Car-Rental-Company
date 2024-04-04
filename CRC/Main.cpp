#include <iostream>
#include "Admin.h"





int main() {

	Admin a1;
	User u1; 
	/*User u1;*/


	std::cout << "-----------------" << std::endl;
	std::cout << "Welcome to a Car Rental Company" << std::endl;
	std::cout << "Chose who you are xD:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1.Admin" << std::endl;
	std::cout << "2.User" << std::endl;
	std::cout << "-----------------" << std::endl;
	int a;
	while (true) {
		std::cin >> a;
		switch (a) {
		case 1:
			a1.add_admin();
			if (a1.admninInterface == 1) {

				std::cout << "-----------------" << std::endl;
				std::cout << "Jestem adminem" << std::endl;
			}
			break;
		case 2:
		/*	u1.user_add();*/
			break;



			{
		default:
			break;
			}


			return 0;
		}
	}
	return 0;
}