
#include "UploadCSV.h"
#include <iostream>
#include <fstream>
#include <string>


void UploadCSV::execute() {
    std::cout << "Please enter the path of the file: ";
    std::cin >> filePath;

    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            fileContent += line + '\n';
        }
        file.close();

        // Send fileContent to server
        // ...

        // Receive server response
        std::string serverResponse;
        // ...

        if (serverResponse == ".Upload complete") {
            std::cout << "Upload complete." << std::endl;
        } else {
            std::cout << "Server error: " << serverResponse << std::endl;
        }
    } else {
        std::cout << "Invalid input" << std::endl;
    }
}
