#include "BlueTooth.h"
#include <iostream>
#include <fstream>
#include <thread>

BlueTooth::BlueTooth()
{

}

void BlueTooth::transfer(const std::string& filename)
{
    using namespace std;
    std::string line;

    std::ifstream input{ filename };

    std::cout << "Sending file through bluetooth...\n";
    while (std::getline(input, line)) {
        std::cout << '.';
        std::this_thread::sleep_for(500ms);
    }
}
