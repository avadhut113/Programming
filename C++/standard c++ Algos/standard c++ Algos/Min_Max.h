#pragma once
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <span>

struct X {
	static int copy_cnt;
	X(int v) : value(v) {}
	X(const X& other) : value(other.value) {
		++copy_cnt;
	}
	int value;
	friend auto operator <=>(const X&, const X&) = default;
};

struct Y{
	int rank;
	auto operator<=>(const Y&) const = default;
};

int X::copy_cnt = 0;

void min_max()
{
	std::cout << "################################# std::initializer_list leads to excessive copies ################################" << std::endl;
	//Example demonstrating case when utilizing std::initializer_list leads to excessive copies.
	X a{ 1 }, b{ 2 }, c{ 3 }, d{ 4 }, e{ 5 };
	auto max1 = std::max({ a, b, c, d, e });
	// max.value == 5
	// X::copy_cnt == 6

	//Example demonstrating the valid and invalid uses for const_cast.
	int x1 = 10, y1 = 20;

	auto& v = const_cast<int&>(std::min(x1, y1));
	v = 5;
	// x == 5, y == 20

	// !IMPORTANT! the following compiles, but is undefined behaviour
	// i.e. the program is ill-formed
	const int z1 = 3;
	auto& w = const_cast<int&>(std::min(x1, z1));
	w = 10;


	std::cout << "################################# std::min / std::max ################################" << std::endl;
	//Example demonstrating use of std::min and std::max.
	int x2 = 10, y2 = 20;
	int min = std::min(x2, y2);
	// min == 10

	std::string hello = "hello", world = "world";
	std::string& universe = const_cast<std::string&>(std::max(hello,
		world));
	universe = "universe";

	std::string greeting = hello + " " + world;
	// greeting == "hello universe"

	int j = 20;
	auto& k = std::max(5, j);
	// IMPORTANT! only works because 5 < j
	// would produce dangling reference otherwise
	// k == 20

	std::cout << "################################# std::minmax ################################" << std::endl;
   //Example demonstrating use of std::minmax.

	X a1{ 1 }, b1{ 2 };
	auto [first, second] = std::minmax(b1, a1);
	// first.rank == 1, second.rank == 2

	 // Operating on prvalues requires capture by value
	std::pair<int, int> result = std::minmax(5, 10);
	// result.first = 5, result.second = 10



   //Example demonstrating use of std::minmax.
	Y a2{ 1 }, b2{ 2 };
	auto [first2, second2] = std::minmax(b2, a2);
	// first.rank == 1, second.rank == 2

	 // Operating on prvalues requires capture by value
	std::pair<int, int> result2 = std::minmax(5, 10);
	// result.first = 5, result.second = 10


	std::cout << "################################# range variants of std::min, std::max and std::minmax ################################" << std::endl;
   //Example of std::initializer_list and range variants of std::min, std::max and std::minmax.
	auto min2 = std::min({ 5, 3, -2, 0 });
	// min == -2

	auto minmax2 = std::minmax({ 5, 3, -2, 0 });
	// minmax.first == -2, minmax.second == 5

	std::list<int> data2{ 5, 3, -2, 0 };
	auto max2 = std::ranges::max(data2);
	// max == 5


	std::cout << "################################# std::clamp ################################" << std::endl;
	//Eamples of using std::clamp with prvalues and with lvalues and const_cast to get mutable acess to the original variable.
		int a3 = std::ranges::clamp(10, 0, 20);
	// a == 10 (0 < 10 && 10 < 20)

	int b3 = std::clamp(-20, 0, 20);
	// b == 0 (-20 < 0)

	int c3 = std::clamp(30, 0, 20);
	// c == 20 ( 30 > 20 )


	//Examples of using std::clamp with prvalues and with lvalues and const_cast to get mutable access to the original variable.
	int a4 = std::ranges::clamp(10, 0, 20);
	// a == 10 (0 < 10 && 10 < 20)

	int b4 = std::clamp(-20, 0, 20);
	// b == 0 (-20 < 0)

	int c4 = std::clamp(30, 0, 20);
	// c == 20 ( 30 > 20 )

	int x4 = 10, y4 = 20, z4 = 30;
	int& w4 = const_cast<int&>(std::clamp(z4, x4, y4));
	w4 = 99;
	// x == 10, y == 99, z == 30


	std::cout << "################################# std::min_element/std::max_element/std::minmax_element ################################" << std::endl;
   //Example of using element versions of min-max algorithms.
	std::vector<int> data5 = { 5, 3, -2 , 0 };
	auto i5 = std::min_element(data5.begin(), data5.end());
	// *i == -2 (i.e. data[2])
	auto j5 = std::max_element(data5.begin(), data5.end());
	// *j == 5 (i.e. data[0])

	auto k5 = std::minmax_element(data5.begin(), data5.end());
	// *k.first == -2, *k.second == 5

	//Example demonstrating protection from dangling iterators.
	auto i6 = std::ranges::min_element(std::vector<int>{5, 3, -2, 0});
	// decltype(i) == std::ranges::dangling

	std::vector<int> data6 = { 5, 3, -2 , 0 };
	auto j6= std::ranges::min_element(std::span(data6.begin(), 2));
	// *j == 3, std::span is a borrowed_range
}