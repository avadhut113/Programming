#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <random>
#include <array>
#include <numeric>

struct Card {
	unsigned index;

	friend std::ostream& operator << (std::ostream& s, const Card& card) {
		static constexpr std::array<const char*, 13> ranks = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine", "Ten", "Jack", "Queen", "King" };
		static constexpr std::array<const char*, 4> suits = { "Hearts", "Diamonds", "Clubs", "Spades" };

		if (card.index >= 52)
			throw std::domain_error("Card index has to be in the range0..51");

		s << ranks[card.index % 13] << " of " << suits[card.index / 13];
		return s;
	}

};


void Trasformation_Algos()
{
	//####################################################### std::transform ##############################################################
	//Example of unary and binary version of std::transform. Note that the output iterator can beone of the input ranges’ begin iterator (line 4 and 12).
	std::vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8 };

	std::transform(data1.begin(), data1.end(),
		data1.begin(),
		[](int v) { return v * 2; });
	// data == {2, 4, 6, 8, 10, 12, 14, 16}

	std::vector<int> add{ 8, 7, 6, 5, 4, 3, 2, 1 };

	std::transform(data1.begin(), data1.end(),
		add.begin(),
		data1.begin(),
		[](int left, int right) { return left + right; });
	// data == {10, 11, 12, 13, 14, 15, 16, 17}




	//####################################################### std::adjacent_difference ##############################################################
   //Example of the default version of std::adjacent_difference, which will calculate thedifference of adjacent elements, with the first element copied.
	std::vector<int> data2{ 2, 3, 5, 7, 11, 13 };
	std::adjacent_difference(data2.begin(), data2.end(), data2.begin());
	// data == {2, 1, 2, 2, 4, 2}

	//Example of more inventive use of std::adjacent_difference to generate the Fibonacci sequence.
	std::vector<int> data3(10, 1);
	// data == {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

	std::adjacent_difference(data3.begin(), std::prev(data3.end()),
		std::next(data3.begin()), std::plus<int>());
	// Fibonacci sequence:
	// data == {1, 1, 2, 3, 5, 8, 13, 21, 34, 55}




	//####################################################### std::remove/remove_if ##############################################################
	//Example of using std::remove and std::remove_if.
	std::vector<int> data4{ 1, 2, 3, 4, 5 };

	auto it = std::remove(data4.begin(), data4.end(), 3);
	// data == { 1, 2, 4, 5, ?}

	data4.erase(it, data4.end()); // Erase sub-range
	// data == {1, 2, 4, 5}

	auto is_even = [](int v) { return v % 2 == 0; };
	it = std::remove_if(data4.begin(), data4.end(), is_even);
	// data == {1, 5, ?, ?}

	data4.resize(it - data4.begin()); // Random Access Ranges only
	// data = {1, 5}



	//####################################################### std::replace/replace_if ##############################################################
   //Example of using std::replace and std::replace_if.
	std::vector<int> data5{ 1, 2, 3, 4, 5, 6, 7 };

	std::ranges::replace(data5, 4, 0);
	// data == {1, 2, 3, 0, 5, 6, 7}

	auto is_odd = [](int v) { return v % 2 != 0; };
	std::ranges::replace_if(data5, is_odd, -1);
	// data == {-1, 2, -1, 0, -1, 6, -1}


	//####################################################### std::reverse ##############################################################
	//Example of using std::reverse and reverse iteration, provided by bidirectional ranges.
	std::vector<int> data6{ 1, 2, 3, 4, 5, 6, 7 };

	std::reverse(data6.begin(), data6.end());
	// data == {7, 6, 5, 4, 3, 2, 1}

	for (auto it = data6.rbegin(); it != data6.rend(); ++it) {
		// iterate over: 1, 2, 3, 4, 5, 6, 7
	}



	//####################################################### std::rotate ##############################################################
	//Example of using std::rotate.
	std::vector<int> data7{ 1, 2, 3, 4, 5, 6, 7 };
	std::rotate(data7.begin(), data7.begin() + 3, data7.end());
	// data == {4, 5, 6, 7, 1, 2, 3}




	//####################################################### std::shuffle ##############################################################
	//Example of using std::shuffle to shuffle a deck of cards.
	std::vector<Card> deck(52, Card{});
	std::ranges::generate(deck, [i = 0u]() mutable { return Card{ i++ }; });
	// deck == {Ace of Hearts, Two of Hearts, Three of Hearts, Four...}

	std::random_device rd;
	std::mt19937 gen{ rd() };

	std::ranges::shuffle(deck, gen);
	// deck == { random order }



	//####################################################### std::next_permutation ##############################################################
	//Example of using std::next_permutation to iterate over all permutations of three uniqueelements.
	std::vector<int> data9{ 1, 2, 3 };
	do {
		// iterate over:
		// 1, 2, 3
		// 1, 3, 2
		// 2, 1, 3
		// 2, 3, 1
		// 3, 1, 2
		// 3, 2, 1
		for (const auto& i : data9)
			std::cout << i << " ";

		std::cout << std::endl;
	} while (std::next_permutation(data9.begin(), data9.end()));
	// data == {1, 2, 3}



	//####################################################### std::is_permutation ##############################################################
	//Example of using std::is_permutation to validate a simple sort implementation.
	std::vector<int> data = { 8, 1, 7, 3, 4, 6, 2, 5 };
	for (size_t i = 0; i < data.size() - 1; ++i)
		for (size_t j = i + 1; j < data.size(); ++j)
			if (data[i] > data[j])
				std::swap(data[i], data[j]);

	bool is_sorted = std::ranges::is_sorted(data);
	// is_sorted == true

	bool is_permutation = std::ranges::is_permutation(data,
		std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
	// is_permutation == true
}