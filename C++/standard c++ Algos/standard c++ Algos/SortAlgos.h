#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <list>

void Sorting_algorithms()
{
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

	std::cout << "################################# std::stable_sort ################################" << std::endl;

	struct Record {
		std::string label;
		int rank;
	};

	std::vector<Record> data{ {"q", 1}, {"f", 1}, {"c", 2}, {"a", 1},
	 {"d", 3} };

	std::ranges::stable_sort(data, {}, & Record::label);
	std::ranges::stable_sort(data, {}, & Record::rank);
	// Guarantted order: a-1, f-1, q-1, c-2, d-3

	std::cout << "################################# std::is_sorted ################################" << std::endl;

	std::vector<int> data1 = { 1, 2, 3, 4, 5 };
	bool test1 = std::is_sorted(data1.begin(), data1.end());
	// test1 == true

	std::vector<int> data2 = { 5, 4, 3, 2, 1 };
	bool test2 = std::ranges::is_sorted(data2);
	// test2 == false
	bool test3 = std::ranges::is_sorted(data2, std::greater<>{});
	// test3 == true

	std::cout << "################################# std::is_sorted_until ################################" << std::endl;

	std::vector<int> is_data_sorted{ 1, 5, 9, 2, 4, 6 };
	auto it = std::is_sorted_until(is_data_sorted.begin(), is_data_sorted.end());
	// *it == 2


	std::cout << "################################# std::partial_sort ################################" << std::endl;

	std::vector<int> data_partinal_sorted{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::partial_sort(data_partinal_sorted.begin(), data_partinal_sorted.begin() + 3, data_partinal_sorted.end());
	// data == {1, 2, 3, -unspecified order-}

	std::ranges::partial_sort(data_partinal_sorted, data_partinal_sorted.begin() + 3, std::greater<>());
	// data == {9, 8, 7, -unspecified order-}


	std::cout << "################################# std::partial_sort_copy ################################" << std::endl;

	// input == "0 1 2 3 4 5 6 7 8 9"
	std::vector<int> top(3);

	auto input = std::istream_iterator<int>(std::cin);
	auto cnt = std::counted_iterator(input, 10);

	std::ranges::partial_sort_copy(cnt, std::default_sentinel,
		top.begin(), top.end(),
		std::greater<>{});
	// top == { 9, 8, 7 }

	std::cout << "################################# qsort ################################" << std::endl;

	int data_array[] = { 2, 1, 9, -1, 7, -8 };
	int size = sizeof data_array / sizeof(int);

	qsort(data_array, size, sizeof(int),
		[](const void* left, const void* right) {
			int vl = *(const int*)left;
			int vr = *(const int*)right;

			if (vl < vr) return -1;
			if (vl > vr) return 1;
			return 0;
		});
	// data == {-8, -1, 1, 2, 7, 9}
}