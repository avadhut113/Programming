#pragma once

#include <vector>
#include <algorithm>
#include <ranges>
#include <random>
#include <string>
#include <iostream>
#include <iterator>
#include <numeric>

//Example of using standard concepts in user code. The function accepts any random access range as the first argument and an output iterator with the same underlying type as the second argument.
template <std::ranges::random_access_range T>
auto my_function(T&& rng,
	std::output_iterator<std::ranges::range_value_t<T>> auto it) {
	if (rng.size() >= 5)
		*it++ = rng[4];
	if (rng.size() >= 7)
		*it++ = rng[6];
}

//Example demonstrating declaring MyView as a borrowed range.
//template<typename T>
//inline constexpr bool std::ranges::enable_borrowed_range<MyView<T>> = true;

void notion_on_ranges()
{
	//Example of an infinite range when the data guarantees termination. Using std::unreachable_sentinel causes the boundary check to be optimized-out, removing one comparison from the loop.
	std::vector<int> dt = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::ranges::shuffle(dt, std::mt19937(std::random_device()()));

	auto pos = std::ranges::find(
		dt.begin(),
		std::unreachable_sentinel,
		7);



	//Eample of using the range overload of std::sort.
	std::vector<int> dt1 = { 1, 4, 2, 3 };
	std::ranges::sort(dt1);

}

struct Account {
	double value;
	Account(double val) : value(val) {}
};


struct A {
	double value;
	A(double val) : value(val) {}
};

struct B {
	double value;
	B() : value(0){}
	B(double val) : value(val) {}
};

void projections()
{
	//Example of using a projection to sort elements of a range based on a computed value from an element method.
	std::vector<Account> data1 = std::initializer_list<Account>{1.0,2.0,3.0,4.0};

	std::ranges::sort(data1, std::greater<>{}, & Account::value);



	//Example of the difference between std::ranges::copy_if, which uses the projection result for the predicate and std::ranges::transform, which uses the projection result as the input for the transformation function (therefore making it affect the output type).
	std::vector<A> data2 = std::initializer_list<A>{1,2,3,4,5};

	std::vector<A> out1;
	// std::vector<B> out1; would not compile
	std::ranges::copy_if(data2, std::back_inserter(out1),
		[](B) { return true; }, // predicate accepts B
		[](A) { return B{}; }); // projection projects A->B for the predicate only

	std::vector<B> out2;
	std::ranges::transform(data2, std::back_inserter(out2),
		[](auto x) { std::cout << typeid(decltype(x)).name(); return x; }, // no-op transformation functor
		[](A) { return B{}; });



	//3.4 Dangling iterator protection

	//Example demonstrating the different handling for a borrowed range std::string_view and std::string.
		const char* c_str = "1234567890";

	// find on a temporary string_view
	auto sep1 = std::ranges::find(std::string_view(c_str), '0');
	static_assert(!std::is_same_v<std::ranges::dangling, decltype(sep1)>);
	// OK, string_view is a borrowed range, *sep1 == '0',

	int bad = 1234567890;

	// find on a temporary string
	auto sep2 = std::ranges::find(std::to_string(bad), '0');
	//static_assert(!std::is_same_v<std::ranges::dangling, decltype(sep2)>);
	
	// decltype(sep2) == std::ranges::dangling, *sep2 would not compile
}
