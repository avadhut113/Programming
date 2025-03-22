#include "AddCommand.h"

#include <iostream>
#include <string>

#include "UndoStack.h"
#include "WordPadApp.h"

AddCommand::AddCommand(WordPadApp* pApp): m_pApp{pApp} {
}

void AddCommand::Execute(int id) {
	m_Position = m_pApp->GetText().size() ;
	std::cout << "Enter text:" ;
	std::string text ;
	std::getline(std::cin, text) ;

	m_Count = text.size() ;

	m_pApp->AddText(text) ;
	UndoStack::Push(new AddCommand{*this}) ;
}

void AddCommand::Undo() {
	std::cout << "[ADD UNDO] " ;
	m_pApp->RemoveText(m_Position, m_Count) ;
}
