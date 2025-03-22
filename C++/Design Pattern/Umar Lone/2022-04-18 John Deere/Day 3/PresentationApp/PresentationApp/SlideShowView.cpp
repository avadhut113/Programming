#include "SlideShowView.h"

#include <cstdlib>
#include <iostream>
#include "SlideData.h"
#include "Slide.h"
SlideShowView::SlideShowView(SlideData* pData): m_pData{pData} {
}

void SlideShowView::Display(int part) {
	if(part == 2) {
		return ;
	}
	std::cout << "\n##SLIDESHOW VIEW ##\n" ;
	size_t index{1} ;
	for(size_t i = 0 ; i < m_pData->Count() ; ++i) {
		std::cout << "\n===== " << index++ << " =====\n" ;
		std::cout << m_pData->GetSlide(i)->GetTitle() << '\n'; 
		std::cout << m_pData->GetSlide(i)->GetContent() << '\n'; 
		//std::cout << m_pData->GetSlide(i)->GetNotes() << '\n';

		/*std::cout << "\nPress enter to continue...\n";
		std::cin.get();
		system("cls");*/
	}
	//std::cout << "\nPress enter to continue...\n" ;
	//std::cin.get() ;
	//system("cls") ;
}
