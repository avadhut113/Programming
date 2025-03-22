// Atomi_Flag_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>

void run_atomic_flag()
{
	std::atomic_flag flag = ATOMIC_FLAG_INIT;

	std::cout << "1.Flag value :" << flag.test_and_set() << std::endl;
	std::cout << "2.Flag value :" << flag.test_and_set() << std::endl;

	std::cout << "1.Flag value :" << flag._Storage << std::endl;
	std::cout << "1.Flag value :" << flag._Storage << std::endl;
	std::cout << "1.Flag value :" << flag._Storage << std::endl;

	flag.clear();
	std::cout << "3.Flag value :" << flag.test_and_set() << std::endl;

	std::cout << "1.Flag value :" << flag._Storage << std::endl;
}

void run_atomic_bool()
{
	std::atomic<bool> var(false);

	std::cout << "var :" << var << std::endl;

	std::cout << "is var lock free :" << var.is_lock_free() << std::endl;

	std::atomic_bool var2(true);

	var.store(var2);
	std::cout << "var :" << var.load() << std::endl;

	std::cout << "var :" << var.exchange(false) << std::endl;
	std::cout << "var :" << var.load() << std::endl;


	var.store(true);
	std::cout << "var :" << var.load() << std::endl;

}

void run_atomic_int()
{
	std::atomic<int> x(20);

	int expected = 10;

	std::cout << "previous expected value :" << expected << std::endl;

	bool result = x.compare_exchange_weak(expected, 6);

	std::cout << "Result :" << (result ? "Yes" : "No") << std::endl;
	std::cout << "currect expected value :" << expected << std::endl;
	std::cout << " x :" << x.load() << std::endl;

}

void run_atomic_pointer()
{
	std::atomic<int*> x;
	int arr[10];
	for (int i = 0; i < 10;i++) {
		arr[i] = i + 1;
	}

	x = arr;
	
	std::cout << "is var lock free :" << (x.is_lock_free()?"Yes":"No") << std::endl;
	std::cout << "x : "<< *x.load() << std::endl;

	int* y = arr + 3;
	std::cout << "y : " << *y << std::endl;

	x.store(y);
	std::cout << "x : " << *x.load() << std::endl;
	bool res = x.compare_exchange_weak(y, arr + 5);
	std::cout << ( res? "Yes" : "No") << std::endl;
	std::cout << "after exchange x : " << *x.load() << std::endl;
	std::cout << "after exchange y : " << *y << std::endl;

	//fetch add
	int* previous = x.fetch_add(2);
	std::cout << "after fetch add 2 x : " << *x.load() << std::endl;
	std::cout << "before fetch add 2 x : " << *previous << std::endl;

	x++;
	std::cout << "x : " << *x.load() << std::endl;


}

int main()
{
	//run_atomic_flag();
	//run_atomic_bool();
	run_atomic_int();
	run_atomic_pointer();
}

