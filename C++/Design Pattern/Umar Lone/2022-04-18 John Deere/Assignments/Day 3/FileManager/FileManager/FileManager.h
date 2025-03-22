#pragma once
#include <string>

class FileManager {
public:
	void Copy() ;
	void Paste() ;
	void Delete() ;
	void Properties() ;
	void Share(const std::string &filename, int type) ;
};
