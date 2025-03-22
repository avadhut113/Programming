#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <numeric>
#include <execution>

struct Labeled {
	std::string label;
	int value;
};

void Set_Operations()
{

	auto cmp = [](const auto& l, const auto& r) {
		return l.value < r.value;
	};

	std::cout << "################################# std::set_difference ################################" << std::endl;
	//Example of using std::set_difference.
	std::vector<int> data1_set_difference{ 1, 2, 3, 4, 5, 6 };
	std::vector<int> data2_set_difference{ 3, 4, 5 };

	std::vector<int> difference;
	std::ranges::set_difference(data1_set_difference, data2_set_difference,
		std::back_inserter(difference));
	// difference == {1, 2, 6}

	//Example demonstrating std::set_difference behaviour when equivalent elements arepresent.
	std::vector<Labeled> equal1_set_difference{ {"first_a", 1}, {"first_b", 1},
	{"first_c", 1}, {"first_d", 1} };
	std::vector<Labeled> equal2_set_difference{ {"second_a", 1}, {"second_b", 1} };

	std::vector<Labeled> equal_difference;
	std::ranges::set_difference(equal1_set_difference, equal2_set_difference,
		std::back_inserter(equal_difference), cmp);
	// equal_difference == { {"first_c", 1}, {"first_d", 1} }



	std::cout << "################################# std::set_symmetric_difference ################################" << std::endl;
	//Example of using std::set_symmetric_difference.
	std::vector<int> data1_symmetric_difference{ 1, 3, 5, 7, 9 };
	std::vector<int> data2_symmetric_difference{ 3, 4, 5, 6, 7 };

	std::vector<int> symmetric_difference;
	std::ranges::set_symmetric_difference(data1_symmetric_difference, data2_symmetric_difference,
		std::back_inserter(symmetric_difference));
	// symmetric_difference == {1, 4, 6, 9}

	//Example demonstrating std::set_symmetric_difference behaviour when equivalent elements are present.
	std::vector<Labeled> equal1_symmetric_difference{ {"first_a", 1}, {"first_b", 2},
	{"first_c", 2} };
	std::vector<Labeled> equal2_symmetric_difference{ {"second_a", 1}, {"second_b", 1},
	{"second_c", 2} };

	std::vector<Labeled> equal_symmetric_difference;
	std::ranges::set_symmetric_difference(equal1_symmetric_difference, equal2_symmetric_difference,
		std::back_inserter(equal_symmetric_difference), cmp);
	// equal_symmetric_difference == { {"second_b", 1}, {"first_c", 2} }



	std::cout << "################################# std::set_union ################################" << std::endl;
   //Example of using std::set_union.
	std::vector<int> data1_set_union{ 1, 3, 5 };
	std::vector<int> data2_set_union{ 2, 4, 6 };

	std::vector<int> set_union;
	std::ranges::set_union(data1_set_union, data2_set_union,
		std::back_inserter(set_union));
	// set_union == { 1, 2, 3, 4, 5, 6 }

	//Example demonstrating std::set_union behaviour when equivalent elements are present.
	std::vector<Labeled> equal1_set_union{ {"first_a", 1}, {"first_b", 1},
	{"first_c", 2} };
	std::vector<Labeled> equal2_set_union{ {"second_a", 1}, {"second_b", 2},
	{"second_c", 2} };

	std::vector<Labeled> equal_union;
	std::ranges::set_union(equal1_set_union, equal2_set_union,
		std::back_inserter(equal_union), cmp);
	// equal_union == { {"first_a", 1}, {"first_b", 1}, {"first_c", 2},{"second_c", 2}


	std::cout << "################################# std::set_intersection ################################" << std::endl;
	//Example of using std::set_intersection.
	std::vector<int> data1_set_intersection{ 1, 2, 3, 4, 5 };
	std::vector<int> data2_set_intersection{ 2, 4, 6 };

	std::vector<int> intersection;
	std::ranges::set_intersection(data1_set_intersection, data2_set_intersection,
		std::back_inserter(intersection));
	// intersection == {2, 4}


	//Example demonstrating std::set_intersection behaviour when equivalent elements arepresent.
	std::vector<Labeled> equal1_set_intersection{ {"first_a", 1}, {"first_b", 2} };
	std::vector<Labeled> equal2_set_intersection{ {"second_a", 1}, {"second_b", 2},
	{"second_c", 2} };

	std::vector<Labeled> intersection_udef;
	std::ranges::set_intersection(equal1_set_intersection, equal2_set_intersection,
		std::back_inserter(intersection_udef), cmp);
	// intersection == { {"first_a", 1}, {"first_b", 2} }
}
