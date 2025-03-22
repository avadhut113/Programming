#pragma once
#include <string>

class Logger {
	FILE *m_Fp{} ;
	int m_Level{} ;
	std::string m_Tag{} ;
	//static Logger m_Instance;

	//Inline static requires C++17
	//inline static Logger *m_pInstance{} ; //Lazy instantiation

	static Logger *m_pInstance ; //Lazy instantiation
	Logger() ;
public:
	Logger(const Logger &) =delete ;
	Logger & operator=(const Logger&) = delete ;
	void Log(const std::string &message) ;
	void SetLevel(int level) ;
	void SetTag(std::string tag) ;
	~Logger() ;
	static Logger & GetInstance() ;
};
