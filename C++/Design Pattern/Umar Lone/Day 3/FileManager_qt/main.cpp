#include <iostream>

#include "FileManager.h"
#include "TransferPolicy.h"
#include "BlueTooth.h"
#include "InfraRed.h"


void OpenFileManager() {

    TransferPolicy* policy = new BlueTooth;
    FileManager mgr ;
	mgr.Copy() ;
	std::cout << "Choose (0 BT, 1, IR)?" ;
	int type{} ;
	std::cin >> type ;
    if(type == 0)
         mgr.setPolicy(new BlueTooth);
    else if(type == 1)
        mgr.setPolicy(new InfraRed);

    mgr.Share("PinFile.txt", type) ;
}

int main() {
	OpenFileManager() ;
}
