#include "Button.h"

#include "Command.h"

Button::Button(int id): m_Id{id} {
}

void Button::SetClickHandler(Command* p) {
	m_pCmd = p ;
}

void Button::Click() {
	m_pCmd->Execute(m_Id) ;
}
