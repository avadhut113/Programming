#pragma once
#include <vector>

class Slide;

class MainApp
{
	std::vector<Slide *> m_Slides{} ;
public:
	void AddSlide() ;
	void RemoveSlide() ;
	void ModifySlide() ;
	void Save() ;
	void Load() ;
	void Display() ;
};

