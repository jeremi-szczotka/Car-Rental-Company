#pragma once
#include "Car.h"
class Rent : public Car {
public:
	using Car::Car;
	std::vector <Rent> rcars;
	void rentAcar(int l, const std::string& filename, const std::string& rentedFilename);
	void returnCar(int o, const std::string& filename, const std::string& rentedFilename);
	bool displayRented(const std::string& filename);
	void loadRented(const std::string& filename);
	void rClear();
};

