#pragma once
#include<Windows.h>
#include <tchar.h>
#include <StrSafe.h>
#include "Resource.h"

class CQueue
{
public:
  struct ELEMENT {
    int m_nThreadNum, m_nReqestNum;
  };
  typedef ELEMENT* PELEMENT;

private:
  PELEMENT m_pElements;
  int m_nMaxElements;
  HANDLE m_h[2];
  HANDLE &m_hMutex; //reference to m_h[0]
  HANDLE &m_hSemaphoreNum;  //reference to m_h[1]

public:
  CQueue(int nMaxEle);
  ~CQueue();

  bool Append(PELEMENT pElement, DWORD deMilliSec);
  bool Remove(PELEMENT pElement, DWORD deMilliSec);

};

