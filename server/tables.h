#if !defined(AFX_TABLES_H__398F8651_B9D0_470E_B1DE_0E66A563927C__INCLUDED_)
#define AFX_TABLES_H__398F8651_B9D0_470E_B1DE_0E66A563927C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tables.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ctables dialog

class Ctables : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	Ctables(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ctables)
	enum { IDD = IDD_tableDlg };
	CListCtrl	m_list;
	CString	m_name;
	CString	m_ID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ctables)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ctables)
	afx_msg void Onadd();
	afx_msg void Ondelete();
	afx_msg void Onflash();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLES_H__398F8651_B9D0_470E_B1DE_0E66A563927C__INCLUDED_)
