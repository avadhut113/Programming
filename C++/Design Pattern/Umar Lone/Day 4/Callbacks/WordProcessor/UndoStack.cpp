#include "UndoStack.h"

void UndoStack::Push(Command* pCmd) {
	m_Commands.push(pCmd) ;
}

Command* UndoStack::Pop() {
	auto cmd = m_Commands.top() ;
	m_Commands.pop() ;
	return cmd ;
}

bool UndoStack::IsEmpty()  {
	return m_Commands.empty() ;
}
