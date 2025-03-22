#include "RemoveCommand.h"

#include <iostream>

#include "UndoStack.h"
#include "WordPadApp.h"

RemoveCommand::RemoveCommand(WordPadApp* pApp): m_pApp{pApp} {
}

void RemoveCommand::Execute(int id) {
	std::cout << "Remove from index?" ;
	size_t index{} ;
	std::cin >> index ;
	std::cout << "Count?" ;
	size_t count{} ;
	std::cin >> count ;

	m_Position = index ;
	const auto &text = m_pApp->GetText() ;
	m_RemovedText = text.substr(m_Position, count) ;
	m_pApp->RemoveText(index, count) ;
	UndoStack::Push(new RemoveCommand{*this}) ;
}

void RemoveCommand::Undo() {
	std::cout << "[REMOVE UNDO] " ;
	m_pApp->InsertText(m_Position, m_RemovedText) ;
}
