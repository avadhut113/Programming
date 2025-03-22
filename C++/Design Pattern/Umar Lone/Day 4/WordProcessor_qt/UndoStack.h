#pragma once
#include <stack>

class Command;

//Monostate
class UndoStack
{
	inline static std::stack<Command *> m_Commands{} ;
	UndoStack()=default ;
public:
	static void Push(Command *pCmd) ;
	static Command *Pop() ;
	static bool IsEmpty() ;
};

