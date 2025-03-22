#include "FileManager.h"

#include <iostream>
#include <fstream>
#include <thread>
void FileManager::Copy() {
	//Copy the file to another folder
}

void FileManager::Delete() {
	//Delete the file
}

void FileManager::Paste() {
	//Paste a file
}

void FileManager::Properties() {
	//get properties for file
}

void FileManager::Share(const std::string& filename, int type) {
	std::ifstream input{ filename };
	if (!input) {
		std::cout << "Could not open the file <" << filename << ">\n";
		return;
	}
	using namespace std;
	std::string line;
	switch (type) {
	case 0://Bluetooth
		std::cout << "Sending file through bluetooth...\n";
		while (std::getline(input, line)) {
			std::cout << '.';
			std::this_thread::sleep_for(500ms);
		}
		break;
	case 1://IR
		std::cout << "Sending file through IR...\n";

		while (std::getline(input, line)) {
			std::cout << '=';
			std::this_thread::sleep_for(800ms);
		}
		break;
	}
	std::cout << "Finished\n" ;
}
