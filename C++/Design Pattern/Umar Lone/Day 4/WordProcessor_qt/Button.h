#pragma once
class Command;

class Button
{
	Command *m_pCmd ;
	int m_Id ;
public:
	explicit Button(int id);

	void SetClickHandler(Command *p) ;
	void Click() ;
};

