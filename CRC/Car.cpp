#include "Car.h"

Car::Car(std::string pr, std::string mo, int p, int m, int pY) : producent(pr), model(mo), hp(p), milage(m), productionYear(pY) {}

void Car::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            if (iss >> producent >> model >> hp >> milage >> productionYear ) {
                cars.push_back(Car(producent, model, hp, milage, productionYear));
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
void Car::delete_car(int k, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    std::vector<std::string> lines;
    std::string line;
    int lineNumber = 1;
    while (std::getline(file, line)) {
        if (lineNumber != k) {
            lines.push_back(line);
        }
        lineNumber++;
    }

    file.close();
    if (k<1 || k>cars.size()) {
        std::cerr << "Error. Wrong number pls try again\n";
        return;
    }
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    for (const auto& l : lines) {
        outFile << l << std::endl;
    }

    outFile.close();    
    auto it = cars.begin() + k-1;
    cars.erase(it);
    std::cout << "Car has been deleted" << std::endl;
}




void Car::displayCars() {
    int k = 1;
    for (const auto& car : cars) {
        
        std::cout << k++ << ". Producent: " << car.producent << ", Model: " << car.model << ", HP: " << car.hp << ", Milage: " << car.milage << ", Production Year: " << car.productionYear << std::endl;
       
    }
}

void Car::getter(int j)
{
    auto it = cars.begin() + j - 1;
    cars.erase(it);
}

void Car::addCar(const std::string& filename) {
    std::string pr, mo;
    int p, m, pY;
    
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
        file << pr << " " << mo << " " << p << " " << m << " " << pY << " "  << std::endl;
        cars.emplace_back(pr, mo, p, m,pY);
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

}

