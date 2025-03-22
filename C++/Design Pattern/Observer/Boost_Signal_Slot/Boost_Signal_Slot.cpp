// Boost_Signal_Slot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/signal.hpp>

template <typename T>
class observable
{
public:
    boost::signal<void(T&, const std::string&)> field_changed;
};

class Person : public observable<Person>
{
	int age;
public:
	Person(int age) : age{ age } {}

	int get_age() const {
		return age;
	}

	void set_age(int age) {
		if (this->age == age) return;
		this->age = age;
		field_changed(*this, "age");
	}
};

int main()
{
	Person p{ 10 };
	auto conn = p.field_changed.connect(
		[](Person& p, const std::string& field_name) {
			std::cout << "Person's " << field_name << " has changed to ";
			if (field_name == "age") std::cout << p.get_age();
			std::cout << "\n.";
		}
	);

	p.set_age(11);
	p.set_age(12);

	p.field_changed.disconnect(conn);
	p.set_age(13);
}
