#pragma once
#include <iostream>


namespace A {
	void some_call(int) {}
	void some_call(const char*) {}
	namespace B {
		void some_call(double) {}

		void calling_site() {
			some_call(1); // A::B::some_call
			some_call(2.0); // A::B::some_call
			// some_call("hello world"); will not compile
			// no conversion from const char* -> double
		}
	}
}

void calling_site() {
	Custom::X x;
	Custom::operator << (std::cout, x); // OK, explicit call
	std::cout << x; // Requires ADL
}

//Without ADL, any call to a custom operator overload would have to be fully qualified, requiring the function call syntax.
namespace Custom {
	struct X {};

	std::ostream& operator << (std::ostream& s, const X&) {
		s << "Output of X\n";
		return s;
	}
}


namespace A {
	struct X {};
	void some_func(const X&) {}
}

namespace B {
	struct Y {};
	void some_func(const Y&) {}
}

void some_func(const auto&) {}

void calling_site() {
	A::X x; B::Y y;
	some_func(x); // Calls A::some_func
	some_func(y); // Calls B::some_func
}



namespace Base {
	template <typename T>
	std::string serialize(const T&) {
		return std::string{ "{Unknown type}" };
	}
}

namespace Custom {
	struct X {
		friend std::string serialize(const X&) {
			return std::string{ "{X}" };
		}
	};

	struct Y {};
}

void calling_site() {
	Custom::X x;
	Custom::Y y;

	auto serialized_x = serialize(x);
	// serialized_x == "{X}"

	// auto serialized_y = serialize(y); // Would not compile.

	using Base::serialize; // Pull in default version.
	auto serialized_y = serialize(y);
	// serialized_y == "{Unknown type}"
}


//Example demonstrating a lambda stored in an inline variable that can only be invoked through a qualified call.
namespace Custom {
	struct X {};

	constexpr inline auto some_func = [](const X&) {};
}

void calling_site() {
	const Custom::X x;
	// some_func(x); // Will not compile, not visible to ADL.
	Custom::some_func(x); // OK
}


//Example demonstrating a non-function object preventing ADL, making a friend function impossible to invoke.
namespace Custom {
	struct X {
		friend void some_func(const X&) {}
	};
}

constexpr inline auto some_func = [](const auto&) {};

void calling_site() {
	Custom::X x;
	some_func(x); // calls ::some_func
	// Because ADL is skipped, Custom::some_func cannot be called.
}



namespace dflt {
	namespace impl {
		template <typename T>
		concept HasCustomImpl = requires(T a) { do_something(a); };

		struct DoSomethingFn {
			template <typename T> void operator()(T&& arg) const
				requires HasCustomImpl<T> {
				do_something(std::forward<T>(arg));
			}

			template <typename T> void operator()(T&&) const
				requires (!HasCustomImpl<T>) { /* default implementation */ }
		};
	}

	inline namespace var {
		constexpr inline auto do_something = impl::DoSomethingFn{};
	}
}

namespace custom {
	struct X { friend void do_something(const X&) {}; };
	struct Y {};
}

void calling_site() {
	custom::X x;
	custom::Y y;
	dflt::do_something(x); // calls custom::do_something(const X&)
	dflt::do_something(y); // calls default implementation
}

void arg_dependent_lookup()
{
	//Example of unqualified lookup. Both calls to some_call will resolve to ::A::B::some_call since this is the first instance discovered by the compiler.
}
