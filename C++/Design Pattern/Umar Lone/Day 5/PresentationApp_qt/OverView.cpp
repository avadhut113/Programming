#include "O0verView.h"
#include <iostream>
#include "SlideData.h"
#include "Slide.h"

OverView::OverView()
{

}

void OverView::Display()
{
    size_t index{1} ;
    for(size_t i = 0 ; i < m_pData->Count() ; ++i) {
        std::cout << m_pData->GetSlide(i)->GetTitle() << '\t';
    }
    std::cout << "\nPress enter to continue...\n" ;
    std::cin.get() ;
    system("clear") ;
}
