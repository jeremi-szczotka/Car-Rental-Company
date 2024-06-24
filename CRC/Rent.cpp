#include "Rent.h"
void Rent::rentAcar(int l, const std::string& filename, const std::string& rentedFilename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    int lineNumber = 1;
    while (std::getline(file, line)) {
        if (lineNumber != l) {
            lines.push_back(line);
        }
        else {
            std::ofstream rentedFile(rentedFilename, std::ios_base::app);
            if (rentedFile.is_open()) {
                rentedFile << line << std::endl;
                rentedFile.close();
            }
            else {
                std::cerr << "Error. Couldn't open rented file: " << rentedFilename << std::endl;
            }
        }
        lineNumber++;
    }

    file.close();
    

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error. Couldn't save file: " << filename << std::endl;
        return;
    }

    for (const auto& l : lines) {
        outFile << l << std::endl;
    }

    outFile.close();
    std::cout << "Line " << l << " has been deleted from file." << std::endl;
}
void Rent::returnCar(int o, const std::string& filename, const std::string& rentedFilename) {

    std::ifstream file(rentedFilename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << rentedFilename << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    int lineNumber = 1;
    while (std::getline(file, line)) {
        if (lineNumber != o) {
            lines.push_back(line);
        }
        else {
            std::ofstream File(filename, std::ios_base::app);
            if (File.is_open()) {
                File << line << std::endl;
                File.close();
            }
            else {
                std::cerr << "Error. Couldn't open rented file: " << filename << std::endl;
            }
        }
        lineNumber++;
    }
    auto it = rcars.begin() + o - 1;
    rcars.erase(it);
    file.close();

    std::ofstream outFile(rentedFilename);
    if (!outFile.is_open()) {
        std::cerr << "Error. Couldn't save file: " << rentedFilename << std::endl;
        return;
    }

    for (const auto& o : lines) {
        outFile << o << std::endl;
    }

    outFile.close();
    std::cout << "Car " << o << " has been returned." << std::endl;
}
void Rent::loadRented(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            if (iss >> producent >> model >> hp >> milage >> productionYear >> isRented) {
                rcars.push_back(Rent(producent, model, hp, milage, productionYear, isRented));
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
void Rent::displayRented(const std::string& filename)
 {
    int k = 1;
    for (const auto& Rent : rcars) {

        std::cout << k++ << ". Producent: " << Rent.producent << ", Model: " << Rent.model << ", HP: " << Rent.hp << ", Milage: " << Rent.milage << ", Production Year: " << Rent.productionYear << std::endl;
       
    }
}
