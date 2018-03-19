// table.h : main header file for the TABLE application
//

#if !defined(AFX_TABLE_H__9003CAFF_4CD5_47A0_8F0C_B26CEB605687__INCLUDED_)
#define AFX_TABLE_H__9003CAFF_4CD5_47A0_8F0C_B26CEB605687__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTableApp:
// See table.cpp for the implementation of this class
//

class CTableApp : public CWinApp
{
public:
	CTableApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTableApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTableApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLE_H__9003CAFF_4CD5_47A0_8F0C_B26CEB605687__INCLUDED_)
