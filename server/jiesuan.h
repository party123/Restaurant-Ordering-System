#if !defined(AFX_JIESUAN_H__1508C381_DA7D_486C_9BE0_00F1454B606E__INCLUDED_)
#define AFX_JIESUAN_H__1508C381_DA7D_486C_9BE0_00F1454B606E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// jiesuan.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cjiesuan dialog

class Cjiesuan : public CDialog
{
// Construction
public:
	void flash();
	BOOL OnInitDialog();
	Cjiesuan(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cjiesuan)
	enum { IDD = IDD_jiesuanDlg };
	CComboBox	m_name;
	CString	m_price;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cjiesuan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cjiesuan)
	afx_msg void OnBtjiesuan();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIESUAN_H__1508C381_DA7D_486C_9BE0_00F1454B606E__INCLUDED_)
