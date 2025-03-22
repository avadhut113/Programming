#include "TitleView.h"

#include <cstdlib>
#include <iostream>
#include "SlideData.h"
#include "Slide.h"

TitleView::TitleView(SlideData* pData): m_pData{pData} {
}

void TitleView::Display() {
	std::cout << "\n ============= TITLE VIEW =============\n" ;
	for(size_t i = 0 ; i < m_pData->Count() ; ++i) {
		std::cout << m_pData->GetSlide(i)->GetTitle() << '\t'; 
	}
	std::cout << '\n' ;
	/*std::cout << "\nPress enter to continue...\n" ;
	std::cin.get() ;
	system("cls") ;*/
}
