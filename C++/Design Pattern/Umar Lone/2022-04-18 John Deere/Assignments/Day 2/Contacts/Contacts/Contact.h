#pragma once
#include <string>

class Contact
{
	std::string m_Name{} ;
	std::string m_Phone{} ;
public:
	Contact(const std::string& name, const std::string& phone);
	const std::string& GetName() const;
	void SetName(const std::string& name);
	const std::string& GetPhone() const;
	void SetPhone(const std::string& phone);
};

