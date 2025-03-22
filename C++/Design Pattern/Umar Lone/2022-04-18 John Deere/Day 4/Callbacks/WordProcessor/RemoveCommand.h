#pragma once
#include <string>

#include "Command.h"
class WordPadApp;

class RemoveCommand :
    public Command
{
    WordPadApp *m_pApp ;
    size_t m_Position ;
    std::string m_RemovedText ;
public:
    explicit RemoveCommand(WordPadApp* pApp);
    void Execute(int id) override;
    void Undo() override;
};

