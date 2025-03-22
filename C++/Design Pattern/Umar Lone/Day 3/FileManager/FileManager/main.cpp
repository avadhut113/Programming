#include <iostream>

#include "FileManager.h"


void OpenFileManager() {
	FileManager mgr ;
	mgr.Copy() ;
	std::cout << "Choose (0 BT, 1, IR)?" ;
	int type{} ;
	std::cin >> type ;
	mgr.Share("main.cpp", type) ;
}

int main() {
	OpenFileManager() ;
}
