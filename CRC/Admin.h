#pragma once
#include "User.h"
#include <iostream>
class Admin
{
public:
	std::string login;
	std::string password;
	bool swi;
	bool admninInterface;

	//constructor
	Admin();

	bool getadmninInterface(); 
	void show();
	void add_admin();
	void delete_user();
};

