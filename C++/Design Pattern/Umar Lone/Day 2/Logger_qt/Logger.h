#pragma once
#include <string>
#include <mutex>

std::mutex mt;

class Logger {
	FILE *m_Fp{} ;
	int m_Level{} ;
	std::string m_Tag{} ;

    //static Logger logInstance;
    inline static Logger *logInstance;

    Logger() ;
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static inline Logger& GetInstance() {

//        duplicate check singleton
//        if(!logInstance)
//        {
//            std::lock_guard lg(mt);
//            if(!logInstance)
//            {
//                logInstance = new Logger();
//            }
//        }
//        return logInstance;

        //Mayers singleton
        static Logger logInstance;
        return logInstance;
    }
	void Log(const std::string &message) ;
	void SetLevel(int level) ;
	void SetTag(std::string tag) ;


	~Logger() ;
};

//Logger* Logger::logInstance = nullptr;
