#include "pch.h"
#include "CQueue.h"

CQueue::CQueue(int nMaxEle) : m_hMutex(m_h[0]), m_hSemaphoreNum(m_h[1])
{
  m_pElements = (PELEMENT)HeapAlloc(GetProcessHeap(), 0, sizeof(ELEMENT) * nMaxEle);
  m_nMaxElements = nMaxEle;
  m_hMutex = CreateMutex(NULL, FALSE, NULL);
  m_hSemaphoreNum = CreateSemaphore(NULL, 0, nMaxEle, NULL);
}

CQueue::~CQueue()
{
  CloseHandle(m_hSemaphoreNum);
  CloseHandle(m_hMutex);
  HeapFree(GetProcessHeap(), 0, m_pElements);
}

bool CQueue::Append(PELEMENT pElement, DWORD dwTimeOut)
{
  bool bOk = false;
  DWORD dw = WaitForSingleObject(m_hMutex, dwTimeOut);

  if (dw == WAIT_OBJECT_0) {
    LONG lPrevCount;
    bOk = ReleaseSemaphore(m_hSemaphoreNum, 1, &lPrevCount);
    if (bOk) {
      m_pElements[lPrevCount] = *pElement;
    }
    else {
      SetLastError(ERROR_DATABASE_FULL);
    }

    ReleaseMutex(m_hMutex);
  }
  else {
    SetLastError(ERROR_TIMEOUT);
  }

  return bOk;
}

bool CQueue::Remove(PELEMENT pElement, DWORD dwTimeout)
{
  bool fOk = (WaitForMultipleObjects(_countof(m_h), m_h, TRUE, dwTimeout) == WAIT_OBJECT_0);

  if (fOk) {
    //Queue has element pull it from queue
    *pElement = m_pElements[0];

    MoveMemory(&m_pElements[0], &m_pElements[1], sizeof(ELEMENT)*(m_nMaxElements - 1));

    ReleaseMutex(m_hMutex);
  }
  else {
    SetLastError(ERROR_TIMEOUT);
  }

  return fOk;
}

