#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

void left_fold()
{
	std::cout << "################################# std::accumulate ################################" << std::endl;

	std::vector<int> data{ 1, 2, 3, 4, 5 };

	auto sum = std::accumulate(data.begin(), data.end(), 0);
	// sum == 15

	auto product = std::accumulate(data.begin(), data.end(), 1,
		std::multiplies<>{});
	// product == 120

	std::vector<int> data2{ 1, 2, 3, 4, 5 };

	auto left_fold = std::accumulate(data2.begin(), data2.end(), 0,
		[](int acc, int el) {
			return acc / 2 + el;
		});
	// left_fold == 8

	auto right_fold = std::accumulate(data2.rbegin(), data2.rend(), 0,
		[](int acc, int el) {
			return acc / 2 + el;
		});


	std::cout << "################################# std::inner_product ################################" << std::endl;

	//Example of using std::inner_product.
	std::vector<int> heights{ 1, 2, 3, 4, 5 };
	std::vector<int> widths{ 2, 3, 4, 5, 6 };

	auto total_area = std::inner_product(heights.begin(), heights.end(),
		widths.begin(), 0);
	// total_area == 70

	//Example of using std::inner_product on a single range to calculate sum of absolute differences between elements.
	std::vector<int> data4{ 6, 4, 3, 7, 2, 1 };
	auto sum_of_diffs = std::inner_product(
		data4.begin(), std::prev(data4.end()),
		std::next(data4.begin()), 0,
		std::plus<>{},
		[](int left, int right) { 
			return std::abs(left - right); 
		}
	);
	// sum_of_diffs == 13



	std::cout << "################################# std::partial_sum ################################" << std::endl;

	//Example of using std::partial_sum.
	std::vector<int> data3(6, 1);
	// data == {1, 1, 1, 1, 1, 1}

	std::partial_sum(data3.begin(), data3.end(), data3.begin());
	// data == {1, 2, 3, 4, 5, 6}

	std::vector<int> out;
	std::partial_sum(data3.begin(), data3.end(),
		std::back_inserter(out), std::multiplies<>{});
	// out == {1, 2, 6, 24, 120, 720}
}