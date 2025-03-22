#include "Logger.h"
void F() {
	Logger l ;
	l.Log("Test") ;
}
int main() {
	Logger logger ;
	logger.Log("Application has started");
	F() ;
	logger.Log("Application is terminating");
}


