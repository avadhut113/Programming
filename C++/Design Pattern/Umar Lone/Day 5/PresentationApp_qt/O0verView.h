#ifndef OVERVIEW_H
#define OVERVIEW_H
#include "IView.h"

class SlideData;

class OverView : public IView
{
    SlideData* m_pData;
public:
    OverView();
    void Display();
};

#endif // OVERVIEW_H
