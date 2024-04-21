#include "Car.h"

Car::Car(std::string pr, int m, int p, std::string mo, int pY) : producent(pr), milage(m), hp(p), model(mo), productionYear(pY) {}

void Car::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            if (iss >> producent >> milage >> hp >> model >> productionYear) {
                cars.push_back(Car(producent, milage, hp, model, productionYear));
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
        std::cout << "Producent: " << car.producent << ", Milage: " << car.milage << ", HP: " << car.hp << ", Model: " << car.model << ", Production Year: " << car.productionYear << std::endl;
    }
}
