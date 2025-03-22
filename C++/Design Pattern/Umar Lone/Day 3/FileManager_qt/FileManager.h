#pragma once
#include <string>

class TransferPolicy;

class FileManager {
    TransferPolicy* m_trasferPlolicy = nullptr;
public:
    FileManager();
    FileManager(TransferPolicy* policy) : m_trasferPlolicy(policy){}
	void Copy() ;
	void Paste() ;
	void Delete() ;
	void Properties() ;
	void Share(const std::string &filename, int type) ;
    void setPolicy(TransferPolicy* policy);
};
