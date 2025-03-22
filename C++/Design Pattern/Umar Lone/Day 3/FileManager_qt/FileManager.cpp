#include "FileManager.h"
#include "TransferPolicy.h"

#include <iostream>
#include <fstream>
#include <thread>

class NoTransfer : public TransferPolicy
{
public :
    void transfer(const std::string& filename)
    {
        std::cout << "NO Transfer";
    }

};

FileManager::FileManager()
{
    //NoTransfer* trs = new NoTransfer ;

    m_trasferPlolicy = new NoTransfer;
}

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
    //if ( m_trasferPlolicy )
        m_trasferPlolicy->transfer(filename);
}

void FileManager::setPolicy(TransferPolicy *policy)
{
    m_trasferPlolicy = policy;
}
