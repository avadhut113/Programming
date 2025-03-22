#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"

#include <iostream>
#include <mutex>

Logger *Logger::m_pInstance{} ;
Logger::Logger() {
	std::cout << "Logger()\n";
	m_Fp = fopen("log.txt", "w");

	atexit([]() {
		delete m_pInstance;
	});

}

void Logger::Log(const std::string& message) {
	fprintf(m_Fp, "[%d][%s]%s\n", m_Level, m_Tag.c_str(), message.c_str());
	fflush(m_Fp);
}

void Logger::SetLevel(int level) {
	m_Level = level;
}

void Logger::SetTag(std::string tag) {
	m_Tag = std::move(tag);
}

Logger::~Logger() {
	fclose(m_Fp);
	std::cout << "~Logger()\n";
}
std::mutex mtx;
std::once_flag flag ;
Logger& Logger::GetInstance() {
	////Double-checked locking pattern
	//if (!m_pInstance) {
	//	std::lock_guard guard{ mtx };
	//	if (!m_pInstance)
	//		m_pInstance = new Logger{};
	//}

	//std::call_once(flag, []() {
	//	m_pInstance = new Logger{} ;
	//}) ;

	//return *m_pInstance;


	//Meyer's singleton
	static Logger instance;
	return instance ;
}

