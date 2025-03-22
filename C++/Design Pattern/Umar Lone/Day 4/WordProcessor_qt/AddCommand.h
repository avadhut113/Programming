#pragma once
#include "Command.h"
class WordPadApp;

class AddCommand :
    public Command
{
	WordPadApp *m_pApp ;
	size_t m_Position{} ;
	size_t m_Count{} ;
public:
	explicit AddCommand(WordPadApp* pApp);

	void Execute(int id) override;
	void Undo() override;
};

