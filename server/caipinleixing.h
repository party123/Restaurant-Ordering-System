//{{AFX_INCLUDES()

//}}AFX_INCLUDES
#if !defined(AFX_CAIPINLEIXING_H__DC6A2C2C_A1BB_4D17_8027_5D587E715C11__INCLUDED_)
#define AFX_CAIPINLEIXING_H__DC6A2C2C_A1BB_4D17_8027_5D587E715C11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// caipinleixing.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ccaipinleixing dialog

class Ccaipinleixing : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	//int n;//区别添加和修改的标识
	Ccaipinleixing(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ccaipinleixing)
	enum { IDD = IDD_caipinleixingDlg };
	CListCtrl	m_list;
	CButton	m_update;
	CButton	m_search;
	CButton	m_flash;
	CButton	m_delete;
	CButton	m_add;
	CString	m_keyword;
	CString	m_name;
	CString	m_ID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ccaipinleixing)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ccaipinleixing)
	afx_msg void Onadd();
	afx_msg void Ondelete();
	afx_msg void Onflash();
	afx_msg void Onsearch();
	afx_msg void Onupdate();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAIPINLEIXING_H__DC6A2C2C_A1BB_4D17_8027_5D587E715C11__INCLUDED_)
