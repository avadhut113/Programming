#include "ProjectionView.h"

#include <iostream>

void ProjectionView::AddData(const std::string& data) {
	m_Data.push_back(data) ;
}

void ProjectionView::Project() {
	std::cout << "\n\n\n\n\n" ;
	for(auto &data :m_Data) {
		std::cout << "\t\t\t\t\t" << data << '\n' ;
	}
	std::cout << "\n\n\nPress enter to continue\n" ;
	std::cin.get();
	system("cls") ;
}

size_t ProjectionView::Size() const {
	return m_Data.size() ;
}

void ProjectionView::Clear() {
	m_Data.clear() ;
}
