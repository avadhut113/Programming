#include "InfraRed.h"
#include <iostream>
#include <fstream>
#include <thread>

InfraRed::InfraRed()
{

}

void InfraRed::transfer(const std::string& filename)
{
    using namespace std;
    std::string line;

    std::ifstream input{ filename };

    std::cout << "Sending file through IR...\n";

    while (std::getline(input, line)) {
        std::cout << '=';
        std::this_thread::sleep_for(800ms);
    }
}
