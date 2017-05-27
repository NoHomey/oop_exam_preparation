#include <iostream>
#include <fstream>
#include "Appointment.h"

int main() {
    std::ifstream file("calendar.txt");
    if(!file.good()) {
        std::cout << "Could not open file" << std::endl;
        return 0;
    }
    while(true) {
        Appointment app;
        try {
            file >> app;
        } catch(std::exception& error) {
            std::cout << "Error: " << error.what() << std::endl;
        }
        std::cout << app << std::endl;
        if(file.eof()) {
            break;
        }
    }

    return 0;
}