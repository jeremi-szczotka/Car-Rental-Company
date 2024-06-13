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

