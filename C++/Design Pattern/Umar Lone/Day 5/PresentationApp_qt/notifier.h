#pragma once
#include <list>

class View;

class Notifier
{
	std::list<View*> m_Views{} ;
public:
	void RegisterView(View *pView) ;
	void UnregisterView(View *pView) ;
	void Notify();
};

