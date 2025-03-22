#include "MainApp.h"

#include <iostream>
#include <string>
#include <fstream>
#include "Slide.h"
#include "SlideData.h"
#include "SlideShowView.h"

MainApp::MainApp(SlideData* pData, SlideShowView* pView): m_pData{pData},
                                                          m_pView{pView} {
}

MainApp::MainApp(SlideData* pData): m_pData{pData} {
}

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

	m_pData->AddSlide(new Slide{title, content, notes}) ;

	//m_pView->Display() ;
}

void MainApp::RemoveSlide() {
	std::cout << "Index?" ;
	int index{} ;
	std::cin >> index ;
	std::cin.ignore() ;
	m_pData->RemoveSlide(index) ;
	//m_pView->Display() ;
}

void MainApp::ModifySlide() {
	std::cout << "Index?" ;
	int index{} ;
	std::cin >> index ;
	std::cin.ignore() ;

	auto slide = m_pData->GetSlide(index) ;

	std::cout << "[OLD]" << slide->GetTitle() << '\n' ;
	std::cout << "Title?" ;
	std::string title{} ;
	std::getline(std::cin, title) ;

	std::cout << "[OLD]" << slide->GetContent() << '\n' ;
	std::cout << "Content?" ;
	std::string content{} ;
	std::getline(std::cin, content) ;

	std::cout << "[OLD]" << slide->GetNotes() << '\n' ;
	std::cout << "Notes?" ;
	std::string notes{} ;
	std::getline(std::cin, notes) ;

	slide->SetTitle(title) ;
	slide->SetContent(content) ;
	slide->SetNotes(notes) ;
	//m_pView->Display() ;
}

void MainApp::Save() {
	m_pData->Save() ;
}

void MainApp::Load() {
	m_pData->Load() ;
	//m_pView->Display() ;
}
