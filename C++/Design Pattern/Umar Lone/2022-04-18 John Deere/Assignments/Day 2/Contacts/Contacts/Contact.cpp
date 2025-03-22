#include "Contact.h"

Contact::Contact(const std::string& name, const std::string& phone): m_Name{name},
                                                                     m_Phone{phone} {
}

const std::string& Contact::GetName() const {
	return m_Name;
}

void Contact::SetName(const std::string& name) {
	m_Name = name;
}

const std::string& Contact::GetPhone() const {
	return m_Phone;
}

void Contact::SetPhone(const std::string& phone) {
	m_Phone = phone;
}
