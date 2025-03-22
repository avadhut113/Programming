#ifndef NOTEVIEW_H
#define NOTEVIEW_H

#include "View.h"

class SlideData;

class NoteView : public View
{
    SlideData *m_pData{} ;
public:
    NoteView(SlideData* pData);
    void Display();
};

#endif // NOTEVIEW_H
