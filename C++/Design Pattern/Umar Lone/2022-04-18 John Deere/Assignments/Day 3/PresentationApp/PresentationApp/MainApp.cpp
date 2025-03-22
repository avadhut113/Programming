#include "MainApp.h"

#include <iostream>
#include <string>
#include <fstream>
#include "Slide.h"
void MainApp::AddSlide() {
	std::cout << "Title?" ;
	std::string title{} ;
	std::getline(std::cin, title) ;

	std::cout << "Content?" ;
	std::string content{} ;
	std::getline(std::cin, content) ;

	std::cout << "Notes?" ;
	std::string notes{} ;
	std::getline(std::cin, notes) ;

	m_Slides.push_back(new Slide{title, content, notes}) ;
}

void MainApp::RemoveSlide() {
	std::cout << "Index?" ;
	int index{} ;
	std::cin >> index ;
	m_Slides.erase(m_Slides.begin() + index) ;
}

void MainApp::ModifySlide() {
	std::cout << "Index?" ;
	int index{} ;
	std::cin >> index ;
	std::cin.ignore() ;

	std::cout << "[OLD]" << m_Slides[index]->GetTitle() << '\n' ;
	std::cout << "Title?" ;
	std::string title{} ;
	std::getline(std::cin, title) ;

	std::cout << "[OLD]" << m_Slides[index]->GetContent() << '\n' ;
	std::cout << "Content?" ;
	std::string content{} ;
	std::getline(std::cin, content) ;

	std::cout << "[OLD]" << m_Slides[index]->GetNotes() << '\n' ;
	std::cout << "Notes?" ;
	std::string notes{} ;
	std::getline(std::cin, notes) ;

	m_Slides[index]->SetTitle(title) ;
	m_Slides[index]->SetContent(content) ;
	m_Slides[index]->SetNotes(notes) ;


}

void MainApp::Save() {
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

void MainApp::Load() {
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
		std::getline(input, content) ;
		std::getline(input, notes) ;
		m_Slides.push_back(new Slide{title, content, notes}) ;
	}while(!input.eof()) ;
}

void MainApp::Display() {
	size_t index{1} ;
	for(auto slide:m_Slides) {
		std::cout << "\n===== " << index++ << " =====\n" ;
		std::cout << slide->GetTitle() << '\n'; 
		std::cout << slide->GetContent() << '\n'; 
		std::cout << slide->GetNotes() << '\n';

		/*std::cout << "\nPress enter to continue...\n";
		std::cin.get();
		system("cls");*/
	}
	std::cout << "\nPress enter to continue...\n" ;
	std::cin.get() ;
	system("cls") ;
}
