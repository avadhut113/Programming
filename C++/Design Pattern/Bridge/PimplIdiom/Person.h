#pragma once
#include <iostream>
#include <string>

class CPerson
{
	std::string name = "Default";
public:
	class CPersonImpl;
	CPersonImpl* impl;

	CPerson();
	~CPerson();
	std::string get_name() const {
		return name;
	}
	void greet();
};

