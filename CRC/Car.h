#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Car {
public:
    std::string producent;
    int milage;
    int hp;
    std::string model;
    int productionYear;
    std::vector<Car> cars;

    Car(std::string pr = "Unknown", int m = 0, int p = 0, std::string mo = "Unknown", int pY = 0);

    void loadFromFile(const std::string& filename);

    void displayCars();
};


