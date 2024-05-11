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
    bool isRented;

    Car(std::string pr = "Unknown", std::string mo = "Unknown", int p = 0, int m = 0, int pY = 0,bool iR=0);
    void delete_car(int k, const std::string& filename);
    void loadFromFile(const std::string& filename);
    void addCar(const std::string& filename);
    void displayCars();
};


