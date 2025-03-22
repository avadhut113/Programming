#pragma once
#include <vector>

class SlideShowView;
class SlideData;
class Slide;

class MainApp
{
	SlideData *m_pData{} ;
	SlideShowView *m_pView ;
public:
	MainApp(SlideData* pData, SlideShowView* pView);

	explicit MainApp(SlideData* pData);

	void AddSlide() ;
	void RemoveSlide() ;
	void ModifySlide() ;
	void Save() ;
	void Load() ;
};

