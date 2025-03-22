#pragma once
class Observer
{
public :
	virtual void OnUpdate(void *p) = 0 ;
	virtual ~Observer()=default ;
};
/*
 *std::any a = 100 ;
 */