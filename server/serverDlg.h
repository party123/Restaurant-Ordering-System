// serverDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__9066B8ED_4AA8_42D8_B588_13519019C7BF__INCLUDED_)
#define AFX_SERVERDLG_H__9066B8ED_4AA8_42D8_B588_13519019C7BF__INCLUDED_

#include "ServerSocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerDlg : public CDialog
{
// Construction
public:
	CServerSocket sockListen;
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CString	m_testnet;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMENUcaipinleixing();
	afx_msg void OnButton1();
	afx_msg void Onclose();
	afx_msg void OnMENUabout();
	afx_msg void OnMENUadmin();
	afx_msg void OnMENUcaipin();
	afx_msg void OnMENUtable();
	afx_msg void OnButton2();
	afx_msg void OnMENUjiesuan();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__9066B8ED_4AA8_42D8_B588_13519019C7BF__INCLUDED_)
