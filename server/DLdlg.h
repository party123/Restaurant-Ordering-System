#if !defined(AFX_DLDLG_H__D58CE7C0_C39B_45F0_937D_99F87F02B741__INCLUDED_)
#define AFX_DLDLG_H__D58CE7C0_C39B_45F0_937D_99F87F02B741__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDLdlg dialog

class CDLdlg : public CDialog
{
// Construction
public:
	CDLdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLdlg)
	enum { IDD = IDD_DLdlg };
	CString	m_usr;
	CString	m_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLdlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLDLG_H__D58CE7C0_C39B_45F0_937D_99F87F02B741__INCLUDED_)
