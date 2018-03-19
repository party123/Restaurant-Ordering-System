// tableDlg.h : header file
//

#if !defined(AFX_TABLEDLG_H__239428AC_D366_45C3_85AB_DD74E19F8B47__INCLUDED_)
#define AFX_TABLEDLG_H__239428AC_D366_45C3_85AB_DD74E19F8B47__INCLUDED_

#include "TableSocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTableDlg dialog
  
class CTableDlg : public CDialog
{
// Construction
public:
	CTableSocket tablesock;
	CTableDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTableDlg)
	enum { IDD = IDD_TABLE_DIALOG };
	CButton	m_tijiao;
	CComboBox	m_type;
	CComboBox	m_zhuohao;
	CListCtrl	m_list2;
	CListCtrl	m_list1;
	CString	m_chename;
	CString	m_name;
	CString	m_price;
	CString	m_ID;
	CString	m_cheID;
	CString	m_cheprice;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTableDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onkaizhuo();
	afx_msg void Onbtdiancai();
	afx_msg void Ontijiao();
	afx_msg void Onchecai();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelendokCombo3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLEDLG_H__239428AC_D366_45C3_85AB_DD74E19F8B47__INCLUDED_)
