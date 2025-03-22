#pragma once
#include <list>

class Observer;

class Observable
{
	std::list<Observer *> m_Observers ;
public:
	void Attach(Observer *ob) ;
	void Detach(Observer *ob) ;
	void Notify(void *pInfo) ;
};

