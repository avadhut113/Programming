// MyObserver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Observer.h"
#include "Observable.h"

class Person : public Observable<Person>
{
	int age;
public:
	Person(int age) : age{age} {}

	int get_age() const {
		return age;
	}

	void set_age(int age) {
		if (this->age == age) return;
		this->age = age;
		notify(*this, "age");
	}
};

class PersonObserver : public Observer<Person>
{
public:
	void field_changed(Person& person, const std::string& field_name) override {
		std::cout << "Person's " << field_name << " has changed to ";
		if (field_name == "age") std::cout << person.get_age();
		std::cout << "\n.";
	}
};

int main()
{
	Person person{ 10 };
	PersonObserver observePerson;

	person.subscribe(observePerson);

	person.set_age(11);
	person.set_age(12);

	person.unsubscribe(observePerson);

	person.set_age(13);
	
}
