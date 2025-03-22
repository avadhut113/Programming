#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"

#include <iostream>
#include <mutex>
#include <stdexcept>
//Logger Logger::m_Instance{} ;
//Logger *Logger::m_pInstance{} ;

Logger::Logger() {
	m_Fp = fopen("log.txt", "w");
}




void Logger::Log(const std::string& message) {
	fprintf(m_Fp, "[%d][%s]%s\n", m_Level, m_Tag.c_str(), message.c_str());
}

void Logger::SetLevel(int level) {
	m_Level = level;
}

void Logger::SetTag(std::string tag) {
	m_Tag = std::move(tag);
}

Logger::~Logger() {
	fclose(m_Fp);
}

