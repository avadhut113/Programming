#pragma once
#include <list>
#include <vector>

#include "Notifier.h"
class View;
class Slide;

class SlideData : public Notifier
{
	std::vector<Slide *> m_Slides{} ;
public:
	void AddSlide(Slide *pSlide) ;
	void RemoveSlide(int index) ;
	Slide * GetSlide(int index)const ;
	void Save() ;
	void Load() ;
	size_t Count()const ;
};

