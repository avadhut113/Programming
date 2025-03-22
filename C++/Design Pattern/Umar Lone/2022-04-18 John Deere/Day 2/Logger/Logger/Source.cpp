#include <thread>

#include "Logger.h"
void F() {
	Logger &l = Logger::GetInstance()  ;
	l.Log("Test") ;
}
int main() {
	std::thread t1{[]() {
	Logger &logger = Logger::GetInstance();
		logger.Log("Thread 1 started") ;
	}} ;

	std::thread t2{[]() {
	Logger &logger = Logger::GetInstance();
		logger.Log("Thread 2 started") ;
	}} ;

	t1.join() ;
	t2.join() ;
	return 0;
	Logger &logger = Logger::GetInstance();
	logger.Log("Application has started");
	F() ;
	logger.Log("Application is terminating");
}


