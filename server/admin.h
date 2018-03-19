#if !defined(AFX_ADMIN_H__46F5E2C5_8051_49F3_A302_02774F8291C0__INCLUDED_)
#define AFX_ADMIN_H__46F5E2C5_8051_49F3_A302_02774F8291C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// admin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cadmin dialog

class Cadmin : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	Cadmin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cadmin)
	enum { IDD = IDD_adminDlg };
	CListCtrl	m_list;
	CString	m_name;
	CString	m_pwd;
	CString	m_pwd2;
	CString	m_usr;
	CString	m_ID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cadmin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cadmin)
	afx_msg void Onadd();
	afx_msg void Ondelete();
	afx_msg void Onflash();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onupdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMIN_H__46F5E2C5_8051_49F3_A302_02774F8291C0__INCLUDED_)
