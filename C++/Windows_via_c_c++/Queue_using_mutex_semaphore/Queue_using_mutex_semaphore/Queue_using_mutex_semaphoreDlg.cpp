
// Queue_using_mutex_semaphoreDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Queue_using_mutex_semaphore.h"
#include "Queue_using_mutex_semaphoreDlg.h"
#include "afxdialogex.h"
#include <windowsx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//client thread

DWORD WINAPI ClientThread(PVOID pvParam)
{
  int nThreadNum = PtrToUlong(pvParam);
  HWND hwndLB = GetDlgItem(g_hwnd, IDC_CLIENTS);

  int nReqNum = 0;

  while ((PVOID)1 !=
    InterlockedCompareExchangePointer(
    (PVOID*)&g_bShutDown, (PVOID)0, (PVOID)0)) {

    nReqNum++;

    TCHAR sz[1024];
    CQueue::ELEMENT e = {nThreadNum, nReqNum};

    if (g_Q.Append(&e, 200)) {
      StringCchPrintf(sz, _countof(sz), TEXT("Sending %d:%d"),
        nThreadNum, nReqNum);
    }
    else {
      // Couldn't put an element on the queue
      StringCchPrintf(sz, _countof(sz), TEXT("Sending %d:%d (%s)"),
        nThreadNum, nReqNum, (GetLastError() == ERROR_TIMEOUT)
        ? TEXT("timeout") : TEXT("full"));
    }

    // Show result of appending element
    ListBox_SetCurSel(hwndLB, ListBox_AddString(hwndLB, sz));
    Sleep(2500); // Wait before appending another element
  }

  return 0;
}


DWORD WINAPI ServerThread(PVOID pvParam) {

  int nThreadNum = PtrToUlong(pvParam);
  HWND hwndLB = GetDlgItem(g_hwnd, IDC_SERVERS);

  while ((PVOID)1 !=
    InterlockedCompareExchangePointer(
    (PVOID*)&g_bShutDown, (PVOID)0, (PVOID)0)) {

    TCHAR sz[1024];
    CQueue::ELEMENT e;
    // Try to get an element from the queue
    if (g_Q.Remove(&e, 5000)) {

        // Indicate which thread is processing it, which thread
        // sent it and which request we're processing
        StringCchPrintf(sz, _countof(sz), TEXT("%d: Processing %d:%d"),
          nThreadNum, e.m_nThreadNum, e.m_nReqestNum);

      // The server takes some time to process the request
      Sleep(2000 * e.m_nThreadNum);
    }
    else {
      // Couldn't get an element from the queue
      StringCchPrintf(sz, _countof(sz), TEXT("%d: (timeout)"), nThreadNum);
    }
    // Show result of processing element
    ListBox_SetCurSel(hwndLB, ListBox_AddString(hwndLB, sz));
  }
  return(0);
}

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CQueueusingmutexsemaphoreDlg dialog



CQueueusingmutexsemaphoreDlg::CQueueusingmutexsemaphoreDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUEUE_USING_MUTEX_SEMAPHORE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQueueusingmutexsemaphoreDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_LIST_CLIENT, m_listClientRequest);
}

BEGIN_MESSAGE_MAP(CQueueusingmutexsemaphoreDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CQueueusingmutexsemaphoreDlg message handlers

BOOL CQueueusingmutexsemaphoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CQueueusingmutexsemaphoreDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQueueusingmutexsemaphoreDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQueueusingmutexsemaphoreDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

