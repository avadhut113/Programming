#pragma once
#include "View.h"
class SlideData;

class SlideShowView : public View	
{
	SlideData *m_pData{} ;
public:
	explicit SlideShowView(SlideData* pData);

	void Display() ;
};

