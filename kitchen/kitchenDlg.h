// kitchenDlg.h : header file
//

#if !defined(AFX_KITCHENDLG_H__1E44E4F3_F2D5_4556_9679_3632F15EB93B__INCLUDED_)
#define AFX_KITCHENDLG_H__1E44E4F3_F2D5_4556_9679_3632F15EB93B__INCLUDED_

#include "KitchenSocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CKitchenDlg dialog

class CKitchenDlg : public CDialog
{
// Construction
public:
	CKitchenSocket kitchensock;
	CKitchenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKitchenDlg)
	enum { IDD = IDD_KITCHEN_DIALOG };
	CListCtrl	m_list;
	CComboBox	m_type;
	CString	m_name;
	CString	m_ID;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKitchenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKitchenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton2();
	afx_msg void Oncook();
	afx_msg void OnClicklist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelendokCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KITCHENDLG_H__1E44E4F3_F2D5_4556_9679_3632F15EB93B__INCLUDED_)
