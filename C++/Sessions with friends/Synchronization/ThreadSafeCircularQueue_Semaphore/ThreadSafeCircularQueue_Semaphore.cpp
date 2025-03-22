//thread 1 --> even
//thread 2 -->  odd
//
//input = number  (series)

#include <iostream>
using namespace std;
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <chrono>

int limit = 20;
int number = 0;
std::mutex myMutex;
std::mutex myMutex2;
std::condition_variable cv1, cv2, cvEvenOdd;

void PrintEven()
{
	while (number < limit)
	{
		//std::lock_guard<std::mutex> myLock(myMutex);
		std::unique_lock<std::mutex> ul(myMutex);
		cv1.wait(ul, []() { return number % 2 == 0; });

		std::cout << std::this_thread::get_id() << " = " << number << std::endl;
		number++;

		ul.unlock();
		cv2.notify_one();
	}
}

void PrintOdd()
{
	while (number < limit)
	{
		std::unique_lock<std::mutex> ul(myMutex);
		cv2.wait(ul, []() { return number % 2 == 1; });

		std::cout << std::this_thread::get_id() << " = " << number << std::endl;
		number++;

		ul.unlock();
		cv1.notify_one();
	}
}

//void printevenodd(std::string str, int isevenodd)
//{
//	while (number < limit)
//	{
//		std::unique_lock<std::mutex> ul(myMutex2);
//		cvEvenOdd.wait(ul, [=]() { return number % 2 == isevenodd; });
//
//		std::cout << str << "   " << std::this_thread::get_id() << " = " << number << std::endl;
//		number++;
//
//		ul.unlock();
//		cvEvenOdd.notify_all();
//	}
//}

void printevenodd(std::string str, int isevenodd)
{
	while (number < limit)
	{
		std::unique_lock<std::mutex> ul(myMutex2);
		while (! (number % 2 == isevenodd)) { cvEvenOdd.wait(ul); }

		std::cout << str << "   " << std::this_thread::get_id() << " = " << number << std::endl;
		number++;

		ul.unlock();
		cvEvenOdd.notify_all();
	}
}

int main()
{
	//std::thread T2(PrintOdd);
	////std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	//std::thread T1(PrintEven);

	//if (T2.joinable()) T2.join();
	//if (T1.joinable()) T1.join();

	std::thread even_thread(printevenodd, "even", 0);
	std::thread odd_thread(printevenodd , "odd", 1);

	if (even_thread.joinable()) even_thread.join();
	if (odd_thread.joinable()) odd_thread.join();
	return 0;
}