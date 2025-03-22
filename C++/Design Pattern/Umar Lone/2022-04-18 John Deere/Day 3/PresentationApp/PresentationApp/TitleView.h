#pragma once
#include "View.h"
class SlideData;

class TitleView : public View
{
	
	SlideData *m_pData{} ;
public:
	explicit TitleView(SlideData* pData);

	void Display(int part) ;
};

