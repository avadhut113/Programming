#pragma once
#include <vector>
#include <algorithm>
#include <ranges>
#include <string_view>
#include <string>

void views()
{
	
	//Example of composing several views.
	std::vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto v : data1 | std::views::reverse |
		std::views::take(3) | std::views::reverse) {
		// iterate over 7, 8, 9 (in order)
	}


	std::cout << "################################# std::views::keys, std::views::values ################################" << std::endl;
	//std::views::keys, std::views::values
	//Example of decomposing a std::unordered_map into a view over the keys and a view over the values.
	std::unordered_map<int, double> map1{
	{0, 1.0}, {1, 1.5}, {2, 2.0}, {3, 2.5}
	};

	std::vector<int> keys;
	std::ranges::copy(std::views::keys(map1), std::back_inserter(keys));
	// keys == {0, 1, 2, 3} in unspecified order (std::unordered_map)

	std::vector<double> values;
	std::ranges::copy(std::views::values(map1),
		std::back_inserter(values));
	// values == {1.0, 1.5, 2.0, 2.5}
	// in unspecified order matching order of keys


   //std::views::elements
   std::cout << "################################# std::views::elements ################################" << std::endl;
   //Example of creating element views for each tuple’s second and third elements in the source range.
	std::vector<std::tuple<int, int, std::string>> data2{
	{1, 100, "Cat"}, {2, 99, "Dog"}, {3, 17, "Car"},
	};

	std::vector<int> second;
	std::ranges::copy(data2 | std::views::elements<1>,
		std::back_inserter(second));
	// second == {100, 99, 17}

	std::vector<std::string> third;
	std::ranges::copy(data2 | std::views::elements<2>,
		std::back_inserter(third));
	// third == {"Cat", "Dog", "Car"}


	std::cout << "################################# std::views::transform ################################" << std::endl;
   //std::views::transform
   //Example of using std::views::transform that also changes the base type of the range.
	std::vector<double> data3{ 1.2, 2.3, 3.1, 4.5, 7.1, 8.2 };

	std::vector<int> out3;
	std::ranges::copy(data3 |
		std::views::transform([](auto v) -> int {
			return v * v;
			}), std::back_inserter(out3));
	// out == {1, 5, 9, 20, 50, 67}


	std::cout << "################################# std::views::take, std::views::take_while ################################" << std::endl;
	//std::views::take, std::views::take_while
	//Example of a view of the first three elements and a view of the leading sequence of odd elements.
	std::vector<int> data4{ 1, 3, 5, 7, 2, 4, 6, 8 };

	std::vector<int> out4;
	std::ranges::copy(data4 | std::views::take(3),

		std::back_inserter(out4));
	// out1 == {1, 3, 5}

	std::vector<int> out42;
	std::ranges::copy(data4 |
		std::views::take_while([](int v) { return v % 2 != 0; }),
		std::back_inserter(out42));
	// out2 == {1, 3, 5, 7}


	std::cout << "################################# std::views::drop, std::views::drop_while ################################" << std::endl;
   //std::views::drop, std::views::drop_while
   //Example of a view of all but the first three elements and a view skipping over the leading sequence of odd elements.
	std::vector<int> data5{ 1, 3, 5, 7, 2, 4, 6, 8 };

	std::vector<int> out51;
	std::ranges::copy(data5 | std::views::drop(3),
		std::back_inserter(out51));
	// out1 == {7, 2, 4, 6, 8}

	std::vector<int> out52;
	std::ranges::copy(data5 |
		std::views::drop_while([](int v) { return v % 2 != 0; }),
		std::back_inserter(out52));
	// out2 == {2, 4, 6, 8}


	std::cout << "################################# std::views::filter ################################" << std::endl;
   //std::views::filter
   //Example of a view of even elements.
	std::vector<int> data6{ 1, 2, 3, 4, 5, 6, 7, 8 };

	std::vector<int> even6;
	std::ranges::copy(data6 |
		std::views::filter([](int v) { return v % 2 == 0; }),
		std::back_inserter(even6));
	// even == {2, 4, 6, 8}


	std::cout << "################################# std::views::reverse ################################" << std::endl;
	//std::views::reverse
	//Example of a reverse view.
	std::vector<int> data7{ 1, 2, 3, 4 };

	std::vector<int> out7;
	std::ranges::copy(data7 | std::views::reverse,
		std::back_inserter(out7));
	// out == {4, 3, 2, 1}


	std::cout << "################################# std::views::counted ################################" << std::endl;
	//std::views::counted
	//Example of using a counted view to iterate over a subrange.
	std::vector<int> data8{ 1, 2, 3, 4, 5, 6, 7, 8 };

	std::vector<int> out8;
	std::ranges::copy(std::views::counted(std::next(data8.begin()), 3),
		std::back_inserter(out8));
	// out == {2, 3, 4}


	std::cout << "################################# std::views::common ################################" << std::endl;
	//std::views::common
	//Example of using adapting a view for a non-range algorithm.
	std::vector<int> data9{ 1, 2, 3, 4, 5, 6, 7, 8 };

	std::vector<int> out9;
	auto view = data9 |
		std::views::filter([](int v) { return v % 2 == 0; }) |
		std::views::common;

	std::copy(view.begin(), view.end(), std::back_inserter(out9));
	// out == {2, 4, 6, 8}


	std::cout << "################################# std::views::all ################################" << std::endl;
	//std::views::all
	//Example of creating a view over all elements. Note that view over all elements is the default.
	std::vector<int> data10{ 1, 2, 3, 4 };

	std::vector<int> out10;
	std::ranges::copy(std::views::all(data10), std::back_inserter(out10));
	// out == {1, 2, 3, 4}


	std::cout << "################################# std::views::split, std::views::lazy_split, std::views::join_view ################################" << std::endl;
	//std::views::split, std::views::lazy_split, std::views::join_view
	//Example of using split view to parse a version number.
	std::string version = "1.23.13.42";
	std::vector<int> parsed;

	std::ranges::copy(version |
		std::views::split('.') |
		std::views::transform([](auto v) {
			int result = 0;
			// from_chars requires contiguous range
			std::from_chars(v.data(), v.data() + v.size(), result);
			return result;
			}),
		std::back_inserter(parsed));
	// parsed == {1, 23, 13, 42}

   //Example of using std::views::lazy_split to split a string into tokens and then join them using the std::views::join.
	std::string_view data11 = "Car Dog Window";
	std::vector<std::string> words;
	std::ranges::for_each(data11 | std::views::lazy_split(' '),
		[&words](auto const& view) {
			// string constructor needs common range.
			auto common = view | std::views::common;
			words.emplace_back(common.begin(), common.end());
		});
	// words == {"Car", "Dog", "Window"}

	auto joined = data11 | std::views::lazy_split(' ') | std::views::join |
		std::views::common;
	std::string out(joined.begin(), joined.end());
	// out == "CarDogWindow"


	std::cout << "################################# std::views::empty, std::views::single ################################" << std::endl;
   //std::views::empty, std::views::single
   //Example of using std::views::empty and std::views::single.
	std::vector<int> out12;
	std::ranges::copy(std::views::empty<int>, std::back_inserter(out12));
	// out == {}

	std::ranges::copy(std::views::single(42), std::back_inserter(out12));
	// out == {42}

		//std::views::iota
		//Example of using the finite and infinite iota view.
		std::vector<int> out15;
	std::ranges::copy(std::views::iota(2, 5), std::back_inserter(out15));
	// finite view [2, 5), out == {2, 3, 4}

	std::vector<int> out25;
	std::ranges::copy(std::views::iota(42) | std::views::take(5),
		std::back_inserter(out25));
	// infinite view starting with 42, take(5) takes the first five elements from this view
	// out2 == {42, 43, 44, 45, 46}


	std::cout << "################################# std::views::istream ################################" << std::endl;
	//std::views::istream
	//Example of using istream view.
	std::ranges::for_each(std::views::istream<int>(std::cin), [](int v) {
			// iterate over integers on standard input
		std::cout << v << " ";
	});
}