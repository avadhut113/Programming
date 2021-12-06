
// Queue_using_mutex_semaphoreDlg.h : header file
//

#pragma once
#include "CQueue.h"


CQueue g_Q(10);
volatile bool g_bShutDown = FALSE;
HWND g_hwnd;

HANDLE g_hThread[MAXIMUM_WAIT_OBJECTS];
int g_nNumThreads = 0;


// CQueueusingmutexsemaphoreDlg dialog
class CQueueusingmutexsemaphoreDlg : public CDialogEx
{
// Construction
public:
	CQueueusingmutexsemaphoreDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUEUE_USING_MUTEX_SEMAPHORE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  CListCtrl m_listClientRequest;
};
