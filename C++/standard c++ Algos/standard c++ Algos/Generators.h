#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <ranges>
#include <iostream>

void generators()
{
	std::cout << "################################# std::fill and std::generate ################################" << std::endl;
	//Example of using std::fill and std::generate.
	std::vector<int> data1(5, 0);
	// data == {0, 0, 0, 0, 0}

	std::fill(data1.begin(), data1.end(), 11);
	// data == {11, 11, 11, 11, 11}

	std::ranges::generate(data1, []() { return 5; });
	// data == {5, 5, 5, 5, 5}

	 // iota-like
	std::ranges::generate(data1, [i = 0]() mutable { return i++; });
	// data == {0, 1, 2, 3, 4}


	std::cout << "################################# std::fill_n and std::generate_n ################################" << std::endl;
   //Example of using std::fill_n and std::generate_n.
	std::vector<int> data2;
	// data == {}

	std::fill_n(std::back_inserter(data2), 5, 11);
	// data == {11, 11, 11, 11, 11}

	std::ranges::generate_n(std::back_inserter(data2), 5,
		[]() { return 7; });
	// data == {11, 11, 11, 11, 11, 7, 7, 7, 7, 7}


	std::cout << "################################# std::iota ################################" << std::endl;
	//Example of using std::iota.
	std::vector<int> data3(9, 0);
	// data == {0, 0, 0, 0, 0, 0, 0, 0, 0}

	std::iota(data3.begin(), data3.end(), -4);
	// data == {-4, -3, -2, -1, 0, 1, 2, 3, 4}



	//Example of using both finite and infinite std::views::iota.
	std::vector<int> data4;

	std::ranges::transform(std::views::iota(1, 10), std::views::iota(5),
		std::back_inserter(data4), std::plus<>{});
	// data == { 6, 8, 10, 12, 14, 16, 18, 20, 22 }
}
