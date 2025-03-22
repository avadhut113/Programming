#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <chrono>
#include <random>

using namespace std::chrono;

std::vector<int> data;

void Initialize_data()
{
    const std::vector<int> in{ 1, 2, 3, 5, 7 ,9};
    size_t nelems = 3;
    std::sample(
        in.begin(),
        in.end(),
        std::back_inserter(data),
        nelems,
        std::mt19937{ std::random_device{}() }
    );

    for (auto i : data)
        std::cout<< " " << i;

    std::cout << std::endl;
}

struct Sentinel {
    using iter_t = std::vector<int>::iterator;
    iter_t begin;
    std::iter_difference_t<iter_t> cnt;
    bool operator==(const iter_t& l) const {
        return std::distance(begin, l) >= cnt;
    }

    bool operator!=(const iter_t& l) const {
        return std::distance(begin, l) < cnt;
    }
};

struct StatsFn {
    int cnt = 0;
    int sum = 0;
    void operator()(int v) {
        cnt ++;
        sum += v;      
    }
    
};

void para_for_each()
{
    int cnt = 0, sum = 0;

    auto start = high_resolution_clock::now();
    auto result = std::for_each(data.begin(), data.end(), StatsFn{});
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
}

//void Iterators_and_ranges()
//{
//    auto it1 = data.begin();
//    std::ranges::for_each(it1, Sentinel{ it1, 5 }, [](int el) {
//        std::cout << el << ", ";
//        });
//}


void copy_data()
{
   std::vector<int> data{ 1, 2, 3, 4, 5, 6, 7 };
   std::vector<int> out(7, 0);
  
   std::copy(data.begin(), data.end(), // input range
   out.begin() // output range, end iterator is implied:
   // std::next(out.begin(),
   // std::distance(data.begin(), data.end()));
  );
}

void mental_model_for_itr()
{
    std::cout << "################################# std::copy ################################" << std::endl;
    std::vector<int> data{ 1, 2, 3, 4, 5, 6, 7 };
    std::vector<int> out(7, 0);

    std::copy(data.begin(), data.end(), // input range
        out.begin() // output range, end iterator is implied:
        // std::next(out.begin(),
        // std::distance(data.begin(), data.end()));
    );

    for (const auto& ele : out) {
        std::cout << " " << ele;
    }

    std::cout << std::endl;

    std::cout << "################################# std::is_sorted_until ################################" << std::endl;

    std::vector<int> data1{ 1, 4, 5, 7, 9, 2, 3 };

    // is_sorted_until returns the first out of order element.
    auto result = std::is_sorted_until(data1.begin(), data1.end());

    // [begin, result) is the maximal sorted sub-range
    for (auto it = data1.begin(); it != result; it++) {
        // Iterate over all elements in the sorted sub-range.
        // {1, 4, 5, 7, 9}
        std::cout << " " << *it;
    }
    std::cout << std::endl;
    for (auto v : std::ranges::subrange(data1.begin(), result)) {
        // Same, but using a range-based for loop.
        std::cout << " " << v;
    }
    std::cout << std::endl;

    std::cout << "################################# std::lower_bound ################################" << std::endl;
    std::vector<int> data2{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // lower_bound returns the first element !(el < 4)
    auto lb = std::lower_bound(data2.begin(), data2.end(), 4);

    std::cout << " ele < 4 :";
    for (const auto& v : std::ranges::subrange(data2.begin(), lb)) {
        // lower range [begin, lb): elements < 4
        std::cout << " " << v;
    }
    std::cout << std::endl;
    std::cout << "ele >= 4 :";
    for (const auto& v : std::ranges::subrange(lb, data2.end())) {
        // upper range [lb, end): elements >= 4
        std::cout << " " << v;

    }
    std::cout << std::endl;

    std::cout << "################################# std::find ################################" << std::endl;
    std::string str("Hello c++ World!");

    // Returns the iterator to the first occurence of ' '
    auto it = std::find(str.begin(), str.end(), ' ');

    // Range [begin, it) is the maximal prefix range
    // that doesn't contain ' '
    for (const auto& v : std::string_view(str.begin(), it)) {
        // iterate over "Hello"
        std::cout << "" << v;
    }

    std::cout << std::endl;

    for (const auto& v : std::string_view(it, str.end())) {
        // iterate over "Hello"
        std::cout << "" << v;
    }

    std::cout << std::endl;
}


