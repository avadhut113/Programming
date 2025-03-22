#pragma once
#include <vector>

#include "Contact.h"

class AddressBook
{
	std::vector<Contact *> m_Contacts ;
public:
	void LoadDb(const std::string &dbname) ;
	const Contact * GetContact(size_t index)const ;
	size_t Count()const ;
	void DebugDisplay() ;
};

