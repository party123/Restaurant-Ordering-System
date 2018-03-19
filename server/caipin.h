#if !defined(AFX_CAIPIN_H__DB8E6EDF_047E_4F6F_801A_2FD8763CD38E__INCLUDED_)
#define AFX_CAIPIN_H__DB8E6EDF_047E_4F6F_801A_2FD8763CD38E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// caipin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ccaipin dialog

class Ccaipin : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	Ccaipin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ccaipin)
	enum { IDD = IDD_caipin };
	CComboBox	m_type1;
	CListCtrl	m_list;
	CString	m_keyword;
	CString	m_name;
	CString	m_ID;
	CString	m_price;
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ccaipin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ccaipin)
	afx_msg void Onadd();
	afx_msg void Ondelete();
	afx_msg void Onflash();
	afx_msg void Onsearch();
	afx_msg void Onupdate();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAIPIN_H__DB8E6EDF_047E_4F6F_801A_2FD8763CD38E__INCLUDED_)
