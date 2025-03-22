#pragma once

#include <thread>
#include <atomic>

class CBarrierSpin
{
	unsigned const threshHold;
	std::atomic<unsigned> count;
	std::atomic<unsigned> generation;

public:
	explicit CBarrierSpin(unsigned threash_hold) : threshHold(threash_hold) , count(threash_hold), generation(0){}
	void wait() {
		unsigned const my_generation = generation;

		if (!--count) {
			count = threshHold;
			++generation;
		} 
		else {
			while (generation == my_generation)
				std::this_thread::yield();
		}
	}
};