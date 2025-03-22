#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cctype>

void search_and_compare()
{
	std::cout << "################################# std::find ################################" << std::endl;
	//Example of utilizing std::find to find delimiters in a string.
	std::string data = "John;Doe;April;1;1900;";
	auto it11 = data.begin(), token = data.begin();
	std::vector<std::string> out1;

	while ((token = find(it11, data.end(), ';')) != data.end()) {
		out1.push_back("");
		std::copy(it11, token, std::back_inserter(out1.back()));
		it11 = std::next(token);
	}
	// out == { "John", "Doe", "April", "1", "1900" }


	std::cout << "################################# std::find_if_not ################################" << std::endl;
   //Example of utilizing std::find_if_not to find leading and trailing whitespace.
	std::string data4 = " hello world! ";

	auto begin = std::find_if_not(data4.begin(), data4.end(),
		[](char c) { return isspace(c); });

	//std::string out1;
	//std::copy(begin,
	//	std::find_if_not(data4.rbegin(), data4.rend(),
	//		[](char c) { return isspace(c); }
	//	).base(),
	//	std::back_inserter(out1));
	//// out == "hello world!"


	std::cout << "################################# std::adjacent_find ################################" << std::endl;
   //Example of using std::adjacent_find to find the first pair of equal elements and the first pair of elements that sum up to more than ten.
	std::vector<int> data1 = { 1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9 };
	auto it21 = std::adjacent_find(data1.begin(), data1.end());
	// *it1 == 4, i.e. {4, 4}

	auto it22 = std::adjacent_find(data1.begin(), data1.end(),
		[](int l, int r) { return l + r > 10; });
	// *it2 == 5, i.e. {5, 6}


	std::cout << "################################# std::search / std::find_first_of / std::find_end ################################" << std::endl;
	//Example of using std::search_n to find two consecutive elements equal to 3, three elements equal to 3 (in modulo 5 arithmetic) and finally, two elements equal to 0.
	std::vector<int> data3 = { 1, 0, 5, 8, 3, 3, 2 };

	auto it31 = std::search_n(data3.begin(), data3.end(), 2, 3);
	// *it1 == 3, i.e. {3, 3}

	auto it32 = std::search_n(data3.begin(), data3.end(), 3, 3,
		[](int l, int r) { return l % 5 == r % 5; });
	// *it2 == 8, i.e. {8, 3, 3}

	auto it33 = std::search_n(data3.begin(), data3.end(), 2, 0);
	// it3 == data.end(), i.e. not found


   //Example of using std::find_first_of.
	std::vector<int> haystack = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> needles = { 7, 5, 3 };

	auto it41 = std::find_first_of(haystack.begin(), haystack.end(),
		needles.begin(), needles.end());
	// *it == 3, i.e. haystack[2]


	//Example of using std::search and std::find_end.
	std::string haystack1 = "abbabba";
	std::string needle1 = "bba";

	auto it42 = std::search(haystack1.begin(), haystack1.end(),
		needle1.begin(), needle1.end());
	// it1..end == "bbabba"
	auto it43 = std::find_end(haystack1.begin(), haystack1.end(),
		needle1.begin(), needle1.end());
	// it2..end == "bba"


   //Example of using std::search with custom searchers.
	std::string haystack2 = "abbabba";
	std::string needle2 = "bba";

	auto it51 = std::search(haystack2.begin(), haystack2.end(),
		std::default_searcher(needle2.begin(), needle2.end()));

	auto it52 = std::search(haystack2.begin(), haystack2.end(),
		std::boyer_moore_searcher(needle2.begin(), needle2.end()));

	auto it53 = std::search(haystack2.begin(), haystack2.end(),
		std::boyer_moore_horspool_searcher(needle2.begin(), needle2.end()));
	// it1 == it2 == it3



	std::cout << "################################# std::count ################################" << std::endl;
   //Example of using std::count and std::count_if.
	std::vector<int> data2 = { 1, 2, 3, 2, 1, 2, 3, 2, 1 };

	auto one_cnt = std::count(data2.begin(), data2.end(), 1);
	// one_cnt == 3

	auto even_cnt = std::count_if(data2.begin(), data2.end(),
		[](int v) { return v % 2 == 0; });
	// even_cnt == 4


	std::cout << "################################# std::equal ################################" << std::endl;
	//Example of using std::equal.
	std::vector<int> first = { 1, 2, 3, 4, 5 };
	std::vector<int> second = { -1, -2, -3, -4, -5 };

	bool test1 = std::equal(first.begin(), first.end(), second.begin());
	// test1 == false

	bool test2 = std::equal(first.begin(), first.end(), second.begin(),
		[](int l, int r) { return std::abs(l) == std::abs(r); });
	// test2 == true


	//Example of using std::mismatch.
	std::vector<int> first1 = { 1, 2, 3, 4, 5 };
	std::vector<int> second1 = { 1, 2, 2, 4, 5 };

	auto it_pair = std::mismatch(first1.begin(), first1.end(), second1.begin());
	// *it_pair.first == 3, *it_pair.second == 2


	//Example of detecting a mismatch beyond the scope of the first range.
	std::vector<int> first11 = { 1, 2, 3, 4, 5 };
	std::vector<int> second11 = { 1, 2, 3, 4, 5, 6 };

	bool test11 = std::equal(first11.begin(), first11.end(), second11.begin());
	// test1 == true, cannot detect mismatch in number of elements

	bool test22 = std::equal(first11.begin(), first11.end(),
		second11.begin(), second11.end());
	// test2 == false, different number of elements -> not equal.

	auto pair_it = std::mismatch(first11.begin(), first11.end(),
		second11.begin(), second11.end());
	// pair_it.first == first.end()
	// *pair_it.second == 6
}