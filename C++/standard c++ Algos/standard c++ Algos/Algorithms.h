#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <list>

struct Custom {
	explicit Custom(double value) : value_(value) {}
	double getValue() { return value_; }
private:
	double value_;
};

namespace Library {
	struct Storage {
		int iValue;
		short sValue;
		char cVal;
	};

	void swap(Storage& left, Storage& right) {
		std::ranges::swap(left.iValue, right.iValue);
		std::ranges::swap(left.sValue, right.sValue);
		std::ranges::swap(left.cVal, right.cVal);
	}

	std::ostream& operator<<(std::ostream& os, Storage& st) {
		os << st.iValue << " " << st.sValue << " " << st.cVal << std::endl;
		return os;
	}
}

struct Point {

	int x;
	int y;

	// pre-C++20 lexicographical less-than
	friend bool operator<(const Point& left, const Point& right) {
		if (left.x != right.x)
			return left.x < right.x;
		return left.y < right.y;
	}

	// default C++20 spaceship version of lexicographical comparison
	friend auto operator<=>(const Point&, const Point&) = default;

	// manual version of lexicographical comparison using operator <=>
	friend auto operator<=>(const Point& left, const Point& right) {
		if (left.x != right.x)
			return left.x <=> right.x;
		return left.y <=> right.y;
	}
};

template <typename It, typename Cond>
	requires std::forward_iterator<It>
&& std::indirectly_swappable<It, It>
&& std::predicate<Cond>
auto partition(It first, It last, Cond cond) {

	while (first != last && cond(first)) 
		++first;

	if (first == last) 
		return last;

	for (auto it = std::next(first); it != last; it++) {
		if (!cond(it)) 
			continue;

		std::iter_swap(it, first);
		++first;
	}
	return first;
}

void standard_algos()
{
	std::cout << "################################# std::for_each ################################" << std::endl;
	std::vector<Custom> data1(10, Custom{ 1.0 });

	double sum = 0;
	std::ranges::for_each(data1,
		[&sum](auto v) { sum += v; },
		&Custom::getValue);
	// sum == 10.0


	std::cout << "################################# std::swap ################################" << std::endl;

	int a = 1, b = 2;
	std::ranges::swap(a, b); // 3-step-swap

	Library::Storage j{ 26789, 1, 'a'}, k{32345, 2, 'b'};
	std::ranges::swap(j, k); // calls custom Library::swap()

	std::cout << j;
	std::cout << k;

	std::vector<int> data2{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//partition<int, std::greater>(data2.begin(), data2.end(), [](int* a, int* b) { return a > b; });

	std::swap_ranges(data2.begin(), data2.begin() + 3, data2.rbegin());


	std::cout << "################################# std::sort ################################" << std::endl;
	std::vector<int> vect = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	std::sort(vect.begin(), vect.end());
	// data1 == {1, 2, 3, 4, 5, 6, 7, 8, 9}

	std::list<int> lst = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	// std::sort(data.begin(), data.end()); // doesn't compile
	lst.sort();
	// data2 == {1, 2, 3, 4, 5, 6, 7, 8, 9}

	struct Account {
		double value() { return value_; }
		double value_;
	};

	std::vector<Account> accounts{ {0.1}, {0.3}, {0.01}, {0.05} };
	std::ranges::sort(accounts, std::less<>{}, & Account::value);
	// accounts = { {0.3}, {0.1}, {0.05}, {0.01} }

}

void lex_compare()
{
	std::vector<int> range1{ 1, 2, 3 };
	std::vector<int> range2{ 1, 3 };
	std::vector<int> range3{ 1, 3, 1 };


	bool cmp1 = std::lexicographical_compare(range1.begin(), range1.end(),
		range2.begin(), range2.end());
	// same as
	bool cmp2 = range1 < range2;
	// cmp1 == cmp2 == true

	bool cmp3 = std::lexicographical_compare(range2.begin(), range2.end(),
		range3.begin(), range3.end());
	// same as
	bool cmp4 = range2 < range3;
	// cmp3 == cmp4 == true

	// for demonstration only, prefer std::array
	int x[] = { 1, 2, 3 };
	int y[] = { 1, 4 };

	bool cmp5 = std::lexicographical_compare(&x[0], &x[3], &y[0], &y[2]);
	// cmp1 == true

	std::vector<std::string> names1{ "Zod", "Celeste" };
	std::vector<std::string> names2{ "Adam", "Maria" };

	bool cmp6 = std::ranges::lexicographical_compare(names1, names2,
		[](const std::string& left, const std::string& right) {
			return left.length() < right.length();
		});
	// different than
	bool cmp7 = names1 < names2; // Zod > Adam
	// cmp2 == true, cmp3 == false

	std::vector<int> data1 = { 1, 1, 1 };
	std::vector<int> data2 = { 1, 2, 3 };

	auto cmp = std::lexicographical_compare_three_way(
		data1.begin(), data1.end(),
		data2.begin(), data2.end());
	// cmp == std::strong_ordering::less
}