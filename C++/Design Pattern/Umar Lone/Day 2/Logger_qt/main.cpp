#include "Logger.h"

void InitWindowSys()
{
    Logger& log = Logger::GetInstance() ;
    log.Log("Init window system");
}

void InitlinuxSys()
{
    Logger& log = Logger::GetInstance() ;
    log.Log("Init Linux system");
}

int main() {

    Logger& logger = Logger::GetInstance() ;

    InitWindowSys();
    InitlinuxSys();


    logger.Log("Application has started");
    logger.Log("Application is terminating");
    return 0;
}


