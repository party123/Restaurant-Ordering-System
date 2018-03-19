#if !defined(AFX_HISTORY_H__395D173B_9582_4387_B92C_636F467630DE__INCLUDED_)
#define AFX_HISTORY_H__395D173B_9582_4387_B92C_636F467630DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// history.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Chistory dialog

class Chistory : public CDialog
{
// Construction
public:
	Chistory(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Chistory)
	enum { IDD = IDD_chazhang };
	CString	m_orderid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Chistory)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Chistory)
	afx_msg void Onsearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORY_H__395D173B_9582_4387_B92C_636F467630DE__INCLUDED_)
