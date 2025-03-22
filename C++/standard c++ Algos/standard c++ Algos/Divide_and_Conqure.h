#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <list>
#include <set>

//struct ExamResult
//{
//	std::string student_name;
//	int score;
//};

void divide_and_Conqure()
{
	std::cout << "################################# std::lower_bound/upper_bound ################################" << std::endl;
	const std::vector<ExamResult>& results = { {"dumbo",35},{"sam",49}, {"chotu",60}, {"siso",92}, {"papa",99}, {"mummy",100} };


	//std::sort(results.begin(), results.end());
	//auto pp1 = std::partition(results.begin(), results.end(), [threshold = 49](const auto& r) {
	//														 	return r.score >= threshold;
	//														 });

	//auto lb1 = std::ranges::lower_bound(results, 49, {},
	//	&ExamResult::score);
	//// First element for which: it->score >= 49
	//auto ub1 = std::ranges::upper_bound(results, 99, {},
	//	&ExamResult::score);
	//// First element for which: 99 < it->score

	//for (auto it = results.begin(); it != lb1; it++) {
	//	// Process exam fails, upto 48
	//	std::cout << "[FAIL] " << it->student_name << "\n";
	//}

	//for (auto it = lb1; it != ub1; it++) {
	//	// Process exam passes, 49-99
	//	std::cout << "[PASS] " << it->student_name << "\n";
	//}

	//for (auto it = ub1; it != results.end(); it++) {
	//	// Process exams with honors, 100+
	//	std::cout << "[TOPPERS] " << it->student_name << "\n";
	//}


	//std::multiset<int> data{ 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9 };

	//auto lb = data.lower_bound(6);
	//// std::distance(data.begin(), lb) == 5, *lb == 6

	//auto ub = data.upper_bound(6);
	//// std::distance(data.begin(), ub) == 8, *ub == 7


	std::cout << "################################# std::equal_range ################################" << std::endl;
	std::vector<int> data4{ 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9 };

	const auto p = std::equal_range(data4.begin(), data4.end(), 6);
	// std::distance(data.begin(), lb) == 5, *lb == 6
	// std::distance(data.begin(), ub) == 8, *ub == 7



	std::cout << "################################# std::partition_point ################################" << std::endl;
	std::vector<int> data3{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto pp = std::partition_point(data3.begin(), data3.end(),
		[](int v) { return v < 5; });
	// *pp == 5



	std::cout << "################################# std::binary_search ################################" << std::endl;
	std::vector<int> data2{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	bool exists = std::ranges::binary_search(data2, 5);
	// exists == true
	const auto p2 = std::ranges::equal_range(data2, 5);
	// lb != ub, i.e. the value is in the range



	std::cout << "################################# bsearch ################################" << std::endl;
	int data1[] = { -2, -1, 0, 1, 2 };
	int size = sizeof data1 / sizeof(int);

	auto cmp = [](const void* left, const void* right) {
		int vl = *(const int*)left;
		int vr = *(const int*)right;

		if (vl < vr) return -1;
		if (vl > vr) return 1;
		return 0;
	};

	int value = 1;
	void* el1 = bsearch(&value, data1, size, sizeof(int), cmp);
	// *static_cast<int*>(el1) == 1

	value = 3;
	void* el2 = bsearch(&value, data1, size, sizeof(int), cmp);
	// el2 == nullptr


	std::cout << "################################# alternative bsearch ################################" << std::endl;

	int data_arr[] = { -2, -1, 0, 1, 2 };
	int size1 = sizeof data_arr / sizeof(int);

	int value1 = 1;
	bool exist = std::binary_search(&data_arr[0], &data_arr[size1], value1);
	// exist == true

	auto candidate = std::lower_bound(&data_arr[0], &data_arr[size1], value1);
	if (candidate != &data_arr[size] && *candidate == value1) {
		// process element
	}

	const auto p1 = std::equal_range(&data_arr[0], &data_arr[size1], value1);
	if (p1.first != p1.second) {
		// process equal elements
	}
}