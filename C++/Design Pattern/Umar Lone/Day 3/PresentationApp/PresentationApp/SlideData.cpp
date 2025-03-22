#include "SlideData.h"

#include <iostream>
#include <fstream>
#include "SlideShowView.h"
#include "Slide.h"
void SlideData::Save() {
	std::ofstream out{"deck.txt"} ;
	if(!out) {
		std::cout << "Could not open file for writing\n" ;
		return ;
	}
	for(auto slide:m_Slides) {
		out << slide->GetTitle() << '\n'; 
		out << slide->GetContent() << '\n'; 
		out << slide->GetNotes() << '\n'; 
	}
}

void SlideData::Load() {
	m_Slides.clear() ;
	std::ifstream input{"deck.txt"} ;
	if(!input) {
		std::cout << "Could not open file for reading\n" ;
		return ;
	}

	std::string title{} ;
	std::string content{} ;
	std::string notes{} ;
	do {
		std::getline(input, title) ;
		if(title.empty())break ;
		std::getline(input, content) ;
		if(content.empty())break ;
		std::getline(input, notes) ;
		if(content.empty())break ;
		m_Slides.push_back(new Slide{title, content, notes}) ;
	}while(!input.eof()) ;
	m_Notifier.Notify();
}

size_t SlideData::Count() const {
	return m_Slides.size() ;
}



void SlideData::AddSlide(Slide* pSlide) {
	m_Slides.push_back(pSlide) ;
	m_Notifier.Notify();
	
}

void SlideData::RemoveSlide(int index) {
	m_Slides.erase(m_Slides.begin() + index) ;
	m_Notifier.Notify();
}

Slide* SlideData::GetSlide(int index) const {
	return m_Slides[index] ;
}
