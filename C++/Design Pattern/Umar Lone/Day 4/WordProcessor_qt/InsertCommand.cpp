#include "InsertCommand.h"
#include <iostream>
#include <string>

#include "UndoStack.h"
#include "WordPadApp.h"

InsertCommand::InsertCommand(WordPadApp *pApp) : m_pApp(pApp)
{

}

void InsertCommand::Execute(int id)
{
    std::cout << "Enter position:";
    std::cin >> m_Position;
    //m_Position = 7;
    std::cout << "Enter text:" ;
    std::string text ;
    std::getline(std::cin, text) ;

    m_Count = text.size() ;

    m_pApp->InsertText(m_Position, text) ;
    UndoStack::Push(new InsertCommand{*this}) ;
}

void InsertCommand::Undo()
{
    std::cout << "[ADD UNDO] " ;
    m_pApp->RemoveText(m_Position, m_Count) ;
}
