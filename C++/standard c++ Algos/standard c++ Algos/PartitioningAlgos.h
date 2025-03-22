#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <list>

struct ExamResult
{
	std::string student_name;
	int score;

	//ExamResult(const std::initializer_list<ExamResult>& init_list) {
	//	for (const auto& examRes : init_list) {

	//	}
	//}
	//ExamResult(const ExamResult& right) = default;
	//ExamResult& operator=(const ExamResult& right) = default;
	//ExamResult(ExamResult&& right) = default;
	//ExamResult& operator=(ExamResult&& right) = default;
	//auto operator<=>(const ExamResult&) const = default;

};


void partitioning_algorithms()
{
	std::cout << "################################# std::partition ################################" << std::endl;
	std::vector<ExamResult> results = { {"sam",49},{"dumbo",35}, {"papa",99}, {"mummy",100}, {"chotu",60}, {"siso",92} };

	auto pp = std::partition(results.begin(), results.end(),[threshold = 49](const auto& r) {
																return r.score >= threshold;
															});

	// process passing students
	for (auto it = results.begin(); it != pp; ++it) {
		std::cout << "[PASS] " << it->student_name << "\n";
	 }
	// process failed students
	for (auto it = pp; it != results.end(); ++it) {
		std::cout << "[FAIL] " << it->student_name << "\n";
	}


	std::cout << "################################# std::stable_partition ################################" << std::endl;

	/*auto& widget = get_widget();
	std::ranges::stable_partition(widget.items, &Item::is_selected);*/


	std::cout << "################################# std::is_partitioned ################################" << std::endl;

	std::vector<int> data{2, 4, 6, 7, 9, 11};

	auto is_even = [](int v) { return v % 2 == 0; };
	bool test1 = std::ranges::is_partitioned(data, is_even);
	// test1 == true

	bool test2 = true;
	for (int i = 0; i < 16; ++i) {
		test2 = test2 && std::is_partitioned(data.begin(), data.end(),[&i](int v) { return v < i;});																					
	}
	// test2 == true


	std::cout << "################################# std::partition_copy ################################" << std::endl;

	std::vector<int> data2{2, 4, 6, 1, 3, 5};
	auto is_num_even = [](int v) { return v % 2 == 0; };

	std::vector<int> even, odd;
	std::partition_copy(data2.begin(), data2.end(),std::back_inserter(even),std::back_inserter(odd),is_num_even);

	// even == {2, 4, 6}
	// odd == {1, 3, 5}


	std::cout << "################################# std::nth_element ################################" << std::endl;

	std::vector<int> data1{9, 1, 8, 2, 7, 3, 6, 4, 5};
	std::nth_element(data1.begin(), data1.begin() + 4, data1.end());
	// data[4] == 5
	// data[0..3] == {1, 2, 3, 4} - in undeterminate order

	std::nth_element(data1.begin(), data1.begin() + 7, data1.end(),
	 std::greater<>());
	// data[7] == 2
	// data[0..6] == {3, 4, 5, 6, 7, 8, 9} - in undeterminate order
}