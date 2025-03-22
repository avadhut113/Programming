#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"


Logger::Logger() {
	m_Fp = fopen("log.txt", "w");
}




void Logger::Log(const std::string& message) {
	fprintf(m_Fp, "[%d][%s]%s\n", m_Level, m_Tag.c_str(), message.c_str());
	fflush(m_Fp) ;
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

