#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <numeric>
#include <execution>


void linearOperations()
{
	std::cout << "################################# std::includes ################################" << std::endl;
	std::vector<char> letters('z' - 'a' + 1, '\0');
	std::iota(letters.begin(), letters.end(), 'a');

	std::string input = "the quick brown fox jumps over the lazy dog";
	std::ranges::sort(input);

	bool test = std::ranges::includes(input, letters);
	// test == true


	std::cout << "################################# std::merge ################################" << std::endl;
	struct LabeledValue {
		int value;
		std::string label;
	};

	std::vector<LabeledValue> data1_merge{
	{1, "first"}, {2, "first"}, {3, "first"} };
	std::vector<LabeledValue> data2_merge{
	{0, "second"}, {2, "second"}, {4, "second"} };

	std::vector<LabeledValue> result;
	auto cmp = [](const auto& left, const auto& right)
	{ return left.value < right.value; };

	std::ranges::merge(data1_merge, data2_merge, std::back_inserter(result), cmp);
	// result == {0, second}, {1, first}, {2, first},
	// {2, second}, {3, first}, {4, second}


	std::cout << "################################# std::parallel merge ################################" << std::endl;
	//Eample of parallel std::merge.
	std::vector<int> data1{ 1, 2, 3, 4, 5, 6 };
	std::vector<int> data2{ 3, 4, 5, 6, 7, 8 };

	std::vector<int> out(data1.size() + data2.size(), 0);
	std::merge(std::execution::par_unseq,
							data1.begin(), data1.end(),
							data2.begin(), data2.end(),
							out.begin());
	// out == {1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8}


	std::cout << "################################# std::inplace_merge ################################" << std::endl;
	std::vector<int> range{ 1, 3, 5, 2, 4, 6 };
	std::inplace_merge(range.begin(), range.begin() + 3, range.end());
	// range == { 1, 2, 3, 4, 5, 6 }


	std::cout << "################################# std::unique ################################" << std::endl;
	std::vector<int> data_unique{ 1, 1, 2, 2, 3, 4, 5, 6, 6, 6 };

	auto it = std::unique(data_unique.begin(), data_unique.end());
	// data == {1, 2, 3, 4, 5, 6, unspec, unspec, unspec, unspec}
	data_unique.resize(std::distance(data_unique.begin(), it));
	// data == {1, 2, 3, 4, 5, 6}


	std::vector<int> data_unique_copy{ 1, 1, 2, 2, 3, 4, 5, 6, 6, 6 };
	std::vector<int> out_unique;

	std::ranges::unique_copy(data_unique_copy, std::back_inserter(out_unique));
	// out == {1, 2, 3, 4, 5, 6}
}