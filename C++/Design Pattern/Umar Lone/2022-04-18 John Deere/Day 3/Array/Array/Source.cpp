#include <iostream>
#include <thread>

#include "Array.h"
void CompileTimeStrategy() {
		Array<int, MutexLock> arr{};
	for (int i = 0; i < 5; ++i) {
		arr.Add(i);
	}
	std::thread t1{ [&arr]() {
		for (int i = 0; i < 5; ++i) {
		arr.Add(i);
	}
	} };
	std::thread t2{ [&arr]() {
		for (int i = 10; i < 15; ++i) {
		arr.Add(i);
	}
	} };
	t1.join() ;
	t2.join() ;
	for (int i = 0; i < arr.Size(); ++i) {
		std::cout << arr.GetAt(i) << ' ';
	}
	std::vector<int> a ;
}

void DisplayHorizontal(const std::vector<std::string>& elements) {
	for (auto e : elements) {
		std::cout << e << ' ';
	}
}
void DisplayVertical(const std::vector<std::string>& elements) {
	for (auto e : elements) {
		std::cout << e << '\n';
	}
}
void DisplayGrid(const std::vector<std::string>& elements) {
	size_t count = 0 ;
	for (auto e : elements) {
		if(count == 3) {
			std::cout << '\n' ;
			count = 0 ;
		}else {
			std::cout << e << ' ';
			++count ;
		}
	}
}


int main() {
	Array<int> values{1,2,3,4} ;
	//values.Display(0) ;
	std::cout << "\n" ;
	Array<std::string> names{"Bansode Navnath", "Gupta Sukrati", "Jain Gaurav", "Umar Lone", "Kshirsagar Vinod Sunil", "Kurlekar Anand"} ;
	names.SetStrategy(DisplayGrid) ;

	names.Display() ;
}
