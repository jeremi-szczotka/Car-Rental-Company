#include "Admin.h"
Admin::Admin() {
	login = "1";
	password = "2";
	swi = 0;
	admninInterface = 0;
}
void Admin::show() {
	std::cout << login << std::endl;
	std::cout << password << std::endl;
}

void Admin::add_admin() {
	
	while (swi == 0) {
		std::string login1;
		std::string password1;
		std::cout << "Provide login" << std::endl;
		std::cin >> login1;
		std::cout << "Provide password" << std::endl;
		std::cin >> password1;
		if (login1 == login && password1 == password) {
			std::cout << "Loging in was sucsesful" << std::endl;
			swi = 1;
			admninInterface = 1;
		}
		else std::cout << "Wrong login or password." << std::endl << "Try again" << std::endl << std::endl;
	}
}

void Admin::delete_user() {


}