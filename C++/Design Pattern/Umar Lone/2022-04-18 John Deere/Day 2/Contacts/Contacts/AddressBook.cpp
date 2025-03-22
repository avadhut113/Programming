#include "AddressBook.h"
#include <fstream>
#include <iostream>

void AddressBook::LoadDb(const std::string& dbname) {
	std::ifstream input{dbname} ;
	if(!input) {
		throw std::runtime_error{"Cannot open file"} ;
	}
	std::string name{} ;
	std::string phone{} ;
	while(std::getline(input, name)) {
		if(std::getline(input, phone)) {
			m_Contacts.push_back(new Contact{name, phone}) ;
		}else {
			break ;
		}
	}
}

const Contact* AddressBook::GetContact(size_t index) const {
	return m_Contacts[index] ;
}

size_t AddressBook::Count() const {
	return m_Contacts.size() ;
}

void AddressBook::DebugDisplay() {
	for(auto contact : m_Contacts) {
		std::cout << contact->GetName() << '\n' ;
		std::cout << contact->GetPhone() << "\n\n" ;
	}
}
