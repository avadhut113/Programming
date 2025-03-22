#include "Clock.h"
#include "Timer.h"

int main() {
	Clock clock{} ;
	Timer t ;
	t.Attach(&clock) ;
	t.SimulateTimeChange() ;
	t.SimulateTimeChange() ;
}
