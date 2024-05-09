#include "Car.h"

Car::Car(std::string pr, std::string mo, int p, int m, int pY,bool iR) : producent(pr), model(mo), hp(p), milage(m), productionYear(pY), isRented(iR) {}

void Car::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            if (iss >> producent >> model >> hp >> milage >> productionYear >> isRented) {
                cars.push_back(Car(producent, model, hp, milage, productionYear, isRented));
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Car::displayCars() {
    for (const auto& car : cars) {
        std::cout << "Producent: " << car.producent << ", Model: " << car.model << ", HP: " << car.hp << ", Milage: " << car.milage << ", Production Year: " << car.productionYear;
        if (car.isRented) {
            std::cout << " Car is rented" << std::endl;
        }
        else{
            std::cout << " Car is available" << std::endl;
        }
    }
}

void Car::addCar(const std::string& filename) {
    std::string pr, mo;
    int p, m, pY;
    bool iR = false;

    std::cout << "Provide producent of a car: ";
    std::cin >> pr;
    std::cout << "Provide model of a car: ";
    std::cin >> mo;
    std::cout << "Provide horsepower (hp): ";
    std::cin >> p;
    std::cout << "Provide milage of a care (km): ";
    std::cin >> m;
    std::cout << "Provide year of production ";
    std::cin >> pY;

    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << pr << " " << mo << " " << p << " " << m << " " << pY << " " << iR << std::endl;
        cars.emplace_back(pr, mo, p, m,pY, true);
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

}

