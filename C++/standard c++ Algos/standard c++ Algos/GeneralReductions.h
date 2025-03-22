#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <execution>
#include <string>
#include <cmath>


void reduction()
{
	std::cout << "################################# std::reduce ################################" << std::endl;
	//Example of using std::reduce with and without an execution policy.
	std::vector<int> data1{ 1, 2, 3, 4, 5 };

	auto sum = std::reduce(data1.begin(), data1.end(), 0);
	// sum == 15

	sum = std::reduce(std::execution::par_unseq,
		data1.begin(), data1.end(), 0);
	// sum == 15

	auto product = std::reduce(data1.begin(), data1.end(), 1,
		std::multiplies<>{});
	// product == 120

	product = std::reduce(std::execution::par_unseq,
		data1.begin(), data1.end(), 1, std::multiplies<>{});
	// product == 120


   //Example of using std::reduce without specifying the initial value of the accumulator.
	struct Duck {
		std::string sound = "Quack";
		Duck operator+(const Duck& right) const {
			return { sound + right.sound };
		}
	};

	std::vector<Duck> data2(2, Duck{});
	Duck final_duck = std::reduce(data2.begin(), data2.end());
	// final_duck.sound == "QuackQuackQuack"



	std::cout << "################################# std::transform_reduce ################################" << std::endl;
   //Example of using the unary version of std::transform_reduce to calculate a sum of squares and the binary version to calculate a sum of elements multiplied by coefficients.
	std::vector<int> data3{ 1, 2, 3, 4, 5 };
	auto sum_of_squares = std::transform_reduce(data3.begin(), data3.end(),
		0, std::plus<>{}, [](int v) { return v * v; });
	// sum_of_squares == 55

	std::vector<int> coef{ 1, -1, 1, -1, 1 };
	auto result = std::transform_reduce(data3.begin(), data3.end(),
		coef.begin(), 0);
	// result == 1*1 + 2*(-1) + 3*1 + 4*(-1) + 5*1 == 3


	std::cout << "################################# std::inclusive_scan ################################" << std::endl;
	//Example of using std::inclusive_scan.
	std::vector<int> src1{ 1, 2, 3, 4, 5, 6 };
	std::vector<int> out3;

	std::inclusive_scan(src1.begin(), src1.end(),
		std::back_inserter(out3));

	// out == {1, 3, 6, 10, 15, 21}

	std::inclusive_scan(src1.begin(), src1.end(),
		out3.begin(), std::multiplies<>{}, 1);
	// out == {1, 2, 6, 24, 120, 720}

	std::cout << "################################# std::exclusive_scan ################################" << std::endl;
   //Example of using std::exclusive_scan.
	std::vector<int> src{ 1, 2, 3, 4, 5, 6 };
	std::vector<int> out;

	std::exclusive_scan(src.begin(), src.end(),
		std::back_inserter(out), 0);
	// out == {0, 1, 3, 6, 10, 15}

	std::exclusive_scan(src.begin(), src.end(),
		out.begin(), 1, std::multiplies<>{});
	// out == {1, 1, 2, 6, 24, 120}


	//Example of using std::transform_inclusive_scan to accumulate absolute values of elements.
	std::vector<int> data{ -10, 3, -2, 5, 6 };

	std::vector<int> out1;
	std::inclusive_scan(data.begin(), data.end(),
		std::back_inserter(out1), std::plus<>{});

	// out1 == {-10, -7, -9, -4, 2}

	std::vector<int> out2;
	std::transform_inclusive_scan(data.begin(), data.end(),
		std::back_inserter(out2), std::plus<>{},
		[](int v) { return std::abs(v); });
	// out2 == {10, 13, 15, 20, 26}


	std::cout << "################################# Boolean reductions ################################" << std::endl;

	//Example demonstrating all three boolean reduction algorithms.
	std::vector<int> data5{ -2, 0, 2, 4, 6, 8 };

	bool all_even = std::ranges::all_of(data5,
		[](int v) { return v % 2 == 0; });
	// all_even == true

	//bool one_negative = std::ranges::any_of(data5,[](int v) { return std::signbit(v); });

	//one_negative == true;

	bool none_odd = std::ranges::none_of(data5,
		[](int v) { return v % 2 != 0; });
	// none_odd == true
}