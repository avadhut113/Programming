#pragma once
#include <string>

#include "Command.h"

class WordPadApp : public Command
{
	std::string m_Text{} ;
public:
	void AddText(const std::string &text) ;
	void RemoveText(size_t start, size_t count) ;
	void InsertText(size_t start, const std::string &text) ;

	const std::string & GetText()const ;

	void Display(const char *msg="")const ;

	void Execute(int id) override;
};

