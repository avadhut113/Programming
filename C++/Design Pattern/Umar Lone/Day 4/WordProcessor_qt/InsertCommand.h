#ifndef INSERTCOMMAND_H
#define INSERTCOMMAND_H

#include "Command.h"

class WordPadApp;

class InsertCommand : public Command
{
    WordPadApp *m_pApp ;
    size_t m_Position{} ;
    size_t m_Count{} ;
public:
    InsertCommand(WordPadApp* pApp);

    void Execute(int id);
    void Undo();
};

#endif // INSERTCOMMAND_H
