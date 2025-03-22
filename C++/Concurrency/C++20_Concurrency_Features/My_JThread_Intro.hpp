// JThread_Intro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include<future>

using namespace std::literals;

class interrupt_flag
{
	bool local_flag;
public:
	void set() {
		local_flag = true;
	}

	bool is_set() {
		return local_flag;
	}
};

thread_local interrupt_flag this_thread_flag;

class my_jthread
{
	std::thread _thread;
	interrupt_flag* flag;

public:
	template<typename functype>
	my_jthread(functype f) {
		std::promise<interrupt_flag*> p;
		_thread = std::thread([f, &p] {
				p.set_value(&this_thread_flag);
				f();
			});

		flag = p.get_future().get();
	}

	void interrupt() {
		flag->set();
	}

	~my_jthread() {
		if (_thread.joinable())
			_thread.join();
	}
};

bool interrupt_point()
{
	if (this_thread_flag.is_set())
		return true;

	return false;
}


void Test_MuJThread()
{
	/*std::jthread interaptable([](std::stop_token token) {
										int counter = 0;
										while (counter < 10) {
											if (token.stop_requested())
												return;

											std::this_thread::sleep_for(0.5s);
											std::cout << "this is interuptable thread :" << counter++ << std::endl;
										}
								   }); 

	std::jthread noninteraptable([]() {
										int counter = 0;
										while (counter < 10) {

											std::this_thread::sleep_for(0.5s);
											std::cout << "this is non-interuptable thread :" << counter++ << std::endl;
										}
								   });

	std::this_thread::sleep_for(1.0s);
	interaptable.request_stop();
	noninteraptable.request_stop();
	*/

	my_jthread interaptable([]() {
		int counter = 0;
		while (counter < 10) {
			if (interrupt_point())
				return;

			std::this_thread::sleep_for(0.5s);
			std::cout << "this is interuptable thread :" << counter++ << std::endl;
		}
		});

	my_jthread noninteraptable([]() {
		int counter = 0;
		while (counter < 10) {

			std::this_thread::sleep_for(0.5s);
			std::cout << "this is non-interuptable thread :" << counter++ << std::endl;
		}
		});

	std::this_thread::sleep_for(1.0s);
	interaptable.interrupt();
	noninteraptable.interrupt();

	std::cout << std::endl;

}
