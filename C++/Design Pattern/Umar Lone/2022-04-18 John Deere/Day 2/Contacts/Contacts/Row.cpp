#include "Row.h"

#include <iostream>

bool Row::IsVisible() const {
	return m_Visible ;
}

void Row::SetVisibility(bool visible) {
	m_Visible = visible ;
}

Row::Row() {
	++object_count ;
}

Row::Row(const std::string& line01, const std::string& line02): m_Line01{line01},
                                                                m_Line02{line02} {
	++object_count ;
}

const std::string& Row::GetLine01() const {
	return m_Line01;
}

void Row::SetLine01(const std::string& line01) {
	m_Line01 = line01;
}

const std::string& Row::GetLine02() const {
	return m_Line02;
}

void Row::SetLine02(const std::string& line02) {
	m_Line02 = line02;
}

void Row::Render() {
	std::cout << "------------------------\n" ;
	std::cout << '|' << m_Line01 << '\n' ;
	std::cout << '|' << m_Line02 << '\n' ;
}
