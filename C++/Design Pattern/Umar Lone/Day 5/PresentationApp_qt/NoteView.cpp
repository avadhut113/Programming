#include <iostream>
#include "NoteView.h"

#include "SlideData.h"
#include "Slide.h"

NoteView::NoteView(SlideData* pData)
{
    m_pData = pData;
}

void NoteView::Display() {
    std::cout << "\n ============= SLIDESHOW VIEW =============\n" ;
    size_t index{1} ;
    for(size_t i = 0 ; i < m_pData->Count() ; ++i) {
        std::cout << "\n===== " << index++ << " =====\n" ;
        std::cout << m_pData->GetSlide(i)->GetTitle() << '\n';
        std::cout << m_pData->GetSlide(i)->GetContent() << '\n';
        //std::cout << m_pData->GetSlide(i)->GetNotes() << '\n';
    }
    //std::cout << "\nPress enter to continue...\n" ;
    //std::cin.get() ;
    //system("cls") ;
}
