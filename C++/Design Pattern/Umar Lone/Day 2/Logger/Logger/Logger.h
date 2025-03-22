#pragma once
#include <string>

class Logger {
	FILE *m_Fp{} ;
	int m_Level{} ;
	std::string m_Tag{} ;
public:
	Logger() ;
	void Log(const std::string &message) ;
	void SetLevel(int level) ;
	void SetTag(std::string tag) ;
	~Logger() ;
};
