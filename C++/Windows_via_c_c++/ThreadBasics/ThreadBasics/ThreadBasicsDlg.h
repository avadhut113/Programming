
// ThreadBasicsDlg.h : header file
//

#pragma once


// CThreadBasicsDlg dialog
class CThreadBasicsDlg : public CDialogEx
{
// Construction
public:
	CThreadBasicsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THREADBASICS_DIALOG };
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
  DWORD WINAPI ThreadFun(LPVOID lvParam);
};
